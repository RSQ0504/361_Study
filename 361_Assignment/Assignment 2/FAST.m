image = imread("IMG_4760.png");

threshold = 0.3;

ml3 = zeros(7);
ml3(4,1) = 1;
mu3 = zeros(7);
mu3(1,4) = 1;
md3 = zeros(7);
md3(7,4) = 1;
mr3 = zeros(7);
mr3(4,7) = 1;

image = rgb2gray(image);
image =im2double(image);

image_1 = imfilter(image,mu3);
image_9 = imfilter(image,md3);
image_5 = imfilter(image,mr3);
image_13 = imfilter(image,ml3);

image_filter(1,:,:) = zeros(7);
image_filter(1,:,:) = mu3;
image_filter(2,:,:) = zeros(7);
image_filter(2,1,5) = 1;
image_filter(3,:,:) = zeros(7);
image_filter(3,2,6) = 1;
image_filter(4,:,:) = zeros(7);
image_filter(4,3,7) = 1;
image_filter(5,:,:) = zeros(7);
image_filter(5,:,:) = mr3;
image_filter(6,:,:) = zeros(7);
image_filter(6,5,7) = 1;
image_filter(7,:,:) = zeros(7);
image_filter(7,6,6) = 1;
image_filter(8,:,:) = zeros(7);
image_filter(8,7,5) = 1;
image_filter(9,:,:) = zeros(7);
image_filter(9,:,:) = md3;
image_filter(10,:,:) = zeros(7);
image_filter(10,7,3) = 1;
image_filter(11,:,:) = zeros(7);
image_filter(11,6,2) = 1;
image_filter(12,:,:) = zeros(7);
image_filter(12,5,1) = 1;
image_filter(13,:,:) = zeros(7);
image_filter(13,:,:) = ml3;
image_filter(14,:,:) = zeros(7);
image_filter(14,3,1) = 1;
image_filter(15,:,:) = zeros(7);
image_filter(15,2,2) = 1;
image_filter(16,:,:) = zeros(7);
image_filter(16,1,3) = 1;

imageFliterCheck = zeros(7);
result = zeros(7);
for i = 1:16
    result = reshape(image_filter(i,:,:), size(image_filter,2), size(image_filter,3));
    imageFliterCheck=imageFliterCheck+result;
    image_shift(i,:,:) = imfilter(image,result);
end


check_step1 = (~(abs(image_1 - image)<=threshold & abs(image_9 - image)<=threshold));

FAST_step1 = check_step1 .* image;

step2 = (abs(image_1 - FAST_step1)>threshold & image_1 > FAST_step1);% brighter
step2 = step2 - (abs(image_1 - FAST_step1)>threshold & image_1 < FAST_step1);%darker
step2 = step2+ (abs(image_5 - FAST_step1)>threshold & image_5 > FAST_step1);% brighter
step2 = step2 - (abs(image_5 - FAST_step1)>threshold & image_5 < FAST_step1);%darker
step2 = step2+ (abs(image_9 - FAST_step1)>threshold & image_9 > FAST_step1);% brighter
step2 = step2 - (abs(image_9 - FAST_step1)>threshold & image_9 < FAST_step1);%darker
step2 = step2+ (abs(image_13 - FAST_step1)>threshold & image_13 > FAST_step1);% brighter
step2 = step2 - (abs(image_13 - FAST_step1)>threshold & image_13 < FAST_step1);%darker

step2 = step2 .* check_step1;

check_step2 = (abs(step2)>=2);

FAST_step2 = check_step2 .* image;

result = reshape(image_shift(1,:,:), size(image_shift,2), size(image_shift,3));
step3 = (abs(result - FAST_step2)>threshold & result > FAST_step2);% brighter
step3 = step3 - (abs(result - FAST_step2)>threshold & result < FAST_step2);%darker

for i = 2:16
    result = reshape(image_shift(i,:,:), size(image_shift,2), size(image_shift,3));
    step3 = step3 + (abs(result - FAST_step2)>threshold & result > FAST_step2);% brighter
    step3 = step3 - (abs(result - FAST_step2)>threshold & result < FAST_step2);%darker
end
step3 = step3 .* check_step2;
check_step3 = (abs(step3)>=14);
FAST_step3 = check_step3 .*image;

imshow([FAST_step1 FAST_step2 FAST_step3]);

