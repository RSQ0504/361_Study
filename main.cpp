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

/*
    Mat image1,image2,descriptors1,descriptors2;
    std::vector<KeyPoint> keypoints1,keypoints2;
    std::vector<DMatch> match;

    image1 = imread("./Picture/GF.png",IMREAD_GRAYSCALE);
    image2 =image1;

    matchSiftFeatures(image1,image2,keypoints1,keypoints2,descriptors1,descriptors2,match);

    Mat output;
    drawMatches(image1,keypoints1,image2,keypoints2,match,output);
    imshow("SIFT keypoints", output);
*/
    
    Mat image;
    image = imread("./Picture/HsBoy.png");
    image = DoG(image,5,0,1,Grey);
    image = image * 100;
    imshow("Display Image", image);
    
    waitKey(0);
    return 0;
}