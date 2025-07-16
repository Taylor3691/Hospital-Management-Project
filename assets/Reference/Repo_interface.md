# Xây dựng interface cho Repo toàn hệ thống

## 1. Class IRepository
Mô tả: Là một class interface, khai triển template cho đối tượng `class::Entity` (như Employee, Department, Medicine,...). Class này chủ yếu tương tác trực tiếp trên database và là cầu nối với class Manager. Class này yêu cầu các class thể hiện hiện đọc file và ghi đè file.
### a. Thuộc tính (Không có)
### b. Phương thức ảo
+ `load() = 0`: void
+ `save() = 0`: void
+ `add(Entity*)`: void
+ `removeById(const string& id)`: void
+ `update(const Enity& entity)`: void
## 2. Class IManager
Mô tả: là một class interface, khai triển template cho đối tượng `class::Entity` (như Employee, Department, Medicine,...). Class này nhằm tạo hợp đồng chung cho các lớp Manager chuyên cho các yêu cầu về quản lí danh sách các đối tượng. Sau đó các lớp Manager cụ thể sẽ triển khai và tự phát triển các hàm riêng dựa trên loại đối tượng cụ thể.
### a. Thuộc tính 
### b. Phương thức ảo
+ `removeById(const string& id) = 0`: void
+ `add(Entity*) = 0`: void
+ `findAll() = 0`: List<Entity*>

## 3. Class IQuery
Mô tả: là một class interface, sử dụng template chuyên cho việc tìm kiến các đối tượng `class::Entity` (như Employee, Department, Medicine,...) thoả một điều kiện cho trước được truyền vào trong các lớp Manager ở mục 2. Lớp hợp đồng này bắt các thể hiện phải thực hiện tìm hoặc trả về danh sách (tất cả, theo id). Còn tuỳ vào class thì Query có thể phức tạp hoặc không.
### a. Thuộc tính (Không có)
### b. Phương thức ảo
+ `findByid()`: Entity*
+ `findAll() = 0`: List<Entity*>




