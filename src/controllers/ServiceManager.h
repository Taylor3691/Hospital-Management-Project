#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <vector>
#include <algorithm>
#include <iterator>
#include "../models/Service.h"

class ServiceManager {
private:
    inline static ServiceManager* _instance = nullptr;
    std::vector<Service*> _services;

private:
    ServiceManager() = default;
    ~ServiceManager() = default;

public:
    ServiceManager(const ServiceManager&) = delete;

public:
    static ServiceManager* getInstance();

public:
    void addService(Service* service);
    void removeServiceById(const std::string& id);
    void removeServiceByName(const std::string& name);
    std::vector<Service*> getAllServices();
    std::vector<Service*> getServicesByDepartmentId(const std::string& id);
    std::vector<Service*> getServicesByDepartmentName(const std::string& name);
    Service* getServiceById(const std::string& id);
    Service* getServiceByName(const std::string& name);

public:
    ServiceManager& operator=(const ServiceManager&) = delete;
};

#endif
