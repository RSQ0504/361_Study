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
/**
 * @brief 
 * 
 * @param image 
 * @param keypoints 
 * @param threshold value of thrshold which is used to delete the weak feature.
 */
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
/**
 * @brief 
 * 
 * @param image1 
 * @param image2 
 * @param keypoints1 
 * @param keypoints2 
 * @param matches 
 * @param threshold value of thrshold which is used to delete the weak feature.
 */
void matchSiftFeatures(Mat image1, Mat image2,
                        vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2,
                        vector<DMatch> &matches,double threshold);
/**
 * @brief 
 * 
 * @param image 
 * @param out 
 * @param size neighbourhood size
 * @param threshold 
 * @return Mat 
 */
vector<KeyPoint> HarrisCornerDetector(Mat image,Mat &out,int size, float t);
/**
 * @brief 
 * 
 * @param image 
 * @param out 
 * @param threshold 
 * @return vector<KeyPoint> 
 */
vector<KeyPoint> FASTCorner(Mat image,Mat &out, int threshold);
/**
 * @brief 
 * 
 * @param image1 
 * @param image2 
 * @param out 
 * @param keypoints1 
 * @param keypoints2 
 * @return vector<DMatch> 
 */
vector<DMatch> MatchUsingSIFT(Mat image1, Mat image2,Mat &out, vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2);
/**
 * @brief 
 * 
 * @param image1 
 * @param image2 
 * @param out 
 * @param keypoints1 
 * @param keypoints2 
 * @return vector<DMatch> 
 */
vector<DMatch> MatchUsingFREAK(Mat image1, Mat image2,Mat &out, vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2);
/**
 * @brief 
 * 
 * @param corner 
 * @return vector<KeyPoint> 
 */
vector<KeyPoint> Mat2Keypoint(Mat corner);