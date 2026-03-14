//
// Created by Mauricio Kiniz on 14/03/26.
//

#ifndef PROJETO_API_ADDBUSINESSCASE_HPP
#define PROJETO_API_ADDBUSINESSCASE_HPP


namespace core::business {
    template<typename TRequest, typename TResponse>
    class AddBusinessCase {
    public:
        virtual ~AddBusinessCase() = default;

        AddBusinessCase() = default;

        virtual TResponse execute(const TRequest &request) = 0;
    };
} // business
// core

#endif //PROJETO_API_ADDBUSINESSCASE_HPP
