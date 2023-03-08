#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>


int main() {

	cv::Mat img = cv::imread("resources/kaanakgundogdu.jpg");

	cv::CascadeClassifier face_cascade;
	face_cascade.load("resources/haarcascade_frontalface_default.xml");
	
	if (face_cascade.empty())
	{
		std::cout << "Couldn't load cascade" << std::endl;
		return 1;
	}

	std::vector<cv::Rect>faces;
	face_cascade.detectMultiScale(img, faces, 1.1, 10);

	for (size_t i = 0; i < faces.size(); i++)
	{
		cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 0),2);
	}

	cv::imshow("me myself and i", img);

	cv::waitKey(0);
	return 0;
}