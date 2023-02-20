#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Color.h"
#include "Feature.h"
#include "Edge.h"
using namespace cv;

int main(){
    /* -------- Color part ------
    // cerr << cv::getBuildInformation() << endl;
    Mat image,image_hsv,image_blue,alpha;
    Mat channels[3];

    image = imread("./Picture/GF.png",IMREAD_UNCHANGED);

    if (!image.data) {
        printf("No image data \n");
        return -1;
    }

    image_blue = showchannel_3C(image,2);
    alpha = getalpha(image);

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", alpha);
    */

/*
    Mat image1,image2;
    std::vector<KeyPoint> keypoints1,keypoints2;
    std::vector<DMatch> match;

    image1 = imread("./Picture/1.png",IMREAD_GRAYSCALE);
    image2 = imread("./Picture/2.png",IMREAD_GRAYSCALE);

    matchSiftFeatures(image1,image2,keypoints1,keypoints2,match,0.08);

    Mat output;
    drawMatches(image1,keypoints1,image2,keypoints2,match,output);
    imshow("SIFT keypoints", output);
    */

    /*
    Mat image;
    image = imread("./Picture/HsBoy.png");
    image = DoG(image,5,0,1,Grey);
    image = image * 100;
    imshow("Display Image", image);
    */
    /*
    Mat image1,image2,out1,out2,match;
    image1 = imread("./Picture/S2-im1.png");
    vector<KeyPoint> k1 =HarrisCornerDetector(image1,out1,10,0.1);
    imshow("Image", out1);
    image2 = imread("./Picture/S2-im2.png");
    vector<KeyPoint> k2 =HarrisCornerDetector(image2,out2,10,0.1);
    imshow("Display Image", out2);
    vector<DMatch> m;
    m = MatchUsingFREAK(image1,image2,match,k1,k2);
    imshow("SIFT Matches", match);
    */

   /*
    Mat image;
    image = imread("./Picture/LP.png");
    Mat result = FFT(image);
    showFFT(result,0.2);
    */
    Mat image1, image2,image3,image4,out;
    image1 = imread("./Picture/S2-im1.png");
    image2 = imread("./Picture/S2-im2.png");
    image3 = imread("./Picture/S2-im3.png");
    image4 = imread("./Picture/S2-im4.png");
    vector<KeyPoint> k1 =FASTCorner(image1,out,150);
    vector<KeyPoint> k2 =FASTCorner(image2,out,150);
    vector<KeyPoint> k3 =FASTCorner(image3,out,150);
    vector<KeyPoint> k4 =FASTCorner(image4,out,150);
    vector<DMatch> m12 = MatchUsingFREAK(image1,image2,out,k1,k2);
    vector<DMatch> m23 = MatchUsingFREAK(image2,image3,out,k2,k3);
    vector<DMatch> m34 = MatchUsingFREAK(image1,image2,out,k3,k4);
    vector<Point2f> points1, points2, points3, points4;
    for (int i = 0; i < m12.size(); i++)
    {
        points1.push_back(k1[m12[i].queryIdx].pt);
        points2.push_back(k2[m12[i].trainIdx].pt);
    }
    for (int i = 0; i < m23.size(); i++)
    {
        points2.push_back(k2[m23[i].queryIdx].pt);
        points3.push_back(k3[m23[i].trainIdx].pt);
    }
    for (int i = 0; i < m34.size(); i++)
    {
        points3.push_back(k3[m34[i].queryIdx].pt);
        points4.push_back(k4[m34[i].trainIdx].pt);
    }
    Mat homography12 = findHomography(points2, points1, RANSAC);
    Mat homography23 = findHomography(points3, points2, RANSAC);
    Mat homography34 = findHomography(points4, points3, RANSAC);

    // Warp input images using homography matrix
    Mat result;
    warpPerspective(image1, result, Mat::eye(3, 3, CV_32F), Size(image1.cols, image1.rows));
    warpPerspective(image2, result, homography12, Size(result.cols, result.rows), INTER_LINEAR, BORDER_CONSTANT);
    warpPerspective(image3, result, homography23 * homography12, Size(result.cols, result.rows), INTER_LINEAR, BORDER_CONSTANT);
    warpPerspective(image4, result, homography34 * homography23 * homography12, Size(result.cols, result.rows), INTER_LINEAR, BORDER_CONSTANT);

    imshow("check", result);
    waitKey(0);
    return 0;
}