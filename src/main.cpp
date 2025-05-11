#include <iostream>
#include "models/ServiceManager.h"
#include "utils/QueryBuilder.h"

void printService(const Service* service) {
    if (!service) {
        std::cout << "No service found\n";
        return;
    }
    std::cout << "Service: " << service->id() << " - " << service->name()
        << " (" << service->cost() << " d)\n";
}

int main() {
    // Setup test data
    auto d1 = std::make_unique<Department>("DP1", "Cardiology");
    auto d2 = std::make_unique<Department>("DP2", "Radiology");

    auto serviceManager = ServiceManager::getInstance();

    // Add test services
    serviceManager->addService(
        std::make_unique<Service>("SC1", "ECG", 50000.0, "Using", "", d1.get())
    );
    serviceManager->addService(
        std::make_unique<Service>("SC2", "X-Ray", 100000.0, "Using", "", d2.get())
    );
    serviceManager->addService(
        std::make_unique<Service>("SC3", "MRI", 150000.0, "Using", "", d2.get())
    );
    serviceManager->addService(
        std::make_unique<Service>("SC4", "Blood Test", 25000.0, "Using", "", d1.get())
    );

    // Create getters for nested queries
    auto departmentIdGetter = compose<Service>(
        makeGetter(&Service::department),
        makeGetter(&Department::id)
    );

    auto& services = serviceManager->services();

    // 1. Test find() - Find all services in Radiology (DP2)
    std::cout << "\n--- Testing find() ---\n";
    auto results = from(services)
        .where(departmentIdGetter, std::string("DP2"))
        .find();
    std::cout << "Found " << results.size() << " services in Radiology:\n";
    for (const auto* service : results) {
        printService(service);
    }

    // 2. Test findOne() - Find first service costing more than 120000
    std::cout << "\n--- Testing findOne() ---\n";
    auto expensiveService = from(services)
        .where(makeGetter(&Service::cost), 120000.0, ComparisonOperator::GT)
        .findOne();
    std::cout << "First expensive service found:\n";
    printService(expensiveService);

    // 3. Test deleteOne() - Delete the first service in Cardiology
    std::cout << "\n--- Testing deleteOne() ---\n";
    from(services)
        .where(departmentIdGetter, std::string("DP1"))
        .deleteOne();
    std::cout << "After deleting one Cardiology service, remaining services:\n";
    for (const auto& service : services) {
        printService(service.get());
    }

    // 4. Test deleteMany() - Delete all services costing less than 75000
    std::cout << "\n--- Testing deleteMany() ---\n";
    from(services)
        .where(makeGetter(&Service::cost), 75000.0, ComparisonOperator::LT)
        .deleteMany();
    std::cout << "After deleting cheap services, remaining services:\n";
    for (const auto& service : services) {
        printService(service.get());
    }

    return 0;
}
