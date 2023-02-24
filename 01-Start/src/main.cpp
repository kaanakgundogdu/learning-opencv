#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <fstream>



int main()
{
    std::string path = "Resources/yamero.jpg";
    cv::Mat img = cv::imread(path);
    cv::imshow("Imagesss", img);
    cv::waitKey(0);

    return 0;

}
