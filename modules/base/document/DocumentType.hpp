//
// Created by Mauricio Kiniz on 13/03/26.
//

#ifndef PROJETO_API_DOCUMENTTYPE_HPP
#define PROJETO_API_DOCUMENTTYPE_HPP
#include <string>

struct DocumentType {
    enum class Value {
        Cpf,
        Cnpj
    };

    static std::string description(const Value type) {
        switch (type) {
            case Value::Cpf:
                return "CPF";
            case Value::Cnpj:
                return "CNPJ";
            default:
                return "unknown";
        }
    };
};

#endif //PROJETO_API_DOCUMENTTYPE_HPP