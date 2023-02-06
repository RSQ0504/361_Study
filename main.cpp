#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>
#include "Color.h"
#include "Feature.h"
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
    Mat image, descriptors;
    std::vector<KeyPoint> keypoints;
    image = imread("./Picture/GF.png",IMREAD_GRAYSCALE);
    createSIFT(image,keypoints,descriptors);

    Mat output;
    drawKeypoints(image, keypoints, output);
    imshow("SIFT keypoints", output);
    waitKey(0);
    return 0;
}