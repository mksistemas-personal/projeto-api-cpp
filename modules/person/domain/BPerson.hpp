//
// Created by Mauricio Kiniz on 13/03/26.
//

#ifndef PROJETO_API_PERSON_HPP
#define PROJETO_API_PERSON_HPP
#include <memory>
#include <string>
#include <utility>
#include <json/json.h>

#include "../../base/document/Document.hpp"
#include "../../base/document/CpfDocument.hpp"
#include "../../base/document/CnpjDocument.hpp"
#include "../../models/Person.h"


namespace person::domain {
    class BPerson {
    private:
        drogon_model::poctime::Person data_;

    public:
        BPerson() = default;

        explicit BPerson(drogon_model::poctime::Person data)
            : data_(std::move(data)) {
        }

        [[nodiscard]] const drogon_model::poctime::Person &getData() const {
            return data_;
        }

        [[nodiscard]] drogon_model::poctime::Person &getData() {
            return data_;
        }

        [[nodiscard]] std::unique_ptr<base::document::Document> getDocument() const;
 [[nodiscard]] Json::Value toJson() const;
    };
} // person

#endif //PROJETO_API_PERSON_HPP
