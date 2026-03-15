//
// Created by Mauricio Kiniz on 14/03/26.
//

#include "AddPersonService.hpp"

namespace person::domain {
    PersonResponse AddPersonService::execute(const PersonRequest &request) {
        // Exemplo simples: mapeia request para response
        PersonResponse response;
        response.id = "generated-id-123";
        response.name = request.name;
        response.document = request.document;
        return response;
    }
}
