#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
using namespace cv;
using namespace std;

/**
 * @brief 
 * 
 * @param image 
 * @param keypoints 
 * @param descriptors 
 */
void createSIFT(Mat image,vector<KeyPoint> &keypoints, Mat descriptors);
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
void matchSiftFeatures(Mat image1, Mat image2,
                        vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2,
                        Mat descriptors1, Mat descriptors2, vector<DMatch> &matches);

//TODO:
    //void detectHarrisCorners(Mat image, vector<Point2f> corners,double t);
