#include <QApplication>
#include "views/HomeView.h"
#include "models/TxtEmployeeRepository.h"
#include "ServiceLocator.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    TxtEmployeeRepository employeeRepo("../../../data/employees.txt");
    EmployeeManager employeeManager(&employeeRepo);
    ServiceLocator::provide(&employeeManager);

    HomeView w;
    w.show();
    
    return a.exec();
}
