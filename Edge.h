#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat DoG(Mat src, int size, double sigma1, double sigma2);

Mat LoG(Mat src, int size, double sigma);

Mat FindEdges(Mat src, int size, double sigma);

Mat LaplacianKernel(Mat src);