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
   /**/
    Mat *image = new Mat[4];
    Mat result;
    image[0] = imread("./Picture/S2-im1.png");
    image[1] = imread("./Picture/S2-im2.png");
    image[2] = imread("./Picture/S2-im3.png");
    image[3] = imread("./Picture/S2-im4.png");
    result=MyPanoramicImageStitching(image,4);
    //only can stitch 2 image right now
    //result=UsingApiToCreatePanoramic(image,4);
    imshow("check", result);
    waitKey(0);
    return 0;
}