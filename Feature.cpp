#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/xfeatures2d.hpp>
#include "Feature.h"
using namespace cv;
using namespace std;

void createSIFT(Mat image, vector<KeyPoint> &keypoints)
{
    Ptr<SIFT> s = SIFT::create();
    Mat descriptors;
    s->detectAndCompute(image, noArray(), keypoints, descriptors);
}

void createSIFTDeleteWeak(Mat image,vector<KeyPoint> &keypoints,double threshold){
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

void matchSiftFeaturesDeleteWeak(Mat image1, Mat image2,
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

Mat HarrisCornerDetector(Mat src,Mat &out,int size, int threshold)
{
    Mat image = src;
    if (image.channels()!=1)
        cvtColor(image, image, COLOR_BGR2GRAY);

    out = src;
    if (out.channels()!=1)
        cvtColor(out, out, COLOR_BGR2GRAY);

    Mat dst_norm;
    cornerHarris(image, image, size, 5, 0.05, BORDER_DEFAULT);
    normalize(image, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());


    for(int i = 0; i < dst_norm.rows; i++)
    {
        for(int j = 0; j < dst_norm.cols; j++)
        {
            if((int) dst_norm.at<float>(i,j) > threshold)
            {
                circle(image, Point(j,i), 10,  Scalar(10));
                circle(out, Point(j,i), 10,  Scalar(10));
            }
        }
    }
    return image;
}