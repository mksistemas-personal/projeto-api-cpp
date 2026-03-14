//
// Created by Mauricio Kiniz on 14/03/26.
//

#ifndef PROJETO_API_CPFDOCUMENT_HPP
#define PROJETO_API_CPFDOCUMENT_HPP


#include "Document.hpp"
#include <string>
#include <utility>

namespace base::document {
    class CpfDocument : public Document {
    public:
        explicit CpfDocument(std::string identity)
            : Document(DocumentType::Value::Cpf, std::move(identity)) {
        }
    };
} // document
// base

#endif //PROJETO_API_CPFDOCUMENT_HPP
