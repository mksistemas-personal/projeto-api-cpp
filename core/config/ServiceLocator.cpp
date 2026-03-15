#include "ServiceLocator.hpp"
#include <drogon/drogon.h>
#include "../../modules/person/adapters/PersonRepository.hpp"
#include "../../modules/person/services/AddPersonService.hpp"

namespace core::config {
    void ServiceLocator::initAndStart(const Json::Value &config) {
        LOG_INFO << "ServiceLocator plugin iniciado.";

        registerPersonService();

        LOG_INFO << "Servicos registrados no ServiceLocator.";
    }

    void ServiceLocator::shutdown() {
        LOG_INFO << "ServiceLocator plugin finalizado.";
    }

    // metodos privados

    void ServiceLocator::registerPersonService() {
        auto dbClient = drogon::app().getDbClient();
        auto personRepo = std::make_shared<person::adapters::PersonRepository>(dbClient);

        registerService<person::domain::IPersonRepository>(personRepo);
        registerService<person::domain::AddPersonService>(
            std::make_shared<person::domain::AddPersonService>(personRepo)
        );
    }
} // namespace core::config
