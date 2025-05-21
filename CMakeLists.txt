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
    src/controllers/EmployeeManager.cpp
    src/models/Department.cpp
    src/models/Doctor.cpp
    src/models/Employee.cpp
    src/models/EmployeeTableModel.cpp
    src/models/HealthInsurance.cpp
    src/models/Nurse.cpp
    src/models/Object.cpp
    src/models/Patient.cpp
    src/models/Person.cpp
    src/models/Receptionist.cpp
    src/models/TxtDepartmentParser.cpp
    src/models/TxtDoctorParser.cpp
    src/models/TxtEmployeeRepository.cpp
    src/models/TxtNurseParser.cpp
    src/models/TxtParserFactory.cpp
    src/models/TxtPatientParser.cpp
    src/models/TxtReceptionistParser.cpp
    src/models/TxtWritingVisitor.cpp
    src/utils/Date.cpp
    src/utils/Time.cpp
    src/views/EmployeeRecordView.cpp
    src/views/HomeView.cpp
    src/views/LoginView.cpp
    src/views/ManagementView.cpp
    src/views/EmployeeRecordView.ui
    src/views/HomeView.ui
    src/views/LoginView.ui
    src/views/ManagementView.ui
)

target_sources(${TARGET_NAME} PRIVATE
    src/ServiceLocator.h
    src/controllers/EmployeeManager.h
    src/interfaces/IDepartmentRepository.h
    src/interfaces/IEmployeeRepository.h
    src/interfaces/IManager.h
    src/interfaces/IParser.h
    src/interfaces/IParserFactory.h
    src/interfaces/IPatientRepository.h
    src/interfaces/IRepository.h
    src/interfaces/IVisitor.h
    src/interfaces/IWritingVisitor.h
    src/models/Department.h
    src/models/DepartmentParser.h
    src/models/Doctor.h
    src/models/DoctorParser.h
    src/models/Employee.h
    src/models/EmployeeTableModel.h
    src/models/HealthInsurance.h
    src/models/Nurse.h
    src/models/NurseParser.h
    src/models/Object.h
    src/models/Patient.h
    src/models/PatientParser.h
    src/models/Person.h
    src/models/Receptionist.h
    src/models/ReceptionistParser.h
    src/models/TxtDepartmentParser.h
    src/models/TxtDoctorParser.h
    src/models/TxtEmployeeRepository.h
    src/models/TxtNurseParser.h
    src/models/TxtParserFactory.h
    src/models/TxtPatientParser.h
    src/models/TxtReceptionistParser.h
    src/models/TxtWritingVisitor.h
    src/utils/Date.h
    src/utils/QueryBuilder.h
    src/utils/QueryTypes.h
    src/utils/QueryUtils.h
    src/utils/Time.h
    src/utils/utils_template.h
    src/views/EmployeeRecordView.h
    src/views/HomeView.h
    src/views/LoginView.h
    src/views/ManagementView.h
)

target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}_autogen/include_$<CONFIG>")

target_link_libraries(${TARGET_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
