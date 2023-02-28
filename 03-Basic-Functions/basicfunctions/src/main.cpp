#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main() {

	cv::Mat img = cv::imread("resources/yamero.jpg");
	cv::Mat img_gray, img_blur, img_canny, img_dilation, img_erode;

	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, img_blur, cv::Size(3, 3), 3, 0);
	cv::Canny(img_blur, img_canny, 50, 150);

	cv::Mat kernel_dil = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::Mat kernel_erode = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(img_canny, img_dilation, kernel_dil);
	cv::erode(img_dilation, img_erode, kernel_erode);

	cv::imshow("Yamero", img);
	cv::imshow("Yamero Gray", img_gray);
	cv::imshow("Yamero Blur", img_blur);
	cv::imshow("Yamero Canny", img_canny);
	cv::imshow("Yamero Dilation", img_dilation);
	cv::imshow("Yamero Erode", img_erode);

	cv::waitKey(0);
	return 0;
}