#include "PersonRepository.hpp"
#include <drogon/orm/CoroMapper.h>

namespace person::adapters {
    PersonRepository::PersonRepository(drogon::orm::DbClientPtr dbClient)
        : dbClient_(std::move(dbClient)) {
    }

    drogon::Task<void> PersonRepository::save(const domain::BPerson &person) {
        drogon::orm::CoroMapper<drogon_model::poctime::Person> mapper(dbClient_);
        auto data = person.getData();
        co_await mapper.insert(data);
    }

    drogon::Task<std::optional<domain::BPerson> > PersonRepository::findById(long long id) {
        drogon::orm::CoroMapper<drogon_model::poctime::Person> mapper(dbClient_);
        try {
            auto person = co_await mapper.findByPrimaryKey(id);
            co_return domain::BPerson(person);
        } catch (...) {
            co_return std::nullopt;
        }
    }

    drogon::Task<std::vector<domain::BPerson> > PersonRepository::findAll() {
        drogon::orm::CoroMapper<drogon_model::poctime::Person> mapper(dbClient_);
        auto persons = co_await mapper.findAll();
        std::vector<domain::BPerson> results;
        for (const auto &p: persons) {
            results.emplace_back(p);
        }
        co_return results;
    }

    drogon::Task<domain::PaginatedResult> PersonRepository::findPaginated(
        size_t page,
        size_t pageSize,
        const drogon::orm::Criteria &criteria
    ) {
        drogon::orm::CoroMapper<drogon_model::poctime::Person> mapper(dbClient_);

        size_t offset = (page > 0) ? (page - 1) * pageSize : 0;

        // Buscamos um item a mais para saber se existe uma próxima página
        auto persons = co_await mapper
                .limit(pageSize + 1)
                .offset(offset)
                .findBy(criteria);

        domain::PaginatedResult result;
        result.hasNext = persons.size() > pageSize;

        size_t count = 0;
        for (const auto &p: persons) {
            if (count < pageSize) {
                result.items.emplace_back(p);
            }
            count++;
        }

        co_return result;
    }
} // namespace person::adapters
