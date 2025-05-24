#include <QApplication>
#include "views/HomeView.h"
#include "models/TxtEmployeeRepository.h"
#include "models/TxtDepartmentRepository.h"
#include "models/TxtPatientRepository.h"
#include "ServiceLocator.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    TxtEmployeeRepository employeeRepo("../../../data/employees.txt");
    EmployeeManager employeeManager(&employeeRepo);

    TxtDepartmentRepository departmentRepo("../../../data/departments.txt");
    DepartmentManager departmentManager(&departmentRepo);

    TxtPatientRepository patientRepo("../../../data/patients.txt");
    PatientManager patientManager(&patientRepo);

    ServiceLocator::provide(&employeeManager, &departmentManager, &patientManager);

    HomeView w;
    w.show();
    
    return a.exec();
}
