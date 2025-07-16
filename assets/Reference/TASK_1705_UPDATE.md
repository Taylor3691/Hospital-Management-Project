# Cải tiến task 1705 
## Cải thiện chức năng ghi dữ liệu.

### 1. Class Object
#### a. Thuộc tính (Giữ nguyên)
#### b. Phương thức 
- Giữ nguyên cũ
- void acceptWrite(IVisitor* v, ostream& out) = 0 : virtual
- override tất cả các lớp Department, Patient, Doctor, Nurse, Receptionist. Trong tất cả những hàm override này  thì dynamic_cast<IWritingVisitor*> như thế này

```
    void acceptWrite(IVisitor* v, ostream& out){
        (dynamic_cast<IWritingVisitor*>(v))->write(*this);
    }
```

### 2. Class IVisitor
#### a. Thuộc tính (Không có)
#### b. Phương  thức (thuần ảo)
- ~IVisitor() = default: destructor.

### 3. Class IWritingVisitor :  public IVisitor
#### a. Thuộc tính (Không có)
#### b. Phương thức
- void write(Doctor*, ostream& out) = 0: virtual
- void write(Nurse*, ostream& out) = 0: virtual
- void write(Receptionist*, ostream& out) = 0: virtual
- void write(Department*, ostream& out) = 0: virtual

Yêu cầu: Làm thân hàm ghi riêng cho từng hàm cho dù có trùng một phần cách ghi.

### 4. Class TxtWritingVistor : public IVisitor
Mô tả: Ghi file txt tuỳ vào kiểu dữ liệu, có thể tận dụng các hàm cũ những vẫn phải đảm bảo các hàm mới, tuân theo thứ tự đã được cung cấp.
#### a. Thuộc tính (Không có)
#### b. Phương thức
- void write(Doctor*, ostream& out) : override
- void write(Nurse*, ostream& out) : override
- void write(Receptionist*, ostream& out) : override
- void write(Department*, ostream& out): override

Hàm main để test, trong class EmployeeRepo, hàm save sẽ như vầy
```
ofstream out(employees.txt, ios::out);
IVisitor* v = new TxtWritingVisitor() // chỗ này sau này cấu hình
for(Employee* e : _employees){
    e->acceptWrite(e, v); //ofstream là subclass của ostream
    e->acpeptWrite(e, cout); // để check kết quả
}

```



