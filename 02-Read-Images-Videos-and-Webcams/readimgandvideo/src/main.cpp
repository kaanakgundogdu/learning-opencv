#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void video_capture() {
	cv::VideoCapture cap_video("resources/test_video.mp4");
	cv::Mat img;

	while (true)
	{
		cap_video.read(img);
		if (img.empty())
			break;
		cv::imshow("Test Video", img);
		cv::waitKey(1);
	}
}

void webcam() {
	cv::VideoCapture webcam_cap(0);
	cv::Mat img;

	while (true)
	{
		webcam_cap.read(img);
		cv::imshow("Webcam", img);
		cv::waitKey(1);
	}
}

int main() {

	//video_capture();
	webcam();
	return 0;
}