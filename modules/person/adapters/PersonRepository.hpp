#pragma once

#include "../domain/IPersonRepository.hpp"
#include "../../models/Person.h"
#include <drogon/orm/DbClient.h>

namespace person::adapters {
    class PersonRepository : public domain::IPersonRepository {
    public:
        explicit PersonRepository(drogon::orm::DbClientPtr dbClient);

        drogon::Task<void> save(const domain::BPerson &person) override;

        drogon::Task<std::optional<domain::BPerson> > findById(long long id) override;

        drogon::Task<std::vector<domain::BPerson> > findAll() override;

    private:
        drogon::orm::DbClientPtr dbClient_;
    };
} // namespace person::adapters
