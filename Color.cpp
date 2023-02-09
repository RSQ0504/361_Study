
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