//
// Created by Mauricio Kiniz on 13/03/26.
//

#ifndef PROJETO_API_PERSON_H
#define PROJETO_API_PERSON_H
#include <string>

namespace person {
    class Person {
        private:
            std::string name;
            std::string email;
            long id;
        public:
            Person(std::string name, std::string email);

    };
} // person

#endif //PROJETO_API_PERSON_H