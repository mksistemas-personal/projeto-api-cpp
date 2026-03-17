#pragma once

#include <string>
#include <vector>
#include <exception>
#include <nlohmann/json.hpp>

namespace core::business {
    class BusinessException : public std::exception {
    public:
        explicit BusinessException(std::string message)
            : messages_({std::move(message)}) {
        }

        explicit BusinessException(std::vector<std::string> messages)
            : messages_(std::move(messages)) {
        }

        [[nodiscard]] const char *what() const noexcept override {
            if (messages_.empty()) {
                return "Business Exception";
            }
            return messages_[0].c_str();
        }

        [[nodiscard]] const std::vector<std::string> &getMessages() const {
            return messages_;
        }

        friend void to_json(nlohmann::json &j, const BusinessException &e) {
            j = nlohmann::json{{"errors", e.messages_}};
        }

    private:
        std::vector<std::string> messages_;
    };
} // namespace core::business