#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
using namespace cv;
using namespace std;

/**
 * @brief 
 * Create SIFT keypoints without thredshold
 * @param image 
 * @param keypoints 
 */
void createSIFT(Mat image,vector<KeyPoint> &keypoints);
/**
 * @brief 
 * Create SIFT keypoints with thredshold
 * @param image 
 * @param keypoints 
 * @param threshold value of thrshold which is used to delete the weak feature.
 */
void createSIFT(Mat image,vector<KeyPoint> &keypoints,double threshold);
/**
 * @brief 
 * Match SIFT keypoints without threshold by SIFT
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
 * Match SIFT keypoints with threshold by SIFT
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
 * Find Keypoints by HarrisCornerDetector
 * @param image 
 * @param out show result as a Mat picture
 * @param size neighbourhood size
 * @param threshold 
 * @return Mat 
 */
vector<KeyPoint> HarrisCornerDetector(Mat image,Mat &out,int size, float t);
/**
 * @brief 
 * Find Keypoints by FAST
 * @param image 
 * @param out show result as a Mat picture
 * @param threshold 
 * @return vector<KeyPoint> 
 */
vector<KeyPoint> FASTCorner(Mat image,Mat &out, int threshold);
/**
 * @brief 
 * Match keypoints (found by other corner detector) By SIFT
 * @param image1 
 * @param image2 
 * @param out show result as a Mat picture
 * @param keypoints1 
 * @param keypoints2 
 * @return vector<DMatch> 
 */
vector<DMatch> MatchUsingSIFT(Mat image1, Mat image2,Mat &out, vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2);
/**
 * @brief 
 * Match keypoints (found by other corner detector) by FREAK
 * @param image1 
 * @param image2 
 * @param out show result as a Mat picture
 * @param keypoints1 
 * @param keypoints2 
 * @return vector<DMatch> 
 */
vector<DMatch> MatchUsingFREAK(Mat image1, Mat image2,Mat &out, vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2);

/**
 * @brief 
 * Match keypoints (found by other corner detector) by SURF
 * @param image1 
 * @param image2 
 * @param out show result as a Mat picture
 * @param keypoints1 
 * @param keypoints2 
 * @return vector<DMatch> 
 */
vector<DMatch> MatchUsingSURF(Mat image1, Mat image2,Mat &out, vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2);

/**
 * @brief 
 * Transform Mat into Keypoint
 * @param corner 
 * @return vector<KeyPoint> 
 */
vector<KeyPoint> Mat2Keypoint(Mat corner);
/**
 * @brief 
 * PanoramicImageStitching by n pictures
 * @param image 
 * @param size the length of the array of pictures
 * @return Mat 
 */
Mat MyPanoramicImageStitching(Mat* image,int size);

Mat UsingApiToCreatePanoramic(Mat *image,int size);