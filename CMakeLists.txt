cmake_minimum_required(VERSION 4.1)
project(projeto_api)

set(CMAKE_CXX_STANDARD 20)

# Encontrar pacotes necessários
find_package(Drogon REQUIRED)

add_executable(projeto_api main.cpp
        modules/person/domain/BPerson.cpp
        modules/person/domain/BPerson.hpp
        modules/base/document/Document.cpp
        modules/base/document/Document.hpp
        modules/base/document/DocumentType.hpp
        core/business/AddBusinessCase.hpp
        modules/person/domain/CreatePersonRequest.hpp
        modules/base/document/CpfDocument.cpp
        modules/base/document/CpfDocument.hpp
        modules/base/document/CnpjDocument.cpp
        modules/base/document/CnpjDocument.hpp
)

# Vincular bibliotecas
target_link_libraries(projeto_api PRIVATE Drogon::Drogon)
