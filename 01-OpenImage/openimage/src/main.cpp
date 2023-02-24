#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main() {

	cv::Mat img = cv::imread("resources/yamero.jpg");
	cv::imshow("Yamero", img);
	cv::waitKey(0);
	return 0;
}