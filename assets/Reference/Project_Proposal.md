# BẢN DỰ TẢ ĐỒ ÁN LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG 2025
## Mục lục

### A. Mô tả đề tài
-  **Tình huống:** Bạn là nhân viên được cắt cử để xây dựng hệ thống thông minh đèn giao thông cho một ngã tư nhất định, nhưng ngã tư này vô cùng phức tạp, rất hay xảy ra ùn tắc vào giờ cao điểm. Việc của bạn là thiết kế giảm thiểu khả năng ùn tắc, tính toán thời gian chờ đèn một cách linh hoạt vào các khung giờ cao điểm/không cao điểm để xây dựng một ngã tư lưu thông trật tự.
-  **Tên đề tài:** Hệ thống quản lí linh hoạt đèn giao thông tại một ngã tư.
- **Lí do chọn đề tài:** Đề tài này là một đề tài phản ảnh thực tế tình trạng giao thông của một số thành phố, đặc biệt là các thành phố lớn như thành phố Hồ Chí Minh. Ở trong đồ án này, chúng ta sẽ học cách xây dựng các lớp đối tượng như như lớp `trafficLight`, lớp `IntersectionController`,... Sử dụng thuật toán phù hơp để tính toán và đưa ra quyết định cho một số tình huống trong thực tế.
- **Độ khó:** Việc xây dựng một hệ thống như này là rất khó vì nó phụ thuộc rất nhiều vào thực tế. Do vậy trong đồ án này, chúng ta sẽ xây dựng dưới một ngữ cảnh cụ thể là một ngã tư, ngoài ra việc để chứng minh hệ thống chạy được đang còn là một thách thức.
### B. Kế hoạch dự kiến
**1. Giai đoạn đầu (6/4 - 12/4)**

- Chốt được đề tài, chọn được kiến trúc phần mềm, chọn được nơi quản lí mã nguồn.
- Xây được mã nguồn và xây dựng các lớp đối tượng để làm những chức năng cơ bản.
- Đề xuất những chức năng cải tiến.
- Chọn được template báo cáo, viết báo cáo phần giới thiệu.
- Báo cáo project proposal.

**2. Giai đoạn thi giữa kì (13/4 - 19/4)**

- Vừa ôn thi vừa làm.
- Chỉnh sửa đồ án, ổn định các chức năng cơ bản.
- Bắt đầu thêm cải tiến, mở rộng và phân chia các class kĩ hơn.
- Nghiên cứu các chủ đề nâng cao.
- Báo cáo tiếp tục viết những phần đã chốt.

**3. Giai đoạn xây dựng và ổn định (20/4 - 26/4)**

- Bổ sung và bắt đầu áp dụng theo nguyên tắc SOLID, các desgin pattern, nguyên lí dependency injection.
- Chạy thử và bắt đầu test những chức năng cơ bản.
- Bắt đầu viết hàm kiểm thử hệ thống bằng unit test (gtest).
- Đề xuất mẫu giao diện, cách bố trí, thư viện đồ hoạ.

**4. Giai đoạn chỉnh sửa và hoàn thiện chức năng cải tiến (27/4 - 3/5)**

- Clean code, tối ưu hàm để tối đa hiệu suất, review code tất cả và sửa những chỗ chưa theo code convention đã đặt ra.
- Tiếp tục phát triển chức năng, hoàn thiện các mục tiêu còn dở.
- Nghiên cứu và đề xuất chủ đề nâng cao.
- Báo cáo hoàn thiện theo tiến độ nhóm, bắt đầu có thể vẽ class diagram.

**5. Giai đoạn đào sâu và phát triển (4/5 - 13/5)**

- Bắt đầu thực hiện các chủ đề nâng cao.
- Báo cáo project 5/5.
- Hoàn thiện các chức năng đang có, bắt đầu chạy tổng thể một lần, kiểm thử các tình huống giả định.
- Tổ chức file tối ưu, clean code, chú thích mã nguồn nơi còn thiếu.
- Báo cáo viết về những phân tích lý thuyết về chủ đề nâng cao.
- Xây dựng UI.

**6. Giai đoạn hoàn thiện chủ đề nâng cao và bắt đầu xử lí rủi ro (14/5 - 23/5)**

- Cố gắng hoàn thiện chủ đề nâng cao.
- Bắt đầu chỉnh sửa, kiểm thử và chạy hệ thống.
- Hoàn chỉnh UI.
- Lên kịch bản video, viết scipt phụ đề (nếu cẩn).

**7. Giai đoạn cuối hoàn chỉnh bài nộp và video (24/5 - 31/5)**

- Quay, edit video demo và phân tích.
- Hoàn thành báo cáo, hoàn chỉnh về phần hoạt động nhóm, mục lục, tham khảo,...
- Hoàn thiện source code, tinh chỉnh, giải thích hàm,...
- Nộp bài.
### C. Tình hình hiện tại và mục tiêu hướng tới.

**1. Những thứ đã làm được**
- Họp được buổi đầu tiên (Google Meet), thống nhất về nơi quản lí mã nguồn (Github), IDE (Visual Studio), quản lí công việc (Trello), giao tiếp nhanh (Facebook).
- Đã dựng được mô hình giao thông ngã tư gồm 2 class cơ bản gồm các phương thức và thuộc tính tuân thủ nguyên tắc đóng gói. Xây dựng tình huống đơn giản nhất là ngã tư đủ 4 đèn, đèn chỉ có 3 màu, các xe là như nhau, không cảm biến, một bộ điều khiển trung tâm, một làn đường, đèn chuyển màu theo chu kì.
- Chọn được template báo cáo, báo cáo viết được giai đoạn đầu.
- Đề xuất được cấu trúc tổ chức file mã nguồn.
- Viết báo cáo tuần về những sự thay đổi và chỉnh sửa cho hệ thống và đề xuất chức năng mới.

**2. Thách thức và mục tiêu tiếp theo**
- Mục tiêu tiếp theo: Xây dựng thêm một class cảm biến để nhận diện số lượng xe ở mỗi hướng Đông, Tây, Nam, Bắc. Đồng thời thêm vào chức năng tính toán thời gian đèn xanh dựa vào thuật toán Fuzzy Logic hoặc Dynamic Priority.
- Thách thức và câu hỏi chưa giải quyết:
  - Chưa hình dung được sẽ demo chức năng như thế nào?
  - Liệu đồ án này có khả thi và được thầy cho phép làm hay không?
  - Nhóm vẫn chưa tìm được cách để build UI cho đề tài này.
  - Chưa khai thác được nhiều chức năng của chủ đề này.



