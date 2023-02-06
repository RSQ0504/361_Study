#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
using namespace cv;


void createSIFT(const Mat& image, std::vector<KeyPoint>& keypoints, Mat& descriptors);

void matchSiftFeatures(const Mat& image1, const Mat& image2, 
                        std::vector<KeyPoint>& keypoints1, std::vector<KeyPoint>& keypoints2,
                        std::vector<DMatch>& matches);

void detectHarrisCorners(const Mat& image, std::vector<Point2f>& corners);
