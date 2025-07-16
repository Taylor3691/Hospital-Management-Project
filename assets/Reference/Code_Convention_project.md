# MỘT SỐ CODE CONVENTION TRONG ĐỒ ÁN (Update 3004)
## 1. Quy định về class
- Thuộc tính con trỏ phải dùng con trỏ thông minh.
- **Tên lớp**: PascalCase (ví dụ: `Patient`, `Doctor`).
- **Tên phương thức**: camelCase (ví dụ: `bookAppointment`, `viewSchedule`).
- **Tên thuộc tính**: camelCase và bắt đầu bằng "_" (ví dụ: `_patientId`, `_appointmentDate`).
- **Hằng số**: UPPER_CASE (ví dụ: `MAX_BEDS`, `DEFAULT_STATUS`).
- Đối với các thuộc tính là mảng, phải bắt đầu bằng chữ **"all"** hoặc chữ nào mô tả ý nghĩa là tất cả (ví dụ:`_allPatients, _allDoctors`,...).
- Hầu hết các lớp chỉ có **duy nhất** một instance thì phải thiết kế theo **Singleton Pattern** (sẽ có ngoại lệ).
- Khi khai báo .h và định nghĩa hàm trong .cpp phải theo thứ tự bên dưới (Trừ thiết kế Singleton Pattern).
- Tên đặt phải có nghĩa, tránh `a`, `temp`, `x1`,...
- Mỗi class đều phải có 2 file `file.cpp` và `file.h` tương ứng.
**Không theo thiết kế Singleton Pattern**
<pre>
// file .h
class {
private:
    // Thuộc tính thường 
    // Thuộc tính static

private:
    // Phương thức static
    // Phương thức của riêng của lớp

public:
    // Constructor
    // Destructor

public:
    // Getter
    // Setter

public:
    // Phương thức static
    // Phương thức của lớp

public
    // Operator
};
</pre>

**Theo Singleton Pattern**
<pre>
class {
private:
    // Thuộc tính thường 
    // Thuộc tính static

private:
    // Phương thức static
    // Phương thức của riêng của lớp
    // Constructor
    // Destructor

public:
    // Getter
    // Setter

public:
    // Phương thức static
    // Phương thức của lớp

public:
    // Operator
};
</pre>

## 2. Quy định cho các lớp kế thừa.
- Thuộc tính thì xài **private** nhưng kế thừa nên thuộc tính của lớp cha hầu hết/ tất cả chuyển sang **protected**.
- Tất cả hàm nào mà được định nghĩa bởi lớp con thì thêm `virtual` trước tên hàm (Slide-OOP04-page21).
- Destructor của lớp cha **bắt buộc** có `virtual`.
- Việc quyết định một hàm ảo hay thuần ảo phải có sự thống nhất và có lí do hợp lí cho sự phát triển sau này.
- Cực kì hạn chế (có thể sẽ cấm) đa kế thừa vì dễ dẫn đến bài toán Diamond Problem.

## 3. Quy định về tổ chức hàm
- Dùng **//** để comment các ý ngắn gọn, rõ ý.
- Dùng **/\*...\*/** để comment mô tả hàm, class nếu cần.
- Viết hàm ngắn, rõ ràng (Khoảng 20-30 dòng), mỗi hàm nên chỉ làm một việc duy nhất.
- Dùng **{code}** cho tất cả các block lệnh, kể cả lệnh chỉ có một dòng.