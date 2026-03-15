//
// Created by Mauricio Kiniz on 13/03/26.
//

#include "BPerson.hpp"
#include <json/json.h>

namespace person::domain {
    std::unique_ptr<base::document::Document> BPerson::getDocument() const {
        const std::string &docStr = data_.getValueOfDocument();
        if (docStr.empty()) {
            return nullptr;
        }

        Json::Value root;
        Json::Reader reader;
        if (!reader.parse(docStr, root)) {
            return nullptr;
        }

        std::string typeStr = root.get("type", "").asString();
        std::string identity = root.get("identifier", "").asString();

        if (typeStr == "cpf") {
            return std::make_unique<base::document::CpfDocument>(std::move(identity));
        } else if (typeStr == "cnpj") {
            return std::make_unique<base::document::CnpjDocument>(std::move(identity));
        }

        return nullptr;
    }
} // person
