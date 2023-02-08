#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

enum Color{
    Grey = 1,
    Other = 0,
};

Mat DoG(Mat src, int size, double sigma1, double sigma2,int CFormat = Other);

Mat LoG(Mat src, int size, double sigma,int CFormat = Other);

Mat FindEdges(Mat src, int size, double sigma,int CFormat = Other);

Mat LaplacianKernel(Mat src,int CFormat = Other);