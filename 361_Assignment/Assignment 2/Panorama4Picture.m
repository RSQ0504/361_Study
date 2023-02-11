image1 = imread("./SrcPicture/1.png");
image1 =im2double(image1);
targetSize = [1500 1500];
r = centerCropWindow2d(size(image1),targetSize);
image1 = imcrop(image1,r);
image1 =imresize(image1,[750,750]);
rgb1 = image1;
imwrite(image1,"./ResultPicture/S1-im1.png");
image1 = rgb2gray(image1);
Fast1 = my_fast_detector(image1,0.05);
Faster1 = Harris(image1,Fast1);

imwrite(Fast1,"./ResultPicture/S1-fast.png");
imwrite(Faster1,"./ResultPicture/S1-fastR.png");


image2 = imread("./SrcPicture/2.png");
image2 =im2double(image2);
targetSize = [1500 1500];
r = centerCropWindow2d(size(image2),targetSize);
image2 = imcrop(image2,r);
image2 =imresize(image2,[750,750]);
rgb2 = image2;
imwrite(image2,"./ResultPicture/S1-im2.png");
image2 = rgb2gray(image2);
Fast2 = my_fast_detector(image2,0.05);
Faster2 = Harris(image2,Fast2);
%imshow([Fast1 Faster1; Fast2 Faster2]);


image3 = imread("./SrcPicture/3.png");
image3 =im2double(image3);
targetSize = [1500 1500];
r = centerCropWindow2d(size(image3),targetSize);
image3 = imcrop(image3,r);
image3 =imresize(image3,[750,750]);
rgb3 = image3;
imwrite(image3,"./ResultPicture/S1-im3.png");
image3 = rgb2gray(image3);
Fast3 = my_fast_detector(image3,0.05);
Faster3 = Harris(image3,Fast3);

image4 = imread("./SrcPicture/4.png");
image4 =im2double(image4);
targetSize = [1500 1500];
r = centerCropWindow2d(size(image4),targetSize);
image4 = imcrop(image4,r);
image4 =imresize(image4,[750,750]);
rgb4 = image4;
imwrite(image4,"./ResultPicture/S1-im4.png");
image4 = rgb2gray(image4);
Fast4 = my_fast_detector(image4,0.05);
Faster4 = Harris(image4,Fast4);
imshow([rgb1 rgb2;rgb3 rgb4]);

[features1Fast,validPoints1Fast] = matching(image1,Fast1);
[features2Fast,validPoints2Fast] = matching(image2,Fast2);
[features3Fast,validPoints3Fast] = matching(image3,Fast3);
[features4Fast,validPoints4Fast] = matching(image4,Fast4);
indexPairsFast = matchFeatures(features1Fast, features2Fast);
matchedPoints1Fast = validPoints1Fast(indexPairsFast(:, 1), :);
matchedPoints2Fast = validPoints2Fast(indexPairsFast(:, 2), :);
indexPairsFast = matchFeatures(features2Fast, features3Fast);
matchedPoints3Fast = validPoints2Fast(indexPairsFast(:, 1), :);
matchedPoints4Fast = validPoints3Fast(indexPairsFast(:, 2), :);
indexPairsFast = matchFeatures(features3Fast, features4Fast);
matchedPoints5Fast = validPoints3Fast(indexPairsFast(:, 1), :);
matchedPoints6Fast = validPoints4Fast(indexPairsFast(:, 2), :);
%figure;
%showMatchedFeatures(rgb1, rgb2, matchedPoints1Fast, matchedPoints2Fast,'montage');
%figure;
%showMatchedFeatures(rgb2, rgb3, matchedPoints3Fast, matchedPoints4Fast,'montage');
figure;
showMatchedFeatures(rgb3, rgb4, matchedPoints5Fast, matchedPoints6Fast,'montage');
saveas(gcf, './ResultPicture/S1-fastMatch.png');

[features1Faster,validPoints1Faster] = matching(image1,Faster1);
[features2Faster,validPoints2Faster] = matching(image2,Faster2);
[features3Faster,validPoints3Faster] = matching(image3,Faster3);
[features4Faster,validPoints4Faster] = matching(image4,Faster4);
indexPairsFaster = matchFeatures(features1Faster, features2Faster);
matchedPoints1Faster = validPoints1Faster(indexPairsFaster(:, 1), :);
matchedPoints2Faster = validPoints2Faster(indexPairsFaster(:, 2), :);
indexPairsFaster = matchFeatures(features2Faster, features3Faster);
matchedPoints3Faster = validPoints2Faster(indexPairsFaster(:, 1), :);
matchedPoints4Faster = validPoints3Faster(indexPairsFaster(:, 2), :);
indexPairsFaster = matchFeatures(features3Faster, features4Faster);
matchedPoints5Faster = validPoints3Faster(indexPairsFaster(:, 1), :);
matchedPoints6Faster = validPoints4Faster(indexPairsFaster(:, 2), :);
%figure;
%showMatchedFeatures(rgb1, rgb2, matchedPoints1Faster, matchedPoints2Faster,'montage');
%figure;
%showMatchedFeatures(rgb2, rgb3, matchedPoints3Faster, matchedPoints4Faster,'montage');
figure;
showMatchedFeatures(rgb3, rgb4, matchedPoints5Faster, matchedPoints6Faster,'montage');
saveas(gcf, './ResultPicture/S1-fastRMatch.png');


imageSize = [750 750;750 750;750 750;750 750];
tformsFaster(1) = projtform2d;
tformsFaster(2) = estgeotform2d(matchedPoints2Faster, matchedPoints1Faster,'projective', 'confidence', 99, 'MaxNumTrials', 2000);
tformsFaster(2).A = tformsFaster(1).A * tformsFaster(2).A;
tformsFaster(3) = estgeotform2d(matchedPoints4Faster, matchedPoints3Faster,'projective', 'confidence', 99, 'MaxNumTrials', 2000);
tformsFaster(3).A = tformsFaster(2).A * tformsFaster(3).A;
tformsFaster(4) = estgeotform2d(matchedPoints6Faster, matchedPoints5Faster,'projective', 'confidence', 99, 'MaxNumTrials', 2000);
tformsFaster(4).A = tformsFaster(3).A * tformsFaster(4).A;


Tinv = invert(tformsFaster(2));
tformsFaster(1).A = Tinv.A * tformsFaster(1).A;
tformsFaster(2) = projtform2d;
tformsFaster(3).A = Tinv.A * tformsFaster(3).A;
tformsFaster(4).A = Tinv.A * tformsFaster(4).A;

[xlim(1,:), ylim(1,:)] = outputLimits(tformsFaster(1), [1 imageSize(1,2)], [1 imageSize(1,1)]);
[xlim(2,:), ylim(2,:)] = outputLimits(tformsFaster(2), [1 imageSize(2,2)], [1 imageSize(2,1)]);
[xlim(3,:), ylim(3,:)] = outputLimits(tformsFaster(3), [1 imageSize(3,2)], [1 imageSize(3,1)]);
[xlim(4,:), ylim(4,:)] = outputLimits(tformsFaster(4), [1 imageSize(4,2)], [1 imageSize(4,1)]);
maxImageSize = max(imageSize);
xMin = min([1; xlim(1)]);
xMax = max([maxImageSize(2); xlim(:)]);
yMin = min([1; ylim(1)]);
yMax = max([maxImageSize(1); ylim(:)]);
width  = round(xMax - xMin);
height = round(yMax - yMin);
panorama = zeros([height,width,3]);
%panorama = zeros(2000,2000);
xLimits = [xMin xMax];
yLimits = [yMin yMax];
panoramaView = imref2d([height width], xLimits, yLimits);


blender = vision.AlphaBlender('Operation', 'Binary mask', 'MaskSource', 'Input port');  

warpedImage1 = imwarp(rgb1, tformsFaster(1), 'OutputView', panoramaView);
mask1 = imwarp(true(size(rgb1,1),size(rgb1,2)), tformsFaster(1), 'OutputView', panoramaView);
panorama = step(blender, panorama, warpedImage1, mask1);

warpedImage2 = imwarp(rgb2, tformsFaster(2), 'OutputView', panoramaView);
mask2 = imwarp(true(size(rgb2,1),size(rgb2,2)), tformsFaster(2), 'OutputView', panoramaView);
panorama = step(blender, panorama, warpedImage2, mask2);

warpedImage3 = imwarp(rgb3, tformsFaster(3), 'OutputView', panoramaView);
mask3 = imwarp(true(size(rgb3,1),size(rgb3,2)), tformsFaster(3), 'OutputView', panoramaView);
panorama = step(blender, panorama, warpedImage3, mask3);

warpedImage4 = imwarp(rgb4, tformsFaster(4), 'OutputView', panoramaView);
mask4 = imwarp(true(size(rgb4,1),size(rgb4,2)), tformsFaster(4), 'OutputView', panoramaView);
panorama = step(blender, panorama, warpedImage4, mask4);

figure
imshow(panorama);
imwrite(panorama,"./ResultPicture/S1-panorama.png");