#include "AddPersonService.hpp"

namespace person::domain {
    AddPersonService::AddPersonService(std::shared_ptr<IPersonRepository> repository)
        : repository_(std::move(repository)) {
    }

    drogon::Task<PersonResponse> AddPersonService::execute(const PersonRequest &request) {
        PersonResponse response;
        response.id = "generated-id-123";
        response.name = request.name;
        response.document = request.document;
        co_return response;
    }
}
