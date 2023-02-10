image1 = imread("2.jpg");
image1 = rgb2gray(image1);
image1 =im2double(image1);
targetSize = [750 750];
r = centerCropWindow2d(size(image1),targetSize);
image1 = imcrop(image1,r);
image1 =imresize(image1,[750,750]);
Fast1 = my_fast_detector(image1,0.05);
Faster1 = Harris(image1,Fast1);


image2 = imread("1.JPG");
image2 = rgb2gray(image2);
image2 =im2double(image2);
targetSize = [750 750];
r = centerCropWindow2d(size(image2),targetSize);
image2 = imcrop(image2,r);
image2 =imresize(image2,[750,750]);
Fast2 = my_fast_detector(image2,0.05);
Faster2 = Harris(image2,Fast2);

imshow([Fast1 Faster1; Fast2 Faster2]);


[features1,validPoints1] = matching(image1,Fast1);
[features2,validPoints2] = matching(image2,Fast2);
indexPairs = matchFeatures(features1, features2);
matchedPoints1 = validPoints1(indexPairs(:, 1), :);
matchedPoints2 = validPoints2(indexPairs(:, 2), :);
figure;
showMatchedFeatures(image1, image2, matchedPoints1, matchedPoints2,'montage');


[features1,validPoints1] = matching(image1,Faster1);
[features2,validPoints2] = matching(image2,Faster2);
indexPairs = matchFeatures(features1, features2);
matchedPoints1 = validPoints1(indexPairs(:, 1), :);
matchedPoints2 = validPoints2(indexPairs(:, 2), :);
figure;
showMatchedFeatures(image1, image2, matchedPoints1, matchedPoints2,'montage');

[tform,inlierIdx] = estgeotform2d(matchedPoints1, matchedPoints2,'projective', 'confidence', 99.9, 'MaxNumTrials', 2000);




