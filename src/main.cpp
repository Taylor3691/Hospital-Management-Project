//#include "App.h"
#include "models/TxtParserFactory.h"
#include "models/TxtMedicineRepository.h"
#include "models/TxtMedicalRecordRepository.h"
#include "ServiceLocator.h"
#include "controllers/ExaminationService.h"
int main(int argc, char* argv[]) {
    //App app(argc, argv);
    //return app.run();

    ServiceLocator* service = ServiceLocator::getInstance();
    IMedicineRepository* _medicines = service->medicineRepository();
    IMedicalRecordRepository* _records = service->medicalRecordRepository();
    IRoomExaminationRepository* _rooms = service->roomExaminationRepository();
    ITestServiceRepository* _tests = service->testServiceRepository();
    IEmployeeRepository* _employees = service->employeeRepository();
    IPatientRepository* _patients = service->patientRepository();
    ExaminationService* exam = new ExaminationService(_records, _medicines, _rooms, _tests, _employees, _patients);
    std::unique_ptr<MedicineUsage> usage = exam->createMedicineUsage("ME-001", "Paracetamol", 100, 100000.00, "Uống sau bữa");
    std::cout << usage.get()->id();
}
