#include "ServiceManager.h"

ServiceManager* ServiceManager::getInstance() {
    static std::unique_ptr<ServiceManager, void(*)(ServiceManager*)> instance(
        new ServiceManager(),
        [](ServiceManager* ptr) { /*std::cout << "Service Manager is destroying\n"; */delete ptr; });
    return instance.get();
}

std::vector<std::unique_ptr<Service>>& ServiceManager::services() {
    return _services;
}

void ServiceManager::addService(std::unique_ptr<Service> service) {
    _services.push_back(std::move(service));
}
