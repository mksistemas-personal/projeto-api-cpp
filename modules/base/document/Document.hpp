//
// Created by Mauricio Kiniz on 13/03/26.
//

#ifndef PROJETO_API_DOCUMENT_HPP
#define PROJETO_API_DOCUMENT_HPP
#include <utility>

#include "DocumentType.hpp"

namespace base::document {
    class Document {
    private:
        DocumentType::Value type;
        std::string identifier_;
        std::string complement_;

    public:
        Document(DocumentType::Value type, std::string identifier, std::string complement = "")
            : type(type),
              identifier_(std::move(identifier)),
              complement_(std::move(complement)) {
        }

        [[nodiscard]] DocumentType::Value getType() const {
            return type;
        }

        [[nodiscard]] const std::string &getIdentifier() const {
            return identifier_;
        }

        [[nodiscard]] const std::string &getComplement() const {
            return complement_;
        }
    };
};

#endif //PROJETO_API_DOCUMENT_HPP
