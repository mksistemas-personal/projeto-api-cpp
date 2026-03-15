#ifndef PROJETO_API_SLICE_HPP
#define PROJETO_API_SLICE_HPP

#include <vector>
#include <memory>
#include <nlohmann/json.hpp>

namespace core::adapter {
    /**
     * @brief Classe que representa uma fatia de dados (Slice), inspirada no ISlice do Spring Data.
     * @tparam T Tipo dos elementos na fatia.
     */
    template<typename T>
    class Slice {
    public:
        Slice(std::vector<T> content, int number, int size, bool hasNext)
            : content_(std::move(content)),
              number_(number),
              size_(size),
              hasNext_(hasNext) {
        }

        /**
         * @return O conteúdo da fatia.
         */
        const std::vector<T> &getContent() const {
            return content_;
        }

        /**
         * @return O número da fatia atual (0-indexed).
         */
        int getNumber() const {
            return number_;
        }

        /**
         * @return O tamanho da fatia (limite solicitado).
         */
        int getSize() const {
            return size_;
        }

        /**
         * @return O número de elementos presentes nesta fatia.
         */
        int getNumberOfElements() const {
            return static_cast<int>(content_.size());
        }

        /**
         * @return Se a fatia possui conteúdo.
         */
        bool hasContent() const {
            return !content_.empty();
        }

        /**
         * @return Se existe uma próxima fatia.
         */
        bool hasNext() const {
            return hasNext_;
        }

        /**
         * @return Se existe uma fatia anterior.
         */
        bool hasPrevious() const {
            return number_ > 0;
        }

        /**
         * @return Se esta é a primeira fatia.
         */
        bool isFirst() const {
            return !hasPrevious();
        }

        /**
         * @return Se esta é a última fatia.
         */
        bool isLast() const {
            return !hasNext();
        }

        friend void to_json(nlohmann::json &j, const Slice<T> &s) {
            j = nlohmann::json{
                {"content", s.content_},
                {"number", s.number_},
                {"size", s.size_},
                {"numberOfElements", s.getNumberOfElements()},
                {"hasContent", s.hasContent()},
                {"hasNext", s.hasNext_},
                {"hasPrevious", s.hasPrevious()},
                {"isFirst", s.isFirst()},
                {"isLast", s.isLast()}
            };
        }

    private:
        std::vector<T> content_;
        int number_;
        int size_;
        bool hasNext_;
    };
} // namespace core::adapter

#endif //PROJETO_API_SLICE_HPP
