
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
/**
 * @brief 
 * 
 * @param original 
 * @return Mat 
 */
Mat image2hsv(Mat original);
/**
 * @brief 
 * 
 * @param original 
 * @return Mat 
 */
Mat image2double_3C(Mat original);
/**
 * @brief 
 * 
 * @param original 
 * @param color 
 * @return Mat 
 */
Mat showchannel_3C(Mat original,int color);
/**
 * @brief 
 * 
 * @param original 
 * @return Mat 
 */
Mat getalpha(Mat original);