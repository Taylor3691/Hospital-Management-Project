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
    src/main.cpp
    src/controllers/DepartmentManager.cpp
    src/controllers/EmployeeManager.cpp
    src/controllers/PatientManager.cpp
    src/models/BillableComponent.cpp
    src/models/ClinicalTest.cpp
    src/models/CompletedState.cpp
    src/models/Department.cpp
    src/models/DepartmentTableModel.cpp
    src/models/Doctor.cpp
    src/models/Employee.cpp
    src/models/EmployeeTableModel.cpp
    src/models/ExaminingState.cpp
    src/models/HealthInsurance.cpp
    src/models/Hospital.cpp
    src/models/InsurancePayment.cpp
    src/models/MedicalRecord.cpp
    src/models/MedicalRecordListModel.cpp
    src/models/Medicine.cpp
    src/models/MedicineUsage.cpp
    src/models/NormalPayment.cpp
    src/models/Nurse.cpp
    src/models/Object.cpp
    src/models/Patient.cpp
    src/models/PatientTableModel.cpp
    src/models/PendingTestState.cpp
    src/models/Person.cpp
    src/models/Receipt.cpp
    src/models/Receptionist.cpp
    src/models/RegisteredState.cpp
    src/models/RoomExamination.cpp
    src/models/TestService.cpp
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
    src/views/MedicinePrecribingView.cpp
    src/views/ParaclinicalView.cpp
    src/views/PatientFilteringView.cpp
    src/views/PatientRecordView.cpp
    src/views/ReceiptView.cpp
    src/views/RegisterView.cpp
    src/views/RoomView.cpp
    src/views/DepartmentFilteringView.ui
    src/views/DepartmentRecordView.ui
    src/views/EmployeeFilteringView.ui
    src/views/EmployeeRecordView.ui
    src/views/HomeView.ui
    src/views/LoginView.ui
    src/views/ManagementView.ui
    src/views/MedicinePrecribingView.ui
    src/views/ParaclinicalView.ui
    src/views/PatientFilteringView.ui
    src/views/PatientRecordView.ui
    src/views/ReceiptView.ui
    src/views/RegisterView.ui
    src/views/RoomView.ui
    src/Registry.cpp
    src/App.h
    src/App.cpp
    src/Config.h" "src/Config.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}_autogen/include_$<CONFIG>")

target_link_libraries(${TARGET_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
