#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int hmin = 0, smin = 109, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
void create_track_window();

int main() {



	cv::Mat img = cv::imread("resources/vb1.jpg");
	cv::Mat img_hsv, mask;

	cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);

	create_track_window();

	while (true)
	{
		cv::Scalar lower(hmin, smin, vmin);
		cv::Scalar upper(hmax, smax, vmax);

		cv::inRange(img_hsv, lower, upper, mask);

		cv::imshow("Image", img);
		cv::imshow("HSV Image", img_hsv);
		cv::imshow("Mask", mask);

		cv::waitKey(1);
	}

	return 0;
}

void create_track_window() {
	cv::namedWindow("Trackbars", (320, 180));
	cv::createTrackbar("Hue min", "Trackbars", &hmin, 179);
	cv::createTrackbar("Hue max", "Trackbars", &hmax, 179);
	cv::createTrackbar("Sat min", "Trackbars", &smin, 255);
	cv::createTrackbar("Sat max", "Trackbars", &smax, 255);
	cv::createTrackbar("Val min", "Trackbars", &vmin, 255);
	cv::createTrackbar("Val max", "Trackbars", &vmax, 255);
}