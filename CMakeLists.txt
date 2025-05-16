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
    src/models/Doctor.cpp
    src/models/Employee.cpp
    src/models/EmployeeManager.cpp
    src/models/EmployeeQuery.cpp
    src/models/EmployeeTableModel.cpp
    src/models/Nurse.cpp
    src/models/Object.cpp
    src/models/Person.cpp
    src/models/Receptionist.cpp
    src/models/TxtEmployeeRepository.cpp
    src/utils/Date.cpp
    src/utils/Time.cpp
    src/views/HomeView.cpp
    src/views/HomeView.ui
    src/views/LoginView.cpp
    src/views/LoginView.ui
    src/views/ManagementView.cpp
    src/views/ManagementView.ui
    packages/qdarkstyle/style.qrc
)

target_sources(${TARGET_NAME} PRIVATE
    src/interfaces/IEmployeeRepository.h
    src/interfaces/IManager.h
    src/interfaces/IQuery.h
    src/interfaces/IRepository.h
    src/models/Doctor.h
    src/models/Employee.h
    src/models/EmployeeManager.h
    src/models/EmployeeQuery.h
    src/models/EmployeeTableModel.h
    src/models/Nurse.h
    src/models/Object.h
    src/models/Person.h
    src/models/Receptionist.h
    src/models/TxtEmployeeRepository.h
    src/utils/Date.h
    src/utils/QueryBuilder.h
    src/utils/QueryTypes.h
    src/utils/QueryUtils.h
    src/utils/Time.h
    src/views/HomeView.h
    src/views/LoginView.h
    src/views/ManagementView.h
)

target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}_autogen/include_$<CONFIG>")

target_link_libraries(${TARGET_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
