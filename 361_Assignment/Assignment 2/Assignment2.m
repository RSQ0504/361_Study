clear;
image1 = imread("2.png");
image1 = rgb2gray(image1);
image1 =im2double(image1);
targetSize = [1500 1500];
r = centerCropWindow2d(size(image1),targetSize);
image1 = imcrop(image1,r);
image1 =imresize(image1,[750,750]);
Fast1 = my_fast_detector(image1,0.05);
Faster1 = Harris(image1,Fast1);


image2 = imread("1.png");
image2 = rgb2gray(image2);
image2 =im2double(image2);
targetSize = [1500 1500];
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




imageSize = [targetSize;targetSize];
tforms2 = estgeotform2d(matchedPoints1, matchedPoints2,'projective', 'confidence', 99, 'MaxNumTrials', 2000);
tforms2 = invert(tforms2);
tforms1 = projtform2d;


[xlim(1,:), ylim(1,:)] = outputLimits(tforms1, [1 imageSize(1,2)], [1 imageSize(1,1)]);
[xlim(2,:), ylim(2,:)] = outputLimits(tforms2, [1 imageSize(2,2)], [1 imageSize(2,1)]);
maxImageSize = max(imageSize);
xMin = min([1; xlim(:)]);
xMax = max([maxImageSize(2); xlim(:)]);
yMin = min([1; ylim(:)]);
yMax = max([maxImageSize(1); ylim(:)]);
width  = round(xMax - xMin);
height = round(yMax - yMin);
panorama = zeros(height,width);
%panorama = zeros(2000,2000);


blender = vision.AlphaBlender('Operation', 'Binary mask', 'MaskSource', 'Input port');  
xLimits = [xMin xMax];
yLimits = [yMin yMax];
panoramaView = imref2d([height width], xLimits, yLimits);

warpedImage1 = imwarp(image1, tforms1, 'OutputView', panoramaView);
mask1 = imwarp(true(size(image1,1),size(image1,2)), tforms1, 'OutputView', panoramaView);
panorama = step(blender, panorama, warpedImage1, mask1);

warpedImage2 = imwarp(image2, tforms2, 'OutputView', panoramaView);
mask2 = imwarp(true(size(image2,1),size(image2,2)), tforms2, 'OutputView', panoramaView);
panorama = step(blender, panorama, warpedImage2, mask2);

figure
imshow(panorama);



