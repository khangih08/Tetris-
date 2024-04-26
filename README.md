# Tetris-INT2215-UET
# Video Demo https://www.veed.io/view/051df899-f061-4384-80b7-daf79c1f4cf8?panel=share
# 1. Hướng dẫn cài đặt
- Chuyển repo này vào tài khoản riêng của bạn
- Sao chép repo đã chia nhỏ vào cục bộ của bạn thông qua lệnh: git clone https://github.com/khangih08/Tetris-Game
# 2. Mô tả chung
# Giới thiệu
Tetris hay Xếp Hình (1984), trò chơi có 7 loại Khối Hình (Tetromino) I (thẳng đứng), J, L, O (vuông), S, T, Z ứng với 7 màu khác nhau.
# Về Game 
- Cấu tạo: Mỗi Khối Hình được cấu tạo từ 4 khối gạch vuông (Block). Các Khối Hình có thể xoay được các góc 90, 180, 270 độ.
- Mục tiêu: Di chuyển các khối gạch đang rơi từ từ xuống trong kích thước hình chữ nhật 24 hàng x 10 cột (trên màn hình).
- Chỗ nào có gạch rồi thì không di chuyển được tới vị trí đó.
- Người chơi xếp những khối hình sao cho khối hình lấp đầy 1 hàng ngang để ghi điểm và hàng ngang ấy sẽ biến mất và người chơi sẽ ghi điểm.
- Người chơi thua cuộc khi Khối Hình tràn khỏi Board (Bảng).
# 3. Các chức năng
- Chơi từ level đầu tiên từ level 1 sau khi đạt được 1000 điểm sẽ qua level tiếp theo, điểm sẽ tự reset về 0
- Tạo các block với màu sắc ngẫu nhiên
- Xử lý các block khi va chạm với nhau, va chạm với tường và với đáy
- Di chuyển và xoay các block 90 độ, 180 độ, 270 độ
- Xóa hàng khi các block lấp đầy hàng ngang
- Tính score, line, level
- Game Over khi block không thể rơi xuống nữa
# 4. Các kĩ thuật lập trình được sử dụng:
- Kỹ thuật duyệt mảng, sinh khối và màu ngẫu nhiên
- Class, struct
- Con trỏ
- Đồ họa (Hình ảnh, text, sự kiện chuột và bàn phím)
- Tách file
- Cấu trúc rẽ nhánh,Vòng lặp
- Kỹ thuật giải phóng bộ nhớ động.
# 5. Kết luận:
- Hiểu được mô hình phát triển 1 dự án: Phân tích, thiết kế, lập trình, kiểm thử.
- Sử dụng thành thạo class, pointer, chia tách file,...
- Cách dùng github.
- Học được nhiều thuật toán mới. 
- Hình thành tư duy xử lý và giải quyết bài toán
## Khuyết điểm
- Code chưa được tối ưu hoàn toàn.
- Còn thiếu 1 số tính năng như sinh ra các khối tiếp theo, chưa có nhiều hiệu ứng bắt mắt,...
- Một số phần chia tách code chưa được hợp lý.
