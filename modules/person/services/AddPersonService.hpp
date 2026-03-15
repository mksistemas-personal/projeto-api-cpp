//
// Created by Mauricio Kiniz on 14/03/26.
//

#ifndef PROJETO_API_ADDPERSONSERVICE_HPP
#define PROJETO_API_ADDPERSONSERVICE_HPP
#include "../../../core/business/AddBusinessCase.hpp"
#include "../domain/PersonDto.hpp"


namespace person::domain {
    class AddPersonService : public core::business::AddBusinessCase<PersonRequest, PersonResponse> {
    public:
        PersonResponse execute(const PersonRequest &request) override;
    };
}

#endif //PROJETO_API_ADDPERSONSERVICE_HPP
