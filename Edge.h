#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

enum Color{
    Grey = 1,
    Other = 0,
};
/**
 * @brief 
 *  Differentiation of Gaussian (find edge)(G_1-G_2)
 * @param src 
 * @param size size of kernel
 * @param sigma1 
 * @param sigma2 
 * @param CFormat Color Format of the final result (can use default)
 * @return Mat 
 */
Mat DoG(Mat src, int size, double sigma1, double sigma2,int CFormat = Other);
/**
 * @brief 
 *  Laplacian of Gaussian (find edge)
 * @param src 
 * @param size size of kernel
 * @param sigma 
 * @param CFormat Color Format of the final result (can use default)
 * @return Mat 
 */
Mat LoG(Mat src, int size, double sigma,int CFormat = Other);
/**
 * @brief 
 *  using Sobel kernel to find edge (using Gaussian first to reduce noise)
 * @param src 
 * @param size size of kernel
 * @param sigma 
 * @param CFormat Color Format of the final result (can use default)
 * @return Mat 
 */
Mat FindEdges(Mat src, int size, double sigma,int CFormat = Other);
/**
 * @brief 
 * Using kernel which is simliar as Lapacian to find edge
 * @param src 
 * @param CFormat Color Format of the final result (can use default)
 * @return Mat 
 */
Mat LaplacianKernel(Mat src,int CFormat = Other);