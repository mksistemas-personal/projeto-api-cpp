cmake_minimum_required(VERSION 4.1)
project(projeto_api)

set(CMAKE_CXX_STANDARD 20)

# Encontrar pacotes necessários
find_package(Drogon REQUIRED)

add_executable(projeto_api main.cpp
        modules/person/domain/Person.cpp
        modules/person/domain/Person.h)

# Vincular bibliotecas
target_link_libraries(projeto_api PRIVATE Drogon::Drogon)
