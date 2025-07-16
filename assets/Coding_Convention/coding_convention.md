# CODE CONVENTION TRONG ĐỒ ÁN
## 1. Quy định về class
- **Tên lớp**: PascalCase (VD: `Patient`, `Doctor`).
- **Tên phương thức**: camelCase (VD: `bookAppointment`, `viewSchedule`).
- **Tên thuộc tính**: camelCase và bắt đầu bằng "_" (VD: `_patientId`, `_appointmentDate`).
- **Hằng số**: UPPER_CASE (VD: `MAX_BEDS`, `DEFAULT_STATUS`).
- Các thuộc tính liên quan đến con trỏ (biến con trỏ và vector chứa con trỏ), nếu class đó quản lý vòng đời của con trỏ thì dùng `std::unique_ptr`, ngược lại thì dùng con trỏ thường.
- Với tham số truyền vào phương thức là kiểu nguyên thủy (int, double,...) và con trỏ (kể cả `unique_ptr`) thì truyền tham trị, với các STL container phức tạp (vector, string) thì truyền tham chiếu hằng (const&), trừ `vector<unique_ptr>` thì bỏ const.
- Với kiểu trả về, dùng const cho con trỏ (với `unique_ptr` thì dùng `get()` để lấy raw pointer), dùng const& cho `vector`, các kiểu còn lại trả về bình thường.
- Khi truyền/trả/gán `std::unique_ptr`, phải dùng `std::move` vì đặc tính non-copyable. VD: `fn(std::move(ptr))`, `return std::move(ptr)`, `newPtr = std::move(ptr)`.
- Khi khai báo lớp phải theo thứ tự bên dưới:
```cpp
// ClassName.h
class ClassName {
private/protected:
    // Static attributes
    // Non-static attributes

private/protected/public:
    // Constructors
    // Destructors

public:
    // Getters
    // Setters

private/protected/public:
    // Static methods
    // Non-static methods

public:
    // Operators
};
```

**Theo Singleton Pattern**
```cpp
// Singleton.h
class Singleton {
private:
    Singleton() = default;
    ~Singleton() = default;

public:
    Singleton(const Singleton&) = delete;

public:
    static Singleton* getInstance();

public:
    Singleton& operator=(const Singleton&) = delete;
};

// Singleton.cpp
Singleton* Singleton::getInstance() {
    static std::unique_ptr<Singleton, void(*)(Singleton*)> instance(
        new Singleton(),
        [](Singleton* ptr) { delete ptr; });
    return instance.get();
}
```

## 2. Quy định cho các lớp kế thừa
- Thuộc tính thì xài **private** nhưng kế thừa nên thuộc tính của lớp cha hầu hết/ tất cả chuyển sang **protected**.
- Tất cả hàm nào mà được định nghĩa bởi lớp con thì thêm `virtual` trước tên hàm (Slide-OOP04-page21).
- Destructor của lớp cha **bắt buộc** có `virtual`.
- Việc quyết định một hàm ảo hay thuần ảo phải có sự thống nhất và có lí do hợp lí cho sự phát triển sau này.
- Cấm đa kế thừa vì dễ dẫn đến bài toán Diamond Problem.

## 3. Quy định về tổ chức hàm
- Dùng **//** để comment các ý ngắn gọn, rõ ý.
- Dùng **/\*...\*/** để comment mô tả hàm, class nếu cần.
- Viết hàm ngắn, rõ ràng (Khoảng 20-30 dòng), mỗi hàm nên chỉ làm một việc duy nhất.
- Dùng **{code}** cho tất cả các block lệnh, kể cả lệnh chỉ có một dòng.

## 4. Quy định chung
- Tạo một dòng trống giữa các khối lệnh cho dễ đọc.
- Không đặt tên biến quá ngắn hoặc ko có ý nghĩa.