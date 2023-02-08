#include <opencv2/opencv.hpp>
#include <iostream>
#include"Edge.h"

using namespace std;

Mat DoG(Mat src, int size, double sigma1, double sigma2) {
    if (src.channels()!=1)
        cvtColor(src, src, COLOR_BGR2GRAY);
    Mat Gaussian1, Gaussian2;
    GaussianBlur(src, Gaussian1, Size(size, size), sigma1);
    GaussianBlur(src, Gaussian2, Size(size, size), sigma2);
    Mat result = Gaussian1 - Gaussian2;
    return result;
}

Mat LoG(Mat src, int size, double sigma) {
    if (src.channels()!=1)
        cvtColor(src, src, COLOR_BGR2GRAY);
    Mat Gaussian;
    GaussianBlur(src, Gaussian, Size(size, size), sigma);
    Mat result;
    Laplacian(Gaussian, result, CV_16S, size); // unsigned integers: negative values would be truncated and lost
    convertScaleAbs(result, result); // converting it to 8-bit unsigned integers 
    return result;
}

Mat FindEdges(Mat src, int size, double sigma) {
    if (src.channels()!=1)
        cvtColor(src, src, COLOR_BGR2GRAY);
    Mat Gaussian;
    GaussianBlur(src, Gaussian, Size(size, size), sigma);
    Mat ix, iy;
    Sobel(Gaussian, ix, CV_16S, 1, 0);
    Sobel(Gaussian, iy, CV_16S, 0, 1);
    Mat result;
    convertScaleAbs(ix, ix);
    convertScaleAbs(iy,iy);
    addWeighted(ix,0.5,iy,0.5,0,result);
    return result;
}

Mat LaplacianKernel(Mat src){
    Mat result;
    if (src.channels()!=1)
        cvtColor(src, src, COLOR_BGR2GRAY);
    float filter[3][3] = { { 0, -1, 0 },
                            { -1,  4, -1 },
                            { 0, -1, 0 } };
    Mat kernel = Mat(3, 3, CV_32F, filter);
    filter2D(src, result, -1, kernel);

    return result;
}
