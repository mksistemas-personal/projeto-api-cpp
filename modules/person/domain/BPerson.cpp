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

    void to_json(nlohmann::json &j, const BPerson &p) {
        j = nlohmann::json{
            {"id", p.data_.getValueOfId()},
            {"name", p.data_.getValueOfName()}
        };

        auto doc = p.getDocument();
        if (doc) {
            j["document"] = {
                {"type", DocumentType::description(doc->getType())},
                {"value", doc->getIdentifier()}
            };
        } else {
            j["document"] = nullptr;
        }
    }
} // person
