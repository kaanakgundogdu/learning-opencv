#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main() {

	cv::Mat img(512, 512, CV_8UC3, cv::Scalar(166, 166, 255));

	//cv::circle(img, cv::Point(256, 256), 128, cv::Scalar(243, 105, 133));//thinline
	//cv::circle(img, cv::Point(256, 256), 128, cv::Scalar(243, 105, 133),15);//thick
	
	cv::circle(img, cv::Point(256, 256), 128, cv::Scalar(243, 105, 133), cv::FILLED);
	cv::rectangle(img, cv::Point(256, 256), cv::Point(384, 384), cv::Scalar(255, 223, 131), cv::FILLED);
	cv::line(img, cv::Point(256, 256), cv::Point(170,350), cv::Scalar(0, 0, 0));
	cv::putText(img, "Kaan Akgundogdu", cv::Point(140, 230), cv::FONT_HERSHEY_DUPLEX, .8, cv::Scalar(35, 146, 243), 2);

	cv::imshow("Shapes and Text",img);


	cv::waitKey(0);

	return 0;
}