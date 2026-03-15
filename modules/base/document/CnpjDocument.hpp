//
// Created by Mauricio Kiniz on 14/03/26.
//

#ifndef PROJETO_API_CNPJDOCUMENT_HPP
#define PROJETO_API_CNPJDOCUMENT_HPP

#include "Document.hpp"
#include <string>
#include <utility>

namespace base::document {
    class CnpjDocument : public Document {
    public:
        explicit CnpjDocument(std::string identity, std::string complement = "")
            : Document(DocumentType::Value::Cnpj, std::move(identity), std::move(complement)) {
        }
    };
} // document
// base

#endif //PROJETO_API_CNPJDOCUMENT_HPP
