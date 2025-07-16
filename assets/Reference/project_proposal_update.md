# BẢN DỰ TẢ ĐỒ ÁN LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG 2025 (SỬA ĐỔI 14.4.2025)
## A. MÔ TẢ ĐỀ TÀI
**Tên đề tài:** Hệ thống quản lí bệnh viện.
**Lí do chọn đề tài** 
Đây là hệ thống thực tế và cần thiết để quản lí tài nguyên của bệnh viện như sắp xếp giường trống cho bệnh nhân, ca làm việc, lịch phẫu thuật cho bác sĩ,... Hệ thống sẽ cung cấp giao diện thân thiện nhằm giúp quản lí tốt hơn.
 ## B. CÁC ĐỐI TƯỢNG DỰ KIẾN XUẤT HIỆN VÀ MỐI QUAN HỆ
### 1. Các lớp đối tượng  
 - **Bệnh nhân** (Patient): Người sử dụng dịch vụ bệnh viện.
 - **Bác sĩ** (Doctor): Người khám chữa bệnh chính.
 - **Y tá** (Nurse): Người hỗ trợ và chăm sóc bệnh nhân.
 - **Nhân viên** (Employee): Lớp cha trừu tượng chung cho bác sĩ, y tá và các nhân viên khác.
 - **Phòng** (Room): Nơi điều trị bệnh nhân.
 - **Giường** (Bed): Lưu giữ trạng thái (trống/không trống/sửa chữa) để theo dõi.
 - **Lịch hẹn** (Appointment): Quản các cuộc hẹn giữa bác sĩ và bệnh nhân.
 - **Hồ sơ bệnh án** (MedicalRecord): Lưu trữ thông tin y tế bệnh nhân.
 - **Khoa** (Department): Đại diện cho các đơn vị chuyên ngành như khoa hồi sức, khoa thần kinh,...
 - **Thuốc** (Medicine): Thuốc được kê hoặc sử dụng.
 - **Hoá đơn** (Bill): Quản lí chi phí bao gồm chi phí dịch vụ và chi phí thuộc kèm bảo hiểm nếu có.
### 2. Quan hệ giữa các lớp
- **Quan hệ chứa** (Composition): Đối tượng này chứa đối tượng kia.
  - `Department` chứa danh sách các `Room` và `Employee` mà nó quản lí.
  - `Room` chứa danh sách các `Bed`.
- **Quan hệ liên kết** (Association): Đối tượng này có mối quan hệ nhưng không sử hữu nhau.
  - `Appointment` liên kết `Patient` và `Doctor`.
  - `MedicalRecord` liên kết `Patient` và `Doctor`.
- **Quan hệ phụ thuộc** (Dependency): Đối tượng này phụ thuộc đối tượng khác
  - `Bill` phụ thuộc vào `Appointment` hoặc `MedicalRecord` để tính toán chi phí.

## C. THIẾT KẾ CÁC CHỨC NĂNG CHÍNH
- `Quản lý bệnh nhân`: Đăng ký, cập nhật thông tin, xem lịch hẹn, xem hồ sơ bệnh án.
- `Quản lý bác sĩ và nhân viên`: Xem lịch làm việc, xem lịch sử bệnh nhân, kê đơn thuốc.
- `Quản lý lịch hẹn`: Đặt lịch, hủy lịch, thay đổi lịch.
- `Quản lý hồ sơ bệnh án`: Tạo, cập nhật, xem hồ sơ.
- `Quản lý giường và phòng`: Theo dõi trạng thái giường (trống/đã chiếm), quản lý phòng.
- `Quản lý hóa đơn`: Tạo hóa đơn dựa trên dịch vụ đã sử dụng.
- `Giao diện`: Cung cấp giao diện tương tác với người dùng.
- `Phân quyền vào truy cập hệ thống`: Quản lí tài khoản, phân quyền khả năng truy cập cho các đối tượng như Admin, bác sĩ, bệnh nhân,...

## D. CÁC THUỘC TÍNH VÀ CÁC PHƯƠNG THỨC DỰ KIẾN CỦA CÁC ĐỐI TƯỢNG
### 1. Patient (Bệnh nhân)
- **Mô tả**: Người sử dụng dịch vụ của bệnh viện, bao gồm bệnh nhân nội trú và ngoại trú.

#### Thuộc tính
- `patientId`: String - Mã định danh duy nhất của bệnh nhân.
- `name`: String - Tên đầy đủ của bệnh nhân.
- `age`: int - Tuổi của bệnh nhân.
- `gender`: String - Giới tính (Nam/Nữ/Khác).
- `phone`: String - Số điện thoại liên lạc.
- `address`: String - Địa chỉ của bệnh nhân.
- `medicalHistory`: List<MedicalRecord> - Danh sách hồ sơ y tế của bệnh nhân.
- `appointments`: List<Appointment> - Danh sách lịch hẹn của bệnh nhân.

#### Phương thức
- `register(String id, String name, int age, String gender, String phone, String address)`: Đăng ký bệnh nhân mới.
- `updateInfo(String phone, String address)`: Cập nhật thông tin liên lạc.
- `viewAppointments()`: Lấy danh sách lịch hẹn của bệnh nhân.
- `viewMedicalRecords()`: Xem tất cả hồ sơ y tế.
- `getPatientDetails()`: Trả về thông tin chi tiết của bệnh nhân.

---

### 2. Employee (Nhân viên)
- **Mô tả**: Lớp cha chung cho các loại nhân viên trong bệnh viện như bác sĩ, y tá, nhân viên hành chính.

#### Thuộc tính
- `employeeId`: String - Mã định danh duy nhất của nhân viên.
- `name`: String - Tên đầy đủ của nhân viên.
- `department`: Department - Khoa/Phòng ban mà nhân viên trực thuộc.
- `startsWorkingAt`: Date - Ngày vào làm.
- `salary`: double - Lương cơ bản.

#### Phương thức
- `getEmployeeInfo()`: Lấy thông tin chi tiết của nhân viên.
- `updateDepartment(Department dept)`: Cập nhật khoa/phòng ban.
- `calculateSalary()`: Tính lương (phương thức trừu tượng, được ghi đè bởi lớp con).

---

### 3. Doctor (Bác sĩ)
- **Mô tả**: Nhân viên cung cấp dịch vụ y tế, kế thừa từ lớp `Employee`.

#### Thuộc tính
- Kế thừa tất cả thuộc tính từ `Employee`.
- `specialty`: String - Chuyên môn (ví dụ: Tim mạch, Nhi khoa).
- `schedule`: List<Schedule> - Lịch làm việc của bác sĩ.
- `patients`: List<Patient> - Danh sách bệnh nhân được bác sĩ phụ trách.

#### Phương thức
- Kế thừa phương thức từ `Employee`.
- `viewSchedule()`: Xem lịch làm việc của bác sĩ.
- `viewPatientHistory(Patient patient)`: Xem hồ sơ y tế của bệnh nhân.
- `prescribeMedicine(Patient patient, Medicine medicine)`: Kê đơn thuốc.
- `addAppointment(Appointment appointment)`: Thêm lịch hẹn với bệnh nhân.

---

### 4. Nurse (Y tá)
- **Mô tả**: Nhân viên hỗ trợ bác sĩ và chăm sóc bệnh nhân, kế thừa từ lớp `Employee`.

#### Thuộc tính
- Kế thừa tất cả thuộc tính từ `Employee`.
- `shift`: String - Ca làm việc (Sáng/Chiều/Tối).
- `assignedRooms`: List<Room> - Danh sách phòng được phân công chăm sóc.

#### Phương thức
- Kế thừa phương thức từ `Employee`.
- `checkPatientStatus(Patient patient)`: Kiểm tra tình trạng bệnh nhân.
- `updateRoomStatus(Room room)`: Cập nhật trạng thái phòng.

---

### 5. Room (Phòng)
- **Mô tả**: Nơi bệnh nhân được điều trị hoặc nghỉ ngơi.

#### Thuộc tính
- `roomId`: String - Mã định danh duy nhất của phòng.
- `department`: Department - Khoa/Phòng ban chứa phòng.
- `floor`: int - Tầng của phòng.
- `beds`: List<Bed> - Danh sách giường trong phòng.
- `status`: String - Trạng thái phòng (Hoạt động/Bảo trì).
- `rent`: double - Chi phí thuê phòng (nếu có).

#### Phương thức
- `addBed(Bed bed)`: Thêm giường vào phòng.
- `removeBed(Bed bed)`: Xóa giường khỏi phòng.
- `checkAvailability()`: Kiểm tra xem phòng có giường trống hay không.
- `getRoomDetails()`: Lấy thông tin chi tiết của phòng.

---

### 6. Bed (Giường)
- **Mô tả**: Tài nguyên trong phòng, được phân bổ cho bệnh nhân.

#### Thuộc tính
- `bedId`: String - Mã định danh duy nhất của giường.
- `room`: Room - Phòng chứa giường.
- `status`: String - Trạng thái giường (Available/Occupied/Maintenance).
- `patient`: Patient - Bệnh nhân đang sử dụng giường (nếu có).
- `type`: String - Loại giường (Thường/VIP/ICU).

#### Phương thức
- `checkAvailability()`: Kiểm tra giường có trống hay không.
- `assignBed(Patient patient)`: Phân bổ giường cho bệnh nhân.
- `releaseBed()`: Giải phóng giường khi bệnh nhân xuất viện.
- `getBedDetails()`: Lấy thông tin chi tiết của giường.

---

### 7. Appointment (Lịch hẹn)
- **Mô tả**: Quản lý các cuộc hẹn giữa bác sĩ và bệnh nhân.

#### Thuộc tính
- `appointmentId`: String - Mã định danh duy nhất của lịch hẹn.
- `patient`: Patient - Bệnh nhân tham gia lịch hẹn.
- `doctor`: Doctor - Bác sĩ phụ trách lịch hẹn.
- `date`: Date - Ngày hẹn.
- `time`: String - Giờ hẹn.
- `status`: String - Trạng thái (Đã đặt/Đã hủy/Hoàn thành).

#### Phương thức
- `bookAppointment(Patient patient, Doctor doctor, Date date, String time)`: Đặt lịch hẹn.
- `cancelAppointment()`: Hủy lịch hẹn.
- `reschedule(Date newDate, String newTime)`: Thay đổi thời gian hẹn.
- `getAppointmentDetails()`: Lấy thông tin chi tiết của lịch hẹn.

---

### 8. MedicalRecord (Hồ sơ bệnh án)
- **Mô tả**: Lưu trữ thông tin y tế của bệnh nhân.

#### Thuộc tính
- `recordId`: String - Mã định danh duy nhất của hồ sơ.
- `patient`: Patient - Bệnh nhân sở hữu hồ sơ.
- `doctor`: Doctor - Bác sĩ phụ trách hồ sơ.
- `diagnosis`: String - Chẩn đoán bệnh.
- `treatment`: String - Phương pháp điều trị.
- `date`: Date - Ngày tạo hồ sơ.
- `medicines`: List<Medicine> - Danh sách thuốc được kê.

#### Phương thức
- `createRecord(Patient patient, Doctor doctor, String diagnosis, String treatment)`: Tạo hồ sơ mới.
- `updateRecord(String diagnosis, String treatment)`: Cập nhật hồ sơ.
- `addMedicine(Medicine medicine)`: Thêm thuốc vào hồ sơ.
- `getRecordDetails()`: Lấy thông tin chi tiết của hồ sơ.

---

### 9. Department (Khoa)
- **Mô tả**: Đơn vị tổ chức chuyên môn trong bệnh viện (ví dụ: Khoa Tiêu hóa, Khoa Hồi sức).

#### Thuộc tính
- `departmentId`: String - Mã định danh duy nhất của khoa.
- `name`: String - Tên khoa (ví dụ: Khoa Nội, Khoa Nhi).
- `location`: String - Vị trí trong bệnh viện (ví dụ: Tòa A, tầng 3).
- `head`: Doctor - Trưởng khoa.
- `employees`: List<Employee> - Danh sách nhân viên trong khoa.
- `rooms`: List<Room> - Danh sách phòng thuộc khoa.

#### Phương thức
- `addEmployee(Employee employee)`: Thêm nhân viên vào khoa.
- `removeEmployee(Employee employee)`: Xóa nhân viên khỏi khoa.
- `addRoom(Room room)`: Thêm phòng vào khoa.
- `getPatientList()`: Lấy danh sách bệnh nhân trong khoa.
- `getDepartmentDetails()`: Lấy thông tin chi tiết của khoa.

---

### 10. Medicine (Thuốc)
- **Mô tả**: Tài nguyên được kê đơn hoặc sử dụng trong điều trị.

#### Thuộc tính
- `medicineId`: String - Mã định danh duy nhất của thuốc.
- `name`: String - Tên thuốc (ví dụ: Paracetamol).
- `type`: String - Loại thuốc (Viên/Uống/Tiêm).
- `quantity`: int - Số lượng tồn kho.
- `price`: double - Giá mỗi đơn vị thuốc.
- `expiryDate`: Date - Ngày hết hạn.

#### Phương thức
- `addStock(int quantity)`: Thêm số lượng thuốc vào kho.
- `useMedicine(int quantity)`: Sử dụng thuốc (giảm số lượng tồn kho).
- `checkAvailability()`: Kiểm tra số lượng thuốc còn trong kho.
- `getMedicineDetails()`: Lấy thông tin chi tiết của thuốc.

---

### 11. Bill (Hóa đơn)
- **Mô tả**: Quản lý chi phí dịch vụ mà bệnh nhân sử dụng.

#### Thuộc tính
- `billId`: String - Mã định danh duy nhất của hóa đơn.
- `patient`: Patient - Bệnh nhân nhận hóa đơn.
- `services`: List<Service> - Danh sách dịch vụ sử dụng (ví dụ: khám, xét nghiệm, thuốc).
- `totalAmount`: double - Tổng số tiền phải trả.
- `issueDate`: Date - Ngày phát hành hóa đơn.
- `status`: String - Trạng thái (Chưa thanh toán/Đã thanh toán).

#### Phương thức
- `createBill(Patient patient, List<Service> services)`: Tạo hóa đơn mới.
- `addService(Service service)`: Thêm dịch vụ vào hóa đơn.
- `calculateTotal()`: Tính tổng số tiền dựa trên các dịch vụ.
- `payBill()`: Đánh dấu hóa đơn là đã thanh toán.
- `getBillDetails()`: Lấy thông tin chi tiết của hóa đơn.

---

### 12. Service (Dịch vụ)
- **Mô tả**: Thông tin của một dịch vụ y tế được cung cấp trong bệnh viện.

#### Thuộc tính
- `serviceId`: String - Mã định danh duy nhất của dịch vụ.
- `name`: String - Tên dịch vụ (ví dụ: "Khám tổng quát", "Xét nghiệm máu", "Phẫu thuật nội soi").
- `cost`: double - Chi phí của dịch vụ.
- `description`: String - Mô tả chi tiết về dịch vụ (tùy chọn).
- `department`: Department - Khoa/Phòng ban cung cấp dịch vụ (ví dụ: Khoa Nội, Khoa Xét nghiệm).

#### Phương thức
- `getCost()`: Trả về chi phí của dịch vụ.
- `getServiceDetails()`: Lấy thông tin chi tiết của dịch vụ (mã, tên, chi phí, mô tả).
- `updateCost(double newCost)`: Cập nhật chi phí của dịch vụ.
- `setDepartment(Department dept)`: Gán dịch vụ cho một khoa cụ thể.

## E. ÁP DỤNG CÁC NGUYÊN TẮC OOP
- **Tính đóng gói** (Encapsulation): Bảo vệ dữ liệu bằng phương thức private (protected) và chỉ cho phép truy cập thông qua phương thức. Ví dụ muốn xem trong lớp `Patient`, thuộc tính `medicalHistory` chỉ có thể được truy cập qua `viewMedicalRecords()` hoặc cập nhật qua `updateMedicalRecords()`.
- **Tính kế thừa** (Inheritance): Sử dụng lớp cha để chia sẻ thuộc tính. Ví dụ như lớp `Employee` gồm 2 lớp con là `Doctor` và `Nurse` sử dụng chung các phương thức và thuộc tính của lớp cha.
- **Tính đa hình** (Polymorphism): Cho phép sử dụng một hàm nhưng có thể tính cho nhiều đối tượng khác nhau. Ví dụ như hàm `calculateSalary()` thì có thể xài cho đối tượng `Doctor` (Tính theo ca) và `Nurse`(Tính theo giờ).
- **Tính trừa tượng** (Abstraction): Ví dụ như lớp `Employee` có phương thức `calculateSalary()` được làm bởi cả `Doctor` và `Nurse` để tính lương.

## F. KIẾN TRÚC PHẦN MỀM VÀ DESIGN PATTERNS DỰ ĐỊNH SỬ DỤNG
- Kiến trúc phần mềm dự kiến: Kiến trúc Layered có sự kết hợp MVC.
- Các Design Patterns dự kiến: Singleton, Factory, Observer, Decorator, Facade, và Strategy.

## G. ĐẢM BẢO CHẤT LƯỢNG SẢN PHẨM
- Đúng yêu cầu đặt ra, thực hiện được các chức năng như quản lí bệnh nhân, quản lí bác sĩ,...
- Mã nguồn phải được thiết kế tuân theo nguyên tắc SOLID, sử dụng các Desgin Patterns và kiến trúc phần mềm sử dụng để tổ chức mã nguồn.
- Mã nguồn đẹp, dễ đọc, tuân thủ code convention.
- Kiểm thử toàn diện:
  - Sử dụng Unit Testing để kiểm tra từng lớp riêng lẻ hoặc phương thức riêng lẻ.
  - Kiểm tra sự tương tác giữa các lớp ví dụ như nếu khi thêm một dịch vụ vào thì tổng tiền hoá đơn sẽ tăng lên.
  - Kiểm tra toàn bộ hệ thống, đảm bảo người dùng tương tác với giao diện và thực hiện được các chức năng như đặt lịch, huỷ lịch,...
  - Kiểm tra các lỗi và khả năng xử lí lỗi của hệ thống khi mình nhập hoặc tương tác sai đầu vào.
- Sử dụng git, github để lưu trữ và quản lí mã nguồn.
- Tài liệu đầy đủ, kịch bản kiểm thử,...

## H. CODE CONVENTION
- **Tên lớp**: PascalCase (ví dụ: `Patient`, `Doctor`).
- **Tên phương thức**: camelCase (ví dụ: `bookAppointment`, `viewSchedule`).
- **Tên biến**: camelCase (ví dụ: `patientId`, `appointmentDate`).
- **Hằng số**: UPPER_CASE (ví dụ: `MAX_BEDS`, `DEFAULT_STATUS`).

## K. MÃ NGUỒN THAM KHẢO
- [Ý tưởng đề tài](https://www.codewithc.com/hospital-management-system-project-in-c/)
- [Mã nguồn đề tài trong link Drive](https://drive.google.com/file/d/18KACIw4eTdV9SsyWdBi-Wc4xZOtfssOu/view?usp=drive_link)

