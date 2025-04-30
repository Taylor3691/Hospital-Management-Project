#include "ServiceManager.h"

ServiceManager* ServiceManager::getInstance() {
    if (_instance) {
        return _instance;
    }
    return _instance = new ServiceManager();
}

void ServiceManager::addService(Service* service) {
    _services.push_back(service);
}

void ServiceManager::removeServiceById(const std::string& id) {
    std::erase_if(_services, [id](Service* s) { return s->id() == id; });
}

void ServiceManager::removeServiceByName(const std::string& name) {
    std::erase_if(_services, [name](Service* s) { return s->name() == name; });
}

std::vector<Service*> ServiceManager::getAllServices() {
    return _services;
}

std::vector<Service*> ServiceManager::getServicesByDepartmentId(const std::string& id) {
    std::vector<Service*> filtered;

    std::copy_if(
        _services.begin(),
        _services.end(),
        std::back_inserter(_services),
        [&id](Service* s) { return s->department()->id() == id; });

    return filtered;
}

std::vector<Service*> ServiceManager::getServicesByDepartmentName(const std::string& name) {
    std::vector<Service*> filtered;

    std::copy_if(
        _services.begin(),
        _services.end(),
        std::back_inserter(_services),
        [&name](Service* s) { return s->department()->name() == name; });

    return filtered;
}

Service* ServiceManager::getServiceById(const std::string& id) {
    auto it = std::find_if(
        _services.begin(),
        _services.end(),
        [&id](Service* s) { return s->id() == id; });

    if (it != _services.end()) {
        return *it;
    }
    return nullptr;
}

Service* ServiceManager::getServiceByName(const std::string& name) {
    auto it = std::find_if(
        _services.begin(),
        _services.end(),
        [&name](Service* s) { return s->name() == name; });

    if (it != _services.end()) {
        return *it;
    }
    return nullptr;
}
