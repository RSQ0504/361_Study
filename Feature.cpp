#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/xfeatures2d.hpp>
#include "Feature.h"
using namespace cv;
using namespace std;

vector<KeyPoint> Mat2Keypoint(Mat corners){
    vector<KeyPoint> keypoints;
        for (int i = 0; i < corners.rows; i++) {
            for (int j = 0; j < corners.cols; j++) {
                if (corners.at<uchar>(i, j) > 0) {
                    keypoints.push_back(KeyPoint(j, i, 1));
                }
            }
        }
    return keypoints;
}

void createSIFT(Mat image, vector<KeyPoint> &keypoints)
{
    Ptr<SIFT> s = SIFT::create();
    Mat descriptors;
    s->detectAndCompute(image, noArray(), keypoints, descriptors);
}

void createSIFT(Mat image,vector<KeyPoint> &keypoints,double threshold){
    Ptr<SIFT> s = SIFT::create();
    vector<KeyPoint> tempt;
    s->detect(image, tempt);
    for (int i = 0; i < tempt.size(); i++) {
        KeyPoint k = tempt[i];
        if (k.response > threshold) {
            keypoints.push_back(k);
        }
    }
}


void matchSiftFeatures(Mat image1, Mat image2,
                        vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2,
                        vector<DMatch> &matches)
{
    Ptr<Feature2D> s = SIFT::create();
    Mat descriptors1,descriptors2;

    s->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
    s->detectAndCompute(image2, noArray(), keypoints2, descriptors2);

    BFMatcher match(NORM_L2);
    match.match(descriptors1, descriptors2, matches);
}

void matchSiftFeatures(Mat image1, Mat image2,
                        vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2,
                        vector<DMatch> &matches,double threshold)
{
    Ptr<Feature2D> s = SIFT::create();
    Mat descriptors1,descriptors2;
    vector<KeyPoint> tempt1,tempt2;

    s->detect(image1, tempt1);
    s->detect(image2,tempt2);

    for (int i = 0; i < tempt1.size(); i++) {
        KeyPoint k = tempt1[i];
        if (k.response > threshold) {
            keypoints1.push_back(k);
        }
    }
    for (int i = 0; i < tempt2.size(); i++) {
        KeyPoint k = tempt2[i];
        if (k.response > threshold) {
            keypoints2.push_back(k);
        }
    }

    s->compute(image1,keypoints1,descriptors1);
    s->compute(image2,keypoints2,descriptors2);

    BFMatcher match(NORM_L2);
    match.match(descriptors1, descriptors2, matches);
}

vector<KeyPoint> HarrisCornerDetector(Mat src,Mat &out,int size, float t)
{
    Mat image = src;
    if (image.channels()!=1)
        cvtColor(image, image, COLOR_BGR2GRAY);
    
    Mat corners;
    cornerHarris(image, corners, size, 5, 0.05);

    Mat k = Mat::zeros(corners.size(), CV_8UC1);
    for( int i = 0; i < corners.rows ; i++ )
    {
        for( int j = 0; j < corners.cols; j++ )
        {
            if(corners.at<float>(i,j) > t )
            {
                k.at<uchar>(i,j) = 255;
            }
        }
    }

    vector<KeyPoint> keypoints = Mat2Keypoint(k);
    drawKeypoints(image, keypoints, out);
    return keypoints;
}

vector<KeyPoint> FASTCorner(Mat image,Mat &out, int threshold){
    if (image.channels()!=1)
        cvtColor(image, image, COLOR_BGR2GRAY);
    bool nonmaxSuppression = true;
    Ptr<FastFeatureDetector> fast = FastFeatureDetector::create(threshold, nonmaxSuppression);
    vector<KeyPoint> keypoints;
    fast->detect(image, keypoints);
    drawKeypoints(image, keypoints, out);
    return keypoints;
}

vector<DMatch> MatchUsingSIFT(Mat image1, Mat image2, Mat &out, vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2){
    Mat descriptors1, descriptors2;
    Ptr<SIFT> sift = SIFT::create();
    sift->compute(image1, keypoints1, descriptors1);
    sift->compute(image2, keypoints2, descriptors2);

    BFMatcher matcher(NORM_L2);
    vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);

    drawMatches(image1, keypoints1, image2, keypoints2, matches, out);

    return matches;
}

vector<DMatch> MatchUsingFREAK(Mat image1, Mat image2,Mat &out, vector<KeyPoint> &keypoints1,vector<KeyPoint> &keypoints2){
    Ptr<xfeatures2d::FREAK> freak = xfeatures2d::FREAK::create();
    Mat descriptors1, descriptors2;
    freak->compute(image1, keypoints1, descriptors1);
    freak->compute(image2, keypoints2, descriptors2);

    BFMatcher matcher(NORM_HAMMING);
    vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);

    drawMatches(image1, keypoints1, image2, keypoints2, matches, out);
    return matches;
}
