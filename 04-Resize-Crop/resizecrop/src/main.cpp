#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main() {

	cv::Mat img = cv::imread("resources/yamero.jpg");
	cv::Mat img_resized, img_crop;

	//std::cout << img.size() << std::endl;// 224,225

	//cv::resize(img, img_resized, cv::Size(120,120)); // for specific size values
	cv::resize(img, img_resized, cv::Size(), 1.7, 1.7);

	cv::Rect roi(0, 0, 200,100);
	img_crop = img(roi);

	cv::imshow("Yamero", img);
	cv::imshow("Yamero Resized", img_resized);
	cv::imshow("Yamero Crop", img_crop);
	cv::waitKey(0);
	return 0;
}