#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/xfeatures2d.hpp>
#include "Feature.h"
using namespace cv;

void createSIFT(const Mat& image, std::vector<KeyPoint>& keypoints, Mat& descriptors)
{
    Ptr<SIFT> sift = SIFT::create();
    sift->detectAndCompute(image, noArray(), keypoints, descriptors);
}

void matchSiftFeatures(const Mat& image1, const Mat& image2,
                        std::vector<KeyPoint>& keypoints1,std::vector<KeyPoint>& keypoints2,
                        Mat& descriptors1, Mat& descriptors2, std::vector<DMatch>& matches)
{
    Ptr<Feature2D> sift = SIFT::create();

    sift->detectAndCompute(image1, noArray(), keypoints1, descriptors1);
    sift->detectAndCompute(image2, noArray(), keypoints2, descriptors2);

    BFMatcher matcher(NORM_L2);
    matcher.match(descriptors1, descriptors2, matches);
}

void detectHarrisCorners(const Mat& image, std::vector<Point2f>& corners,double t)
{
    Mat cornerStrength;
    cornerHarris(image, cornerStrength, 2, 3, 0.04);

    Mat harrisCorners;
    threshold(cornerStrength, harrisCorners, t, 255, THRESH_BINARY);

    for (int y = 0; y < harrisCorners.rows; y++)
    {
        for (int x = 0; x < harrisCorners.cols; x++)
        {
            if (harrisCorners.at<float>(y, x) > 0.01)
            {
                corners.push_back(cv::Point2f(x, y));
            }
        }
    }
}
