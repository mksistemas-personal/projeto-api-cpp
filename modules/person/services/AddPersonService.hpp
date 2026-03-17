#pragma once

#include "../../../core/business/AddBusinessCase.hpp"
#include "../domain/PersonDto.hpp"
#include "../domain/IPersonRepository.hpp"
#include <memory>

namespace person::domain {
    class AddPersonService : public core::business::AddBusinessCase<PersonRequest, PersonResponse> {
    public:
        explicit AddPersonService(std::shared_ptr<IPersonRepository> repository);

        drogon::Task<PersonResponse> execute(const PersonRequest &request) override;

    private:
        std::shared_ptr<IPersonRepository> repository_;

        void validate(const PersonRequest &request);
    };
}
