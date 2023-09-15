#include <opencv2/opencv.hpp>

int main()
{
  // Đọc hai hình ảnh cần chồng lên nhau
  cv::Mat image1 = cv::imread("scrambled1.png");
  cv::Mat image2 = cv::imread("scrambled2.png");

  // Kiểm tra xem việc đọc hình ảnh có thành công không
  if (image1.empty() || image2.empty())
  {
    std::cout << "Không thể đọc hình ảnh!" << std::endl;
    return -1;
  }

  // Chồng hình ảnh thứ hai lên hình ảnh thứ nhất (chồng cách trái trên)
  cv::Mat overlaidImage = image1.clone(); // Tạo một bản sao của hình ảnh thứ nhất
  int startX = 0;                         // Điểm bắt đầu cắt hình ảnh thứ hai
  int startY = 0;                         // Điểm bắt đầu cắt hình ảnh thứ hai

  // Đảm bảo hình ảnh thứ hai không vượt ra khỏi hình ảnh thứ nhất
  int endX = std::min(image1.cols, startX + image2.cols);
  int endY = std::min(image1.rows, startY + image2.rows);

  // Tính kích thước hình ảnh thứ hai dựa trên vùng được chồng
  int width = endX - startX;
  int height = endY - startY;

  // Cắt hình ảnh thứ hai để phù hợp với vùng chồng
  cv::Mat croppedImage2 = image2(cv::Rect(0, 0, width, height));

  // Chồng hình ảnh thứ hai lên hình ảnh thứ nhất
  cv::Mat roi = overlaidImage(cv::Rect(startX, startY, width, height));
  croppedImage2.copyTo(roi);

  // Hiển thị hình ảnh kết quả
  cv::imshow("Hình ảnh chồng lên nhau", overlaidImage);
  cv::waitKey(0); // Chờ người dùng đóng cửa sổ

  // Lưu hình ảnh kết quả
  cv::imwrite("overlaid_image.jpg", overlaidImage);

  return 0;
}
