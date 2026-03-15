//
// Created by Mauricio Kiniz on 14/03/26.
//

#ifndef PROJETO_API_PERSONDTO_HPP
#define PROJETO_API_PERSONDTO_HPP
#include <string>
#include "../../base/document/Document.hpp"

namespace person::domain {
    struct PersonRequest {
        std::string name;
        std::string document;
    };

    struct PersonResponse {
        std::string id;
        std::string name;
        std::string document;
    };
}

#endif //PROJETO_API_PERSONDTO_HPP
