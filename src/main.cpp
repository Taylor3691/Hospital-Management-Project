#include <QApplication>
#include "views/HomeView.h"
#include "models/TxtEmployeeRepository.h"
#include "models/TxtDepartmentRepository.h"
#include "models/TxtPatientRepository.h"
#include "ServiceLocator.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    TxtEmployeeRepository employeeRepo("../../../database/employees.txt");
    EmployeeManager employeeManager(&employeeRepo);

    TxtDepartmentRepository departmentRepo("../../../database/departments.txt");
    DepartmentManager departmentManager(&departmentRepo);

    TxtPatientRepository patientRepo("../../../database/patients.txt");
    PatientManager patientManager(&patientRepo);

    ServiceLocator::provide(&employeeManager, &departmentManager, &patientManager);

    HomeView w;
    w.show();
    
    return a.exec();
}
