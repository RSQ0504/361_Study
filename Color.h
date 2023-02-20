
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
/**
 * @brief 
 * 
 * @param src 
 * @return Mat 
 */
Mat image2hsv(Mat src);
/**
 * @brief 
 * 
 * @param src 
 * @return Mat 
 */
Mat image2double_3C(Mat src);
/**
 * @brief 
 * 
 * @param src 
 * @param color 
 * @return Mat 
 */
Mat showchannel_3C(Mat src,int color);
/**
 * @brief 
 * 
 * @param src 
 * @return Mat 
 */
Mat getalpha(Mat src);
/**
 * @brief 
 * Appy dilation erosion opening closing.
 */
void morphological();
/**
 * @brief 
 * Create FFT of image without shift (2 channel)
 * @param image 
 * @return Mat 
 */
Mat FFT(Mat image);
/**
 * @brief 
 * fftshift and show the frequency domain
 * @param result 
 * @param scale 
 */
void showFFT(const Mat& result,double scale);