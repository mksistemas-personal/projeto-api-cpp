#include <drogon/drogon.h>
#include <iostream>
#include "modules/models/Person.h"
#include "modules/person/domain/BPerson.hpp"

int main() {
    std::cout << "Iniciando servidor Drogon..." << std::endl;

    // Carregar configuração
    drogon::app().loadConfigFile("../config.json");

    // Adicionar um handler para testar CoroMapper (não bloqueante)
    drogon::app().registerHandler("/test_coro",
                                  [](drogon::HttpRequestPtr req,
                                     std::function<void(const drogon::HttpResponsePtr &)> callback) -> drogon::Task<> {
                                      auto dbClient = drogon::app().getDbClient();
                                      drogon::orm::CoroMapper<drogon_model::poctime::Person> mapper(dbClient);

                                      try {
                                          // Busca assíncrona usando co_await
                                          auto person = co_await mapper.findByPrimaryKey(802978046123027198);
                                          auto bperson = person::domain::BPerson(person);
                                          auto document = bperson.getDocument();
                                          auto res = drogon::HttpResponse::newHttpResponse();
                                          res->setBody("Pessoa encontrada (Coro): " + person.getValueOfName() +
                                                       " | Documento: " + person.getValueOfDocument());
                                          callback(res);
                                      } catch (const drogon::orm::DrogonDbException &e) {
                                          auto res = drogon::HttpResponse::newHttpResponse();
                                          res->setStatusCode(drogon::k404NotFound);
                                          res->setBody("Pessoa não encontrada ou erro no banco (Coro).");
                                          callback(res);
                                      }
                                      co_return;
                                  });

    // Iniciar o loop de eventos
    drogon::app().run();

    return 0;
}
