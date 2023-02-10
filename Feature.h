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
 */
void createSIFT(Mat image,vector<KeyPoint> &keypoints);

void createSIFT(Mat image,vector<KeyPoint> &keypoints,double threshold);
/**
 * @brief 
 * 
 * @param image1 
 * @param image2 
 * @param keypoints1 
 * @param keypoints2 
 * @param matches 
 */
void matchSiftFeatures(Mat image1, Mat image2,
                        vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2,
                        vector<DMatch> &matches);

void matchSiftFeatures(Mat image1, Mat image2,
                        vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2,
                        vector<DMatch> &matches,double threshold);

Mat HarrisCornerDetector(Mat image,Mat &out,int size, int threshold);