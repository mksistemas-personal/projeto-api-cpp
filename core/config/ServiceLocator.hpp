#pragma once

#include <drogon/plugins/Plugin.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <typeindex>
#include <any>
#include <mutex>
#include <stdexcept>

namespace core::config {
    /**
 * @brief ServiceLocator plugin para Drogon.
 * Permite o registro e recuperação de serviços (objetos injetados) globalmente.
 */
    class ServiceLocator : public drogon::Plugin<ServiceLocator> {
    public:
        ServiceLocator() = default;

        /**
     * @brief Registra um serviço no locator.
     * 
     * @tparam T Tipo do serviço (interface ou classe base).
     * @param service Instância do serviço.
     */
        template<typename T>
        void registerService(std::shared_ptr<T> service) {
            std::lock_guard<std::mutex> lock(mutex_);
            services_[typeid(T)] = service;
        }

        /**
     * @brief Obtém um serviço previamente registrado.
     * 
     * @tparam T Tipo do serviço desejado.
     * @return std::shared_ptr<T> O serviço solicitado.
     * @throws std::runtime_error se o serviço não estiver registrado.
     */
        template<typename T>
        std::shared_ptr<T> getService() {
            std::lock_guard<std::mutex> lock(mutex_);
            auto it = services_.find(typeid(T));
            if (it == services_.end()) {
                throw std::runtime_error("Service not found: " + std::string(typeid(T).name()));
            }
            return std::any_cast<std::shared_ptr<T> >(it->second);
        }

        /**
     * @brief Métodos obrigatórios do Drogon Plugin.
     */
        void initAndStart(const Json::Value &config) override;

        void shutdown() override;

    private:
        std::unordered_map<std::type_index, std::any> services_;
        std::mutex mutex_;

        void registerPersonService();
    };
} // namespace core::config
