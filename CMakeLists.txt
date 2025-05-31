cmake_minimum_required(VERSION 3.10.0)

project(HospitalManagementSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/packages/bulbqt-msvc-x64.5.15.2.10889/build/native")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

if(MSVC)
    add_compile_options(/utf-8)
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(TARGET_NAME HospitalManagementSystem)

add_executable(${TARGET_NAME}
    packages/qdarkstyle/style.qrc
    src/controllers/BillService.cpp
    src/controllers/DepartmentManager.cpp
    src/controllers/EmployeeManager.cpp
    src/controllers/ExaminationService.cpp
    src/controllers/MedicineManager.cpp
    src/controllers/PatientManager.cpp
    src/controllers/RegistrationService.cpp
    src/controllers/TestProcessingService.cpp
    src/models/BillableComponent.cpp
    src/models/BillableComponentTableModel.cpp
    src/models/ClinicalTest.cpp
    src/models/ClinicalTestTableModel.cpp
    src/models/CompletedState.cpp
    src/models/Department.cpp
    src/models/DepartmentTableModel.cpp
    src/models/Doctor.cpp
    src/models/Employee.cpp
    src/models/EmployeeTableModel.cpp
    src/models/ExaminingState.cpp
    src/models/HealthInsurance.cpp
    src/models/InsurancePayment.cpp
    src/models/MedicalRecord.cpp
    src/models/MedicalRecordListModel.cpp
    src/models/Medicine.cpp
    src/models/MedicineTableModel.cpp
    src/models/MedicineUsage.cpp
    src/models/MedicineUsageTableModel.cpp
    src/models/NormalPayment.cpp
    src/models/Nurse.cpp
    src/models/Object.cpp
    src/models/PaidState.cpp
    src/models/Patient.cpp
    src/models/PatientTableModel.cpp
    src/models/PaymentMethodStrategy.cpp
    src/models/TestPendingState.cpp
    src/models/Person.cpp
    src/models/Receipt.cpp
    src/models/Receptionist.cpp
    src/models/RoomExamination.cpp
    src/models/SelectableTableModel.cpp
    src/models/TableModel.cpp
    src/models/TestService.cpp
    src/models/TestServiceTableModel.cpp
    src/models/TxtClinicalTestParser.cpp
    src/models/TxtDepartmentParser.cpp
    src/models/TxtDepartmentRepository.cpp
    src/models/TxtDoctorParser.cpp
    src/models/TxtEmployeeRepository.cpp
    src/models/TxtMedicalRecordParser.cpp
    src/models/TxtMedicalRecordRepository.cpp
    src/models/TxtMedicineParser.cpp
    src/models/TxtMedicineRepository.cpp
    src/models/TxtMedicineUsageParser.cpp
    src/models/TxtNurseParser.cpp
    src/models/TxtParserFactory.cpp
    src/models/TxtPatientParser.cpp
    src/models/TxtPatientRepository.cpp
    src/models/TxtReceptionistParser.cpp
    src/models/TxtRoomExaminationParser.cpp
    src/models/TxtRoomExaminationRepository.cpp
    src/models/TxtTestServiceParser.cpp
    src/models/TxtTestServiceRepository.cpp
    src/models/TxtWritingVisitor.cpp
    src/models/WaitingState.cpp
    src/utils/Date.cpp
    src/utils/Time.cpp
    src/utils/utils.cpp
    src/views/DepartmentFilteringView.cpp
    src/views/DepartmentRecordView.cpp
    src/views/EmployeeFilteringView.cpp
    src/views/EmployeeRecordView.cpp
    src/views/HomeView.cpp
    src/views/LoginView.cpp
    src/views/ManagementView.cpp
    src/views/MedicineManagementView.cpp
    src/views/MedicinePrescribingView.cpp
    src/views/ParaclinicalView.cpp
    src/views/PatientFilteringView.cpp
    src/views/PatientRecordView.cpp
    src/views/ReceiptView.cpp
    src/views/RegisterView.cpp
    src/views/RoomView.cpp
    src/views/SelectingView.cpp
    src/views/DepartmentFilteringView.ui
    src/views/DepartmentRecordView.ui
    src/views/EmployeeFilteringView.ui
    src/views/EmployeeRecordView.ui
    src/views/HomeView.ui
    src/views/LoginView.ui
    src/views/ManagementView.ui
    src/views/MedicineManagementView.ui
    src/views/MedicinePrescribingView.ui
    src/views/ParaclinicalView.ui
    src/views/PatientFilteringView.ui
    src/views/PatientRecordView.ui
    src/views/ReceiptView.ui
    src/views/RegisterView.ui
    src/views/RoomView.ui
    src/views/SelectingView.ui
    src/main.cpp
    src/App.cpp
    src/Config.cpp
    src/ServiceLocator.cpp
)

target_sources(${TARGET_NAME} PRIVATE
    src/controllers/BillService.h
    src/controllers/DepartmentManager.h
    src/controllers/EmployeeManager.h
    src/controllers/ExaminationService.h
    src/controllers/MedicineManager.h
    src/controllers/PatientManager.h
    src/controllers/RegistrationService.h
    src/controllers/TestProcessingService.h
    src/interfaces/IDepartmentRepository.h
    src/interfaces/IEmployeeRepository.h
    src/interfaces/IManager.h
    src/interfaces/IMedicalRecordRepository.h
    src/interfaces/IMedicineRepository.h
    src/interfaces/IParser.h
    src/interfaces/IParserFactory.h
    src/interfaces/IPatientRepository.h
    src/interfaces/IPaymentMethod.h
    src/interfaces/IRepository.h
    src/interfaces/IRoomExaminationRepository.h
    src/interfaces/ITestServiceRepository.h
    src/interfaces/IVisitor.h
    src/interfaces/IWritingVisitor.h
    src/models/BillableComponent.h
    src/models/BillableComponentTableModel.h
    src/models/ClinicalTest.h
    src/models/ClinicalTestParser.h
    src/models/ClinicalTestTableModel.h
    src/models/CompletedState.h
    src/models/Department.h
    src/models/DepartmentParser.h
    src/models/DepartmentTableModel.h
    src/models/Doctor.h
    src/models/DoctorParser.h
    src/models/Employee.h
    src/models/EmployeeTableModel.h
    src/models/ExaminationState.h
    src/models/ExaminingState.h
    src/models/HealthInsurance.h
    src/models/InsurancePayment.h
    src/models/MedicalRecord.h
    src/models/MedicalRecordListModel.h
    src/models/MedicalRecordParser.h
    src/models/Medicine.h
    src/models/MedicineParser.h
    src/models/MedicineTableModel.h
    src/models/MedicineUsage.h
    src/models/MedicineUsageParser.h
    src/models/MedicineUsageTableModel.h
    src/models/NormalPayment.h
    src/models/Nurse.h
    src/models/NurseParser.h
    src/models/Object.h
    src/models/PaidState.h
    src/models/Patient.h
    src/models/PatientParser.h
    src/models/PatientTableModel.h
    src/models/PaymentMethodStrategy.h
    src/models/TestPendingState.h
    src/models/Person.h
    src/models/Receipt.h
    src/models/Receptionist.h
    src/models/ReceptionistParser.h
    src/models/RoomExamination.h
    src/models/RoomExaminationParser.h
    src/models/SelectableTableModel.h
    src/models/TableModel.h
    src/models/TestService.h
    src/models/TestServiceParser.h
    src/models/TestServiceTableModel.h
    src/models/TxtClinicalTestParser.h
    src/models/TxtDepartmentParser.h
    src/models/TxtDepartmentRepository.h
    src/models/TxtDoctorParser.h
    src/models/TxtEmployeeRepository.h
    src/models/TxtMedicalRecordParser.h
    src/models/TxtMedicalRecordRepository.h
    src/models/TxtMedicineParser.h
    src/models/TxtMedicineRepository.h
    src/models/TxtMedicineUsageParser.h
    src/models/TxtNurseParser.h
    src/models/TxtParserFactory.h
    src/models/TxtPatientParser.h
    src/models/TxtPatientRepository.h
    src/models/TxtReceptionistParser.h
    src/models/TxtRoomExaminationParser.h
    src/models/TxtRoomExaminationRepository.h
    src/models/TxtTestServiceParser.h
    src/models/TxtTestServiceRepository.h
    src/models/TxtWritingVisitor.h
    src/models/WaitingState.h
    src/utils/Date.h
    src/utils/QueryBuilder.h
    src/utils/QueryTypes.h
    src/utils/QueryUtils.h
    src/utils/Time.h
    src/utils/utils.h
    src/utils/utils_template.h
    src/views/DepartmentFilteringView.h
    src/views/DepartmentRecordView.h
    src/views/EmployeeFilteringView.h
    src/views/EmployeeRecordView.h
    src/views/HomeView.h
    src/views/LoginView.h
    src/views/ManagementView.h
    src/views/MedicineManagementView.h
    src/views/MedicinePrescribingView.h
    src/views/ParaclinicalView.h
    src/views/PatientFilteringView.h
    src/views/PatientRecordView.h
    src/views/ReceiptView.h
    src/views/RegisterView.h
    src/views/RoomView.h
    src/views/SelectingView.h
    src/App.h
    src/Config.h
    src/ServiceLocator.h
)

target_include_directories(${TARGET_NAME} PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}_autogen/include_$<CONFIG>")

target_link_libraries(${TARGET_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
