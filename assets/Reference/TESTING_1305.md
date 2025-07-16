# TASK CHỨC NĂNG QUẢN LÍ NHÂN SỰ
Tạo thư mục test
## A. Cách để tạo file test
- Bước 1: Tạo project mới, chọn **Native Unit Test Project** nếu chưa có project 
- Bước 2: Làm theo các bước như SLIDE OOP06 - C++ Unit test (Nếu chưa link)
- Bước 3: Tạo file theo yêu cầu task.
- Bước 4: Viết các mẫu test theo yêu cầu và test case.
- Bước 5: **Nhấn** build, không debugging gì hết, sau đó trên thanh tool có **Test** chọn ***Run All Test*** và chờ kết quả.
- Bước 6: Kiểm thử và ghi nhận lại kết quả báo cáo.
## B. KIỂM THỬ CHỨC NĂNG 1305
Lưu ý: Mọi lỗi nặng thì quăng exception hết nhé. Lưu ý đặt tên test theo đúng quy tắc trên slide OOP06 (sẽ được bổ sung code convention sau).
Công thức: <Method>_Should<expected>_When<Condition>
Ví dụ: 
FractionDenominator_ShouldNotBeZero_WhenCreateDefaultFraction
Balance_ShouldIncrease_WhenDepositPositiveValue
Balance_ShouldDecrease_WhenWithdrawaIsMade

### 1. Kiểm thử class Object
tên các test
- ObjectIdConstructor_ShouldThrowException_WhenIdIsEmpty: Khởi tạo đối tượng với id rỗng
- ObjectNameConstructor_ShouldThrowException_WhenNameIsEmpty: Khởi tạo name rỗng,
- ObjectId_ShouldThrowException_WhenSetIdEmpty: Không set null cho id và quăng exception.
- ObjectName_ShouldThrowException_WhenSetNameEmpty: Không set name null và quăng exception.
- ObjectId_ShoudeMatchAssignedValue_WhenSetId: Set được id.
- ObjectName_ShoudeMatchAssignedValue_WhenSetName: Set được name.

### 2. Kiểm thử class Person
tên các test
- PersonPhoneConstructor_ShouldThrowException_WhenPhoneIsEmpty.
- PersonPhoneConstructor_ShouldThrowException_WhenPhoneSizeNotEqualToTen: Độ dài số điện thoại bằng 10.
- PersonBirthdayConstructor_ShouldThrowException_WhenBirthdayIsEmpty.
- PersonAddressConstructor_ShouldThrowException_WhenAddressIsEmpty.
- PersonGenderConstructor_ShouldThrowException_WhenGenderIsEmpty.
- PersonPhone_ShouldThrowException_WhenSetPhoneEmpty.
- PersonBirthday_ShouldThrowException_WhenSetBirthdayEmpty.
- PersonBirthday_ShouldThrowException_WhenDateIsNotValid.
- PersonPhone_ShouldThrowException_WhenSetPhoneWithSizeNotEqualToTen.
- PersonAddress_ShouldThrowException_WhenSetAddressEmpty.
- PersonGender_ShouldThrowException_WhenSetGenderEmpty.
- PersonPhone_ShoudeMatchAssignedValue_WhenSetPhone.
- PersonAddress_ShoudeMatchAssignedValue_WhenSetAddress.
- PersonGender_ShoudeMatchAssignedValue_WhenSetGender.

### 3. Kiểm thử class Employee
- EmployeeEducation_ShouldThrowException_WhenEducationIsEmpty.
- EmployeeBaseSalary_ShouldThrowException_WhenSalaryIsEmpty.
- EmployeeBaseSalary_ShouldThrowException_WhenSalaryIsNegative.
- EmployeeEducation_ShouldThrowException_WhenSetEducationEmpty.
- EmployeeBaseSalary_ShouldThrowException_WhenSetSalaryEmpty.
- EmployeeBaseSalary_ShouldThrowException_WhenSetSalaryNegative.
- EmployeeEducation_ShoudeMatchAssignedValue_WhenSetEducation.
- EmployeeBaseSalary_ShoudeMatchAssignedValue_WhenSetSalary.
### 4. Kiểm thử class Doctor
- DoctorSpeciality_ShouldThrowException_WhenSpecialityIsEmpty.
- DoctorLicenses_ShouldThrowException_WhenLicensesIsEmpty.
- DoctorSpeciality_ShouldThrowException_WhenSetSpecialityEmpty.
- DoctorLicenses_ShouldThrowException_WhenSetLicensesEmpty.
- DoctorSpeciality_ShouldMatchAssignedValue_WhenSetSpeciality.

### 5. Kiểm thử class Nurse
NurseDuty_ShouldThrowException_WhenDutyIsEmpty.
NurseDuty_ShouldThrowException_WhenSetDutyEmpty.
NurseDuty_ShouldMatchAssignedValue_WhenSetDuty.

### 6. Kiểm thử class Receptionist
- ReceptionistSubsidies_ShouldThrowException_WhenSubsidiesIsEmpty.
- ReceptionistSubsidies_ShouldThrowException_WhenSubsidiesIsNegative.
- ReceptionistWorkingDays_ShouldThrowException_WhenWorkingDaysIsEmpty.
- ReceptionistWorkingDays_ShouldThrowException_WhenWorkingDaysIsNegative.
- ReceptionistSubsidies_ShouldThrowException_WhenSetSubsidiesEmpty.
- ReceptionistSubsidies_ShouldThrowException_WhenSetSubsidiesNegative.
- ReceptionistWorkingDays_ShouldThrowException_WhenSetWorkingDaysEmpty.
- ReceptionistWorkingDays_ShouldThrowException_WhenSetWorkingDaysNegative.
- ReceptionistSubsidies_ShouldMatchAssignedValue_WhenSetSubsidies.
- ReceptionistWorkingDays_ShouldMatchAssignedValue_WhenSetWorkingDays.