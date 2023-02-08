#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
using namespace cv;

/**
 * @brief 
 * 
 * @param image 
 * @param keypoints 
 * @param descriptors 
 */
void createSIFT(const Mat& image, std::vector<KeyPoint>& keypoints, Mat& descriptors);
/**
 * @brief 
 * 
 * @param image1 
 * @param image2 
 * @param keypoints1 
 * @param keypoints2 
 * @param descriptors1 
 * @param descriptors2 
 * @param matches 
 */
void matchSiftFeatures(const Mat& image1, const Mat& image2,
                        std::vector<KeyPoint>& keypoints1,std::vector<KeyPoint>& keypoints2,
                        Mat& descriptors1, Mat& descriptors2, std::vector<DMatch>& matches);
/**
 * @brief 
 * 
 * @param image 
 * @param corners 
 * @param t 
 */
void detectHarrisCorners(const Mat& image, std::vector<Point2f>& corners,double t);
