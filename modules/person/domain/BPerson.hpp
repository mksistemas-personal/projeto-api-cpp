//
// Created by Mauricio Kiniz on 13/03/26.
//

#ifndef PROJETO_API_PERSON_HPP
#define PROJETO_API_PERSON_HPP
#include <string>

#include "../../models/Person.h"


namespace person::domain {
    class BPerson {
    private:
        drogon_model::poctime::Person data_;

    public:
        BPerson() = default;

        explicit BPerson(const drogon_model::poctime::Person &data)
            : data_(data) {
        }

        [[nodiscard]] const drogon_model::poctime::Person &getData() const {
            return data_;
        }
    };
} // person

#endif //PROJETO_API_PERSON_HPP
