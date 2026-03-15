cmake_minimum_required(VERSION 4.1)
project(projeto_api)

set(CMAKE_CXX_STANDARD 20)

# Encontrar pacotes necessários
find_package(Drogon REQUIRED)

add_executable(projeto_api main.cpp
        modules/person/domain/BPerson.cpp
        modules/person/domain/BPerson.hpp
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
)

# Vincular bibliotecas
target_link_libraries(projeto_api PRIVATE Drogon::Drogon)
