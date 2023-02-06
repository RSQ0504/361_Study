image = imread("IMG_4760.png");

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

threshold = 0.3;

check_step1 = (~(abs(image_1 - image)<=threshold & abs(image_9 - image)<=threshold));

FAST_step1 = check_step1 .* image;

check_step2 = (abs(image_1 - FAST_step1)>threshold & image_1 > FAST_step1);% brighter
check_step2 = check_step2 - (abs(image_1 - FAST_step1)>threshold & image_1 < FAST_step1);%darker
check_step2 = check_step2+ (abs(image_5 - FAST_step1)>threshold & image_5 > FAST_step1);% brighter
check_step2 = check_step2 - (abs(image_5 - FAST_step1)>threshold & image_5 < FAST_step1);%darker
check_step2 = check_step2+ (abs(image_9 - FAST_step1)>threshold & image_9 > FAST_step1);% brighter
check_step2 = check_step2 - (abs(image_9 - FAST_step1)>threshold & image_9 < FAST_step1);%darker
check_step2 = check_step2+ (abs(image_13 - FAST_step1)>threshold & image_13 > FAST_step1);% brighter
check_step2 = check_step2 - (abs(image_13 - FAST_step1)>threshold & image_13 < FAST_step1);%darker

check_step2 = check_step2 .* check_step1;

check_step2 = (abs(check_step2)>=2);

FAST_step2 = check_step2 .* image;

imshow([FAST_step1 FAST_step2]);

