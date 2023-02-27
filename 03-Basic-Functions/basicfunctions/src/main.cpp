#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main() {

	cv::Mat img = cv::imread("resources/yamero.jpg");
	cv::Mat img_gray, img_blur, img_canny;

	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, img_blur, cv::Size(3, 3), 3, 0);
	cv::Canny(img_blur, img_canny, 50, 150);

	cv::imshow("Yamero", img);
	cv::imshow("Yamero Gray", img_gray);
	cv::imshow("Yamero Blur", img_blur);
	cv::imshow("Yamero Canny", img_canny);

	cv::waitKey(0);
	return 0;
}