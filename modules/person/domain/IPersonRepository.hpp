#pragma once

#include <vector>
#include <memory>
#include <optional>
#include <drogon/orm/DbClient.h>
#include <drogon/drogon.h>
#include "BPerson.hpp"

namespace person::domain {
    class IPersonRepository {
    public:
        virtual ~IPersonRepository() = default;

        virtual drogon::Task<void> save(const BPerson &person) = 0;

        virtual drogon::Task<std::optional<BPerson> > findById(long long id) = 0;

        virtual drogon::Task<std::vector<BPerson> > findAll() = 0;
    };
} // namespace person::domain
