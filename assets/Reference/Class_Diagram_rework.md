# A. Class Diagram

## 1. Clas Diagram cho chức năng quản lí nhân viên, bệnh nhân.

```mermaid
---
    config:
        class:
            hideEmptyMembersBox: true
---
classDiagram

namespace Organization {
    class Hospital
    class Department
    class Employee
    class Doctor
    class Nurse
    class Patient
    class Receptionist
    class Person
    class EmployeeManager
}
EmployeeManager *-- Employee: Composition
Hospital "1" -- "*" Person: Association
Hospital "1" o-- "1..*" Department: Composition
Department "1" o-- "1..*" EmployeeManager: Aggregation
Person <|-- Patient: Inheritance
Person <|-- Employee: Inheritance
Employee <|-- Doctor: Inheritance
Employee <|-- Nurse: Inheritance
Employee <|-- Receptionist: Inheritance

```
## 2. Class Diagram cho chức năng phân chia ca trực.

```mermaid
---
    config:
        class:
            hideEmptyMembersBox: true
---
classDiagram
namespace Assginment {
    class AssignmentManager
    class Hospital
    class Assignment
    class Doctor
    class Nurse
    class Room
    class Patient
    class Employee
    class Shift
    class Receptionist
}
    Hospital o-- AssignmentManager: Aggregation
    Employee <|-- Doctor: Inheritance
    Employee <|--  Nurse: Inheritance
    Employee <|--  Receptionist: Inheritance
    AssignmentManager *-- Assignment: Composition
    Assignment o-- Employee: Arregation
    Shift  --o Assignment: Arregation
    Doctor --> Patient : Treat
    Hospital *-- Room: 
    Room o-- Patient: Contain
    Room <-- Assignment: Responsible
```
## 3. Class Diagram cho chức năng chuẩn đoán và kê thuốc cho bệnh nhân.

```mermaid
---
    config:
        class:
            hideEmptyMembersBox: true
---
classDiagram
namespace Manager {
    class Doctor
    class Patient
    class MedicalRecord
    class Service
    class Examination
    class MedicineUsage
    class ServiceUsage
}
class Examination{
<<Event>>
}
Doctor --> Examination: Join
Patient --> Examination: Join
MedicalRecord <-- Examination: Diagnosis
MedicineUsage <-- Examination: Prescribe
MedicalRecord *-- MedicineUsage: Composition
Examination --> Service: Use
Service --> MedicineUsage: Prescribe
MedicalRecord o-- Patient: Arregation
MedicalRecord o-- Doctor: Arregation
Service --> ServiceUsage: Save
MedicalRecord o-- ServiceUsage: Composition
```
## 4. Class Diagram cho chức năng quản lí dịch vụ 
```mermaid
---
    config:
        class:
            hideEmptyMembersBox: true
---
classDiagram
namespace Manager {
    class Service
    class ServiceUsage
    class ServiceUsageManager
    class Patient
    class Room
    class Use
    class ServiceManager
}

class Use{
<<Event>>
}

Patient -- Use : Join
Service -- Use: Join
ServiceUsage <-- Use: Result
ServiceUsageManager *-- ServiceUsage: Composition 
ServiceManager *-- Service: Composition
Room o-- Service: Aggregation
```

## 5. Class Diagram chức năng thanh toán những thuốc và dịch vụ sử dụng.

```mermaid
---
    config:
        class:
            hideEmptyMembersBox: true
---
classDiagram
namespace Manager {
   class Bill
   class BillManager
   class MedicalRecord
   class Patient
}

Bill o-- Patient: Aggregation
BillManager *-- Bill: Composition
Bill o-- MedicalRecord: Aggeration
```
## 6. Class Diagram cho chức năng thống kê lương, tính lương
```mermaid
---
    config:
        class:
            hideEmptyMembersBox: true
---
classDiagram
namespace Manager {
   class SalaryManager
   class EmployeeManager
   class AssignmentManager
   class Employee
}

SalaryManager o-- EmployeeManager: Aggregation
SalaryManager o-- AssignmentManager: Aggregation
EmployeeManager *-- Employee: Composition
```

# B. Mô tả các bước chương trình hoạt động

## 1. Mô tả quá trình quản lí cơ sở dữ liệu (Nhân viên, khoa, ca trực,...)
- Bước 1: Khi chương trình khởi động, khởi tạo cơ sở dữ liệu (Đọc file/Sử dụng Hệ quản trị).
- Bước 2: Thực hiện các chức năng tương tác với Model (Thêm/Xoá/Sửa) trên chương trình.
- Bước 3: Lưu vào cơ sở dữ liệu (Hệ quản trị/ file).

## 2. Mô tả quá trình khám chữa bệnh.
- Bước 1: Bệnh nhân sẽ tạo sổ khám bệnh (`MedicalRecord`) và chờ được điều vào phòng cần thiết. Hồ sơ bao gồm thông tin cá nhân của bệnh nhân, triệu chứng, ngày đi khám,...
- Bước 2: Dựa vào triệu chứng, ta sẽ phân luồng vào phòng khám của khoa chuyên điều trị loại bệnh đó, nếu rõ triệu chứng hoặc chung chung thì mặc định vô phòng thuộc khoa "Noi Tong Quat".
- Bước 3: Kiểm tra phòng khám còn chỗ không. Nếu trống thì chuyển hồ sơ vào đó và bắt đầu khám. Nếu phòng quá tải thì phải đưa vào khu chờ đợi đến lượt.
- Bước 4: Khi được khám, gán bác đã khám cho bệnh nhân đó vào sổ khám. Sau đó bác sĩ sẽ thực hiện chuẩn đoán. Sau khi chuẩn đoán xong thì, bác sĩ sẽ cho thuốc. Nếu cảm thấy nghi ngờ, bác sĩ có thể chuyển qua sử dụng dịch vụ khác (Xét nghiệm máu, xét nghiệm nước tiểu,...) của phòng khác, quay lại bước 3. Các phòng đều thực hiện dịch vụ cũng như kê thuốc. Nếu như cảm thấy ổn, không cần chuyển nữa thì hoàn tất khám, bắt đầu xuất hoá đơn. Tất cả dịch vụ và thuốc được kê đều được tổng hợp vào hồ sơ. 
- Bước 5: Thanh toán hoá đơn qua hồ sơ, mỗi hoá đơn thanh toán cho một hồ sơ một lúc. Hoá đơn tính giá tiền từ thuốc và dịch vụ mà bệnh nhân đã sử dụng kết hợp bảo hiểm y tế.

## C. Luồng chương trình bằng hình vẽ.

## 1. Luồng hệ thống tổng quát
```mermaid
---
title: Menu
---
flowchart LR
 A@{ shape: circle, label: "Start" } -->
 E@{shape: lin-rect, label: "Logging"}-->
 B@{ shape: rect, label: "GUI" } -->
 C@{shape: diamond, label: "Choose another interface"}
 B --> D@{shape: diamond, label: "Interact with functions"} 
 F@{shape: lin-rect, label: "Change UI"}
F-->B
C --> F
H@{shape: lin-rect, label: "Do Something"}
D --> H
G@{shape: rect, label: "Creat Response"}
K@{shape: lin-rect, label: "Update"}
H --> G
G --> K
K --> B
L@{shape: circle, label: "End"}
B --> L
``` 

2. Luồng chức năng khám chữa bệnh
```mermaid
---
title: Menu
---
flowchart LR
A@{shape: circle, label: "Start"}
B@{shape: rect, label: "Create MeidcalRecord"}
B1@{shape: lin-rect, label: "Choose Serivce and Room suitably process"}
C@{shape: diamond, label: "Is full ?"}
D@{shape: lin-rect, label: "Waiting process"}
D1@{shape: lin-rect, label: "Move into room process"}
D2@{shape: rect, label: "Add Service"}
E@{shape: rect, label: "Doctor Examination"}
E1@{shape: rect, label: "Prescribe"}
G@{shape: diamond, label: "Have finish?"}
G2@{shape: lin-rect, label: "Move into another room process"}
F@{shape: rect, label: "Generate Bill"}
H@{shape: circle, label: "End"}

N@{shape: circle, label: "Yes"}
N1@{shape: circle, label: "Yes"}
M@{shape: circle, label: "No"}
M1@{shape: circle, label: "No"}

A --> B
B --> B1
B1 --> C
C --> N
N --> D
D --> C
C --> M
M --> D1
D1 --> D2
D2 --> E
E --> E1
E1 --> G
G --> N1
F --> H
G --> M1
M1 --> G2
G2 --> D2
N1 --> F

``` 