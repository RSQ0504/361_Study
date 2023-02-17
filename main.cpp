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
    Mat image,out1,out2;
    out1 = imread("./Picture/HsBoy.png");
    image=HarrisCornerDetector(out1,out2,30,100);
    imshow("Display Image", out2);
    */
    Mat img = imread("1.png", IMREAD_GRAYSCALE);
    Size newSize(20, 20);
    resize(img, img, newSize);
    // Create a kernel for morphological operations
    float filter[3][3] = { { 0, 1, 0 },
                            { 1,  1, 1 },
                            { 0, 1, 0 } };
    Mat kernel = Mat(3, 3, CV_8U, filter);

    // Apply erosion
    Mat erosion;
    erode(img, erosion, kernel);

    // Apply dilation
    Mat dilation;
    dilate(img, dilation, kernel);

    // Apply opening
    Mat opening;
    morphologyEx(img, opening, MORPH_OPEN, kernel);

    // Apply closing
    Mat closing;
    morphologyEx(img, closing, MORPH_CLOSE, kernel);

    // Display results
    namedWindow("Original Image", WINDOW_NORMAL);
    namedWindow("Erosion", WINDOW_NORMAL);
    namedWindow("Dilation", WINDOW_NORMAL);
    namedWindow("Opening", WINDOW_NORMAL);
    namedWindow("Closing", WINDOW_NORMAL);

    imshow("Original Image", img);
    imshow("Erosion", erosion);
    imshow("Dilation", dilation);
    imshow("Opening", opening);
    imshow("Closing", closing);
    waitKey(0);
    return 0;
}