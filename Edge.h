#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

enum Color{
    Grey = 1,
    Other = 0,
};
/**
 * @brief 
 * 
 * @param src 
 * @param size size of kernel
 * @param sigma1 
 * @param sigma2 
 * @param CFormat Color Format of the final result
 * @return Mat 
 */
Mat DoG(Mat src, int size, double sigma1, double sigma2,int CFormat = Other);
/**
 * @brief 
 * 
 * @param src 
 * @param size size of kernel
 * @param sigma 
 * @param CFormat Color Format of the final result
 * @return Mat 
 */
Mat LoG(Mat src, int size, double sigma,int CFormat = Other);
/**
 * @brief 
 * 
 * @param src 
 * @param size size of kernel
 * @param sigma 
 * @param CFormat Color Format of the final result
 * @return Mat 
 */
Mat FindEdges(Mat src, int size, double sigma,int CFormat = Other);
/**
 * @brief 
 * 
 * @param src 
 * @param CFormat Color Format of the final result
 * @return Mat 
 */
Mat LaplacianKernel(Mat src,int CFormat = Other);