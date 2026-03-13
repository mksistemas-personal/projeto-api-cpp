#include <drogon/drogon.h>
#include <iostream>

int main() {
    std::cout << "Iniciando servidor Drogon..." << std::endl;

    // Carregar configuração
    drogon::app().loadConfigFile("../config.json");

    // Adicionar um handler simples para testar a conexão com o banco
    drogon::app().registerHandler("/test_db", [](const drogon::HttpRequestPtr& req,
                                                  std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
        auto dbClient = drogon::app().getDbClient();
        dbClient->execSqlAsync("SELECT version();", [callback](const drogon::orm::Result &result) {
            auto res = drogon::HttpResponse::newHttpResponse();
            if (result.size() > 0) {
                res->setBody("Conectado ao Postgres! Versão: " + result[0]["version"].as<std::string>());
            } else {
                res->setBody("Falha ao obter versão do Postgres.");
            }
            callback(res);
        }, [callback](const drogon::orm::DrogonDbException &e) {
            auto res = drogon::HttpResponse::newHttpResponse();
            res->setBody("Erro na conexão com o banco: " + std::string(e.base().what()));
            callback(res);
        });
    });

    // Iniciar o loop de eventos
    drogon::app().run();

    return 0;
}