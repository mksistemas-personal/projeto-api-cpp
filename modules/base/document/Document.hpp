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
        std::string identity;

    public:
        Document(DocumentType::Value type, std::string identity)
            : type(type),
              identity(std::move(identity)) {
        }

        [[nodiscard]] DocumentType::Value getType() const {
            return type;
        }

        [[nodiscard]] const std::string &getIdentity() const {
            return identity;
        }
    };
};

#endif //PROJETO_API_DOCUMENT_HPP
