import cv2

# Đọc hình ảnh cần chồng
top_image = cv2.imread('scrambled1.png')
bottom_image = cv2.imread('scrambled2.png')

# Kiểm tra xem hình ảnh đã được đọc thành công
if top_image is None or bottom_image is None:
    print('Không thể đọc hình ảnh.')
else:
    # Lấy kích thước của hình ảnh trên cùng
    height, width, _ = top_image.shape

    # Đảm bảo hình ảnh dưới cùng có kích thước tương tự
    bottom_image = cv2.resize(bottom_image, (width, height))

    # Chồng hai hình ảnh lại với nhau
    combined_image = cv2.addWeighted(top_image, 0.7, bottom_image, 0.3, 0)

    # Lưu hình ảnh kết quả
    cv2.imwrite('combined_image.jpg', combined_image)

    print('Đã chồng hai hình ảnh thành công.')
