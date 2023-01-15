
#include <opencv2/opencv.hpp>
#include <iostream>
#include "Color.h"
using namespace cv;

Mat image2double_3C(Mat original){
    Mat doubleimage;
    original.convertTo(doubleimage, CV_64FC3,1.0/255.0);
    return doubleimage;
}

Mat image2hsv(Mat original){
    Mat hsvimage;
    cvtColor(original,hsvimage,COLOR_RGB2HSV);
    return hsvimage;
}

Mat showchannel_3C(Mat original,int channel){
    Mat channels[4];
    Mat target;
    original=image2double_3C(original);
    split(original,channels);

    original.copyTo(target);

    for(int i=0;i<3;i++){
        if (i != channel){
            channels[i]=Mat::zeros(original.rows, original.cols, CV_64FC1);
        }
    }
    merge(channels,3,target);
    return target;
}

Mat getalpha(Mat original){
    Mat channels[4];
    split(original,channels);
    return channels[3];
}