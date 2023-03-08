#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

cv::Mat img, img_gray, img_blur, img_canny, img_dil, img_erode;

void setup_image();
void get_contours();


int main() {

	setup_image();
	get_contours();
	cv::imshow("shapes", img);
	cv::waitKey(0);
	return 0;
}

void setup_image() {
	img = cv::imread("resources/shapes.png");

	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img_gray, img_blur, cv::Size(3, 3), 3, 0);
	cv::Canny(img_blur, img_canny, 25, 75);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(img_canny, img_dil, kernel);
}

void get_contours()
{
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::findContours(img_dil, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	
	std::vector<std::vector<cv::Point>> con_poly(contours.size());
	std::vector<cv::Rect>bound_rect(contours.size());
	std::string object_name;

	for (size_t i = 0; i < contours.size(); i++)
	{
		int area = cv::contourArea(contours[i]);

		if (area > 1000)
		{
			float peri = cv::arcLength(contours[i], true);
			cv::approxPolyDP(contours[i], con_poly[i], 0.02 * peri, true);
			
			bound_rect[i] = cv::boundingRect(con_poly[i]);

			int obj_cor = (int)con_poly[i].size();
			
			if (obj_cor == 3)
				object_name = "Triangle";
			else if (obj_cor == 4) {
				float asp_ratio = (float)bound_rect[i].width / (float)bound_rect[i].height;
				if(asp_ratio>0.98 && asp_ratio < 1.02)
					object_name = "Square";
				else 
					object_name = "Rectangle";
			}
			else if (obj_cor > 4)
				object_name = "Circle";

			cv::drawContours(img, con_poly, i, cv::Scalar(255, 0, 20), 2.5);
			cv::rectangle(img, bound_rect[i].tl(), bound_rect[i].br(), cv::Scalar(0, 0, 255), 3);

			cv::putText(img, object_name, {bound_rect[i].x, bound_rect[i].y - 5}, cv::FONT_HERSHEY_PLAIN, 0.8, cv::Scalar(0, 0, 0), 1);

		}
	}

}