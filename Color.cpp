
#include <opencv2/opencv.hpp>
#include <iostream>
#include "Color.h"
using namespace cv;

Mat image2double_3C(Mat src){
    Mat doubleimage;
    src.convertTo(doubleimage, CV_64FC3,1.0/255.0);
    return doubleimage;
}

Mat image2hsv(Mat src){
    Mat hsvimage;
    cvtColor(src,hsvimage,COLOR_RGB2HSV);
    return hsvimage;
}

Mat showchannel_3C(Mat src,int channel){
    Mat channels[4];
    Mat target;
    src=image2double_3C(src);
    split(src,channels);

    src.copyTo(target);

    for(int i=0;i<3;i++){
        if (i != channel){
            channels[i]=Mat::zeros(src.rows, src.cols, CV_64FC1);
        }
    }
    merge(channels,3,target);
    return target;
}

Mat getalpha(Mat src){
    Mat channels[4];
    split(src,channels);
    return channels[3];
}

void morphological(){
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
    return;
}