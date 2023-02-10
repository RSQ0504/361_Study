#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
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


    Mat image1,image2;
    std::vector<KeyPoint> keypoints1,keypoints2;
    std::vector<DMatch> match;

    image1 = imread("./Picture/1.png",IMREAD_GRAYSCALE);
    image2 = imread("./Picture/2.png",IMREAD_GRAYSCALE);

    matchSiftFeaturesDeleteWeak(image1,image2,keypoints1,keypoints2,match,0.1);

    Mat output;
    drawMatches(image1,keypoints1,image2,keypoints2,match,output);
    imshow("SIFT keypoints", output);

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
    waitKey(0);
    return 0;
}