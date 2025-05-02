#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "../models/Service.h"

class ServiceManager {
private:
    std::vector<std::unique_ptr<Service>> _services;

private:
    ServiceManager() = default;
    ~ServiceManager() = default;

public:
    ServiceManager(const ServiceManager&) = delete;

public:
    static ServiceManager* getInstance();

public:
    std::vector<std::unique_ptr<Service>>& services();
    void addService(std::unique_ptr<Service> service);

public:
    ServiceManager& operator=(const ServiceManager&) = delete;
};

#endif
