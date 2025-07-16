# KIẾN TRÚC HỆ THỐNG ĐỒ ÁN OOP (update 6/4/2025)

## 1. Mô tả chủ đề

Bạn là nhân viên được cắt cử để xây dựng hệ thống thông minh đèn giao thông cho một ngã tư nhất định, nhưng ngã tư này vô cùng phức tạp, rất hay xảy ra ùn tắc vào giờ cao điểm. Việc của bạn là thiết kế sao cho giảm thiểu khả năng ùn tắc, tính toán thời gian chờ đèn một cách linh hoạt vào các khung giờ cao điểm/không cao điểm để xây dựng một ngã tư không còn/rất ít kẹt xe.

Ban đầu để cho dễ tiếp cận, chúng ta sẽ xây dựng ngã tư mà đèn giao thông thay đổi theo chu kì cố định, không quan tâm số lượng xe. Sau đó chúng ta sẽ phát triển hệ thống này để giải quyết vấn đề ban đầu ở các phiên bản sau. 


## 2. Các lớp đối tượng trong chủ đề (version 1.0)

Class `trafficLight` : Đây là class dùng để điều khiển một cột đèn tại một hướng duy nhất nào đó tại ngã tư.
- **Attributes** : Các thuộc tính cơ bản của lớp đối tượng này, bao gồm định nghĩa và kiểu dữ liệu
  - `_direction` - String: Dùng để chỉ hướng của đặt đèn (VD: Đèn đặt ở hướng "Bắc")
  - `_state` - String: Trạng thái hiện tại của đèn (VD: "Xanh", "Đỏ", "Vàng")
  - `_green_duration` - Int : Thời gian tồn tại của đèn xanh.
  - `_yellow_duration` - Int : Thời gian tồn tại của đèn vàng.
  - `_red_duration` - Int: Thời gian tồn tại của đèn đỏ.

 - **Method**: Các phương thức dùng để lấy dữ liệu, điều chỉnh trạng thái đèn và cập nhật thời gian chạy của đèn.
   - `trafficLight(direction, _green_duration = 30, _yellow_duration = 5, _red_duration = 30)` : Hàm khởi tạo mặc định một đèn giao thông bao gồm hướng và thời gian duy trì mỗi màu đèn 
   - `set_state(new_state)` : Hàm dùng để thay đổi trạng thái đèn thành một trong ba màu đỏ, vàng, xanh.
   -  `get_state()` : Trả về trạng thái hiện tại của đèn.
   -  `get_direction()` : Trả về hướng chính xác nơi đặt đèn.
   -  `~trafficLight()` : Hàm huỷ đối tượng.
   -  `operator<<()` : nạp chồng operator để in ra trạng thái đèn và hướng của nó.

Class `IntersectionController` là lớp đại diện quản lí toàn bộ đèn ở ngã tư và điều khiển theo chu kỳ hoạt động của chúng.
- **Attribute**: Các thuộc tính của lớp đối tượng, gồm bốn đèn giao thông ở 4 hướng và trạng thái ở chu kì hiện tại
  - `LightsArray` - Vector/Mảng động/Mảng tĩnh: Mảng dùng để chứa bốn đèn ở 4 hướng
  - `_current_cycle` - Int : Thuộc tính mô tả trạng thái hiện tại của một chu kì đèn (VD: nếu `_current_cycle = 1` thì Bắc-đỏ, Nam-đỏ, Đông-Xanh, Tây-Xanh hoặc `_current_cycle = 2` thì Bắc-đỏ, Nam-đỏ, Tây-vàng, Đông-vàng).
  - `_current_time` - static Int: Mô tả thời gian thực, tính bằng giây của bộ đếm.
- **Method**: Tập trung chủ yếu  tạo bốn đối tượng `trafficLight` rồi cho vào mảng. Sau đó điều khiển, chuyển trạng thái và cập nhật bộ đếm thời gian
  - `IntersectionController([light_bac,light_nam,light_dong, light_tay])` : Hàm khởi tạo mặc định bộ điều khiển với bốn đèn truyền vào, `_current_cycle = 0` ,  `_current_time = 1000`. Sửa đổi trạng thái đèn và duration các màu của đèn sao cho đúng với `_current_cycle` (Coi ở dưới).
  - `IntersectionController()`: Hàm khởi tạo mặc định không có đối truyền vào và tự khởi tạo 4 đối tượng cho mảng, `_current_cycle = 0` ,  `_current_time = 1000`. Sửa đổi trạng thái đèn và duration các màu của đèn sao cho đúng với `_current_cycle` (Coi ở dưới).
  - `~IntersectionController()` : Hàm huỷ đối tượng.
  - `update_lights()` : Cứ qua một đoạn thời gian thì cập nhật màu đèn cho tất cả (VD: Sau 30s, thì cập nhật `_current_cycle` và đổi màu theo đúng bảng đã quy định ở dưới).
  - `operator<<(object)`: Trả về trạng thái của tất cả đèn kèm hướng đi, bộ đếm thời gian.
  - `operator[](index)` : Trả về đèn được chỉ được chỉ định bằng index số.
  - `operator[](string)`: Trả về đèn được chỉ định bởi tên hướng (VD: LightArrays["Bắc"])
- **Bảng tham chiếu trạng thái đèn và thời gian các đèn tồn tại** của `_current_cycle`
  - Bảng trạng thái đèn ở bốn hướng.

|_current_cycle (Giai đoạn)| Đông | Tây | Nam| Bắc|
|--------------------------|------|-----|----|----|
|0|Xanh|Xanh|Đỏ|Đỏ|
|1|Vàng|Vàng|Đỏ|Đỏ|
|2|Đỏ|Đỏ|Xanh|Xanh|
|3|Đỏ|Đỏ|Vàng|Vàng|

  - Thời gian tồn tại mỗi đèn: **Xanh** = 30 (giây), **Vàng** = 5 (giây), **Đỏ** = 35(giây)






