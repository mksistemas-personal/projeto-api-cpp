cmake_minimum_required(VERSION 4.1)
project(projeto_api)

set(CMAKE_CXX_STANDARD 20)

# Encontrar pacotes necessários
find_package(Drogon REQUIRED)

include(FetchContent)
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_executable(projeto_api main.cpp
        modules/person/domain/BPerson.cpp
        modules/person/domain/BPerson.hpp
        modules/person/domain/IPersonRepository.hpp
        modules/person/adapters/PersonRepository.cpp
        modules/person/adapters/PersonRepository.hpp
        modules/base/document/Document.hpp
        modules/base/document/DocumentType.hpp
        core/business/AddBusinessCase.hpp
        modules/base/document/CpfDocument.cpp
        modules/base/document/CpfDocument.hpp
        modules/base/document/CnpjDocument.cpp
        modules/base/document/CnpjDocument.hpp
        modules/models/Category.cc
        modules/models/Category.h
        modules/models/Client.cc
        modules/models/Client.h
        modules/models/Economicgroup.cc
        modules/models/Economicgroup.h
        modules/models/Organization.cc
        modules/models/Organization.h
        modules/models/Person.cc
        modules/models/Person.h
        modules/models/Product.cc
        modules/models/Product.h
        modules/person/domain/PersonDto.hpp
        modules/person/services/AddPersonService.cpp
        modules/person/services/AddPersonService.hpp
        core/config/ServiceLocator.cpp
        core/config/ServiceLocator.hpp
        core/adapter/Slice.hpp
)

# Vincular bibliotecas
target_link_libraries(projeto_api PRIVATE Drogon::Drogon nlohmann_json::nlohmann_json)
