#include <drogon/drogon.h>
#include <iostream>
#include <nlohmann/json.hpp>


#include "core/adapter/Slice.hpp"
#include "modules/models/Person.h"
#include "modules/person/domain/BPerson.hpp"
#include "core/config/ServiceLocator.hpp"
#include "modules/person/domain/IPersonRepository.hpp"


int main() {
    std::cout << "Iniciando servidor Drogon..." << std::endl;

    // Carregar configuração
    drogon::app().loadConfigFile("../config.json");

    // Adicionar um handler para testar CoroMapper (não bloqueante)
    drogon::app().registerHandler("/test_coro",
                                  [](drogon::HttpRequestPtr req,
                                     std::function<void(const drogon::HttpResponsePtr &)> callback) -> drogon::Task<> {
                                      try {
                                          auto locator = drogon::app().getPlugin<core::config::ServiceLocator>();
                                          auto repo = locator->getService<person::domain::IPersonRepository>();

                                          // Busca assíncrona de todas as pessoas usando o repositório
                                          auto persons = co_await repo->findAll();

                                          // Exemplo de uso do Slice (assumindo que buscamos tudo em uma única fatia)
                                          core::adapter::Slice<person::domain::BPerson> slice(
                                              persons, 0, (int) persons.size(), false);


                                          nlohmann::json nj = slice;
                                          auto res = drogon::HttpResponse::newHttpResponse();
                                          res->setStatusCode(drogon::k200OK);
                                          res->setContentTypeCode(drogon::CT_APPLICATION_JSON);
                                          res->setBody(nj.dump());
                                          callback(res);
                                      } catch (const std::exception &e) {
                                          auto res = drogon::HttpResponse::newHttpResponse();
                                          res->setStatusCode(drogon::k500InternalServerError);
                                          res->setBody("Erro ao buscar pessoas: " + std::string(e.what()));
                                          callback(res);
                                      }
                                      co_return;
                                  });

    // Iniciar o loop de eventos
    drogon::app().run();

    return 0;
}
