#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

const int w = 200, h = 250;
cv::Mat matrix, img_warp;

int main() {
	const int p_count = 4;

	cv::Mat img = cv::imread("resources/kj1.png");

	cv::Point2f src_p[p_count] = { {967,725},{1019,736}, {918,770}, {969,784} };
	cv::Point2f dest_p[p_count] = { {0.0f,0.0f},{w,0.0f}, {0.0f,h}, {w,h} };

	matrix = cv::getPerspectiveTransform(src_p, dest_p);
	cv::warpPerspective(img, img_warp, matrix, cv::Point(w, h));

	for (size_t i = 0; i < p_count; i++)
	{
		cv::circle(img, src_p[i], 1, cv::Scalar(0, 0, 255), 2);
	}

	cv::imshow("Sanji normal", img);
	cv::imshow("Sanji Warped", img_warp);


	cv::waitKey(0);
	return 0;
}