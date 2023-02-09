#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/xfeatures2d.hpp>
#include "Feature.h"
using namespace cv;
using namespace std;

void createSIFT(Mat image, vector<KeyPoint> &keypoints, Mat descriptors)
{
    Ptr<SIFT> s = SIFT::create();
    s->detectAndCompute(image, noArray(), keypoints, descriptors);
}

void matchSiftFeatures(Mat image1, Mat image2,
                        vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2,
                        Mat descriptors1, Mat descriptors2, vector<DMatch> &matches)
{
    Ptr<Feature2D> s = SIFT::create();

    s->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
    s->detectAndCompute(image2, noArray(), keypoints2, descriptors2);

    BFMatcher match(NORM_L2);
    match.match(descriptors1, descriptors2, matches);
}
