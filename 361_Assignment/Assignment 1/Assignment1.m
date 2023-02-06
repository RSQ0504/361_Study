
high = imread("./src/Original1.png");
high = im2double(high);
high = rgb2gray(high);
targetSize = [500 500];
r = centerCropWindow2d(size(high),targetSize);
high = imcrop(high,r);
%imshow(high);

highresize =imresize(high,[500,500]);
%figure
%imshow(highresize);
imwrite(highresize,'./Result_png/HP.png');

highfou = fft2(highresize);
%figure
%imshow(fftshift(abs(highfou))/200);
imwrite(fftshift(abs(highfou))/200,'./Result_png/HP-freq.png');

low = imread("./src/Original2.png");
low = im2double(low);
low = rgb2gray(low);
targetSize = [500 500];
r = centerCropWindow2d(size(low),targetSize);
low = imcrop(low,r);
%figure
%imshow(low);

lowresize =imresize(low,[500,500]);
%figure
%imshow(lowresize);
imwrite(lowresize,'./Result_png/LP.png');

lowfou = fft2(lowresize);
%figure
%imshow(fftshift(abs(lowfou))/200);
imwrite(fftshift(abs(lowfou))/200,'./Result_png/LP-freq.png');


sob = [-1 0 1; -2 0 2; -1 0 1];
gausk = fspecial ('gaussian', 50, 2.5);
%figure
surf(gausk);
saveas(gcf, './Result_png/gaus-surf.png');
figure
surf(conv2(gausk, sob));
DoG = conv2(gausk, sob);
saveas(gcf, './Result_png/dog-surf.png');

hf_gaus = imfilter (highresize, gausk);
hf_gaus_fou = fft2 (hf_gaus);
hf_gaus_fou = fftshift(abs(hf_gaus_fou))/200;
lf_gaus = imfilter (lowresize, gausk);
lf_gaus_fou = fft2 (lf_gaus);
lf_gaus_fou=fftshift(abs(lf_gaus_fou))/200;
%figure
%imshow([hf_gaus hf_gaus_fou; lf_gaus lf_gaus_fou]);
imwrite(hf_gaus,'./Result_png/HP-filt.png');
imwrite(hf_gaus_fou,'./Result_png/HP-filt-freq.png');
imwrite(lf_gaus,'./Result_png/LP-filt.png');
imwrite(lf_gaus_fou,'./Result_png/LP-filt-freq.png');


DoG_fou = fft2(DoG,500,500);
hf_DoG_fou = DoG_fou .* highfou;
hf_DoG_fou_shift = fftshift(abs(hf_DoG_fou))/200;
lf_DoG_fou = DoG_fou .* lowfou;
lf_DoG_fou_shift = fftshift(abs(lf_DoG_fou))/200;
hf_DoG = ifft2(hf_DoG_fou);
lf_DoG = ifft2(lf_DoG_fou);
%figure 
%imshow([hf_DoG_fou_shift lf_DoG_fou_shift]);
%figure
%imshow([hf_DoG lf_DoG]);
imwrite(hf_DoG_fou_shift,'./Result_png/HP-dogfilt-freq.png');
imwrite(hf_DoG,'./Result_png/HP-dogfilt.png');
imwrite(lf_DoG,'./Result_png/LP-dogfilt.png');
imwrite(lf_DoG_fou_shift,'./Result_png/LP-dogfilt-freq.png');


highsub1 = highresize(1:2:end,1:2:end);
highsub1_fou = fft2(highsub1);
highsub1_fouShift = fftshift(abs(highsub1_fou))/200;
lowsub1 = lowresize(1:2:end,1:2:end);
lowsub1_fou = fft2(lowsub1);
lowsub1_fouShift = fftshift(abs(lowsub1_fou))/200;
%figure
%imshow([highsub1 lowsub1]);
imwrite(highsub1,'./Result_png/HP-sub2.png');
imwrite(lowsub1,'./Result_png/LP-sub2.png');
imwrite(highsub1_fouShift,'./Result_png/HP-sub2-freq.png');
imwrite(lowsub1_fouShift,'./Result_png/LP-sub2-freq.png');


highsub2 = highresize(1:4:end,1:4:end);
highsub2_fou = fft2(highsub2);
highsub2_fouShift = fftshift(abs(highsub2_fou))/200;
lowsub2 = lowresize(1:4:end,1:4:end);
lowsub2_fou = fft2(lowsub2);
lowsub2_fouShift = fftshift(abs(lowsub2_fou))/200;
%figure
%imshow([highsub2 lowsub2]);
imwrite(highsub2,'./Result_png/HP-sub4.png');
imwrite(lowsub2,'./Result_png/LP-sub4.png');
imwrite(highsub2_fouShift,'./Result_png/HP-sub4-freq.png');
imwrite(lowsub2_fouShift,'./Result_png/LP-sub4-freq.png');


gausk_aa_sub1 = fspecial ('gaussian', 5, 1.5);
HP_sub2_aa = imfilter(highresize,gausk_aa_sub1);
HP_sub2_aa = HP_sub2_aa(1:2:end,1:2:end);
%figure
%imshow([highsub1 HP_sub2_aa]);
imwrite(HP_sub2_aa,'./Result_png/HP-sub2-aa.png');
HP_sub2_aa_fou=fft2(HP_sub2_aa);
HP_sub2_aa_fou = fftshift(abs(HP_sub2_aa_fou))/200;
imwrite(HP_sub2_aa_fou,'./Result_png/HP-sub2-aa-freq.png');


gausk_aa_sub2 = fspecial ('gaussian', 30, 1.5);
HP_sub4_aa = imfilter(highresize,gausk_aa_sub2);
HP_sub4_aa = HP_sub4_aa(1:4:end,1:4:end);
%figure
%imshow([highsub2 HP_sub4_aa]);
imwrite(HP_sub4_aa,'./Result_png/HP-sub4-aa.png');
HP_sub4_aa_fou=fft2(HP_sub4_aa);
HP_sub4_aa_fou = fftshift(abs(HP_sub4_aa_fou))/200;
imwrite(HP_sub4_aa_fou,'./Result_png/HP-sub4-aa-freq.png');


[cannyedge_high, ~] = edge(highresize,'canny',[0.04,0.08]);
[hll, ~] = edge(highresize,'canny',[0.02,0.08]);
[hlh, ~] = edge(highresize,'canny',[0.07,0.08]);
[hhl, ~] = edge(highresize,'canny',[0.04,0.06]);
[hhh, ~] = edge(highresize,'canny',[0.04,0.1]);
%figure
%imshow([hhh; cannyedge_high]);
imwrite(cannyedge_high,'./Result_png/HP-canny-optimal.png');
imwrite(hll,'./Result_png/HP-canny-lowlow.png');
imwrite(hlh,'./Result_png/HP-canny-highlow.png');
imwrite(hhl,'./Result_png/HP-canny-lowhigh.png');
imwrite(hhh,'./Result_png/HP-canny-highhigh.png');


[cannyedge_low, ~] = edge(lowresize,'canny',[0.1,0.16]);
[lll, ~] = edge(lowresize,'canny',[0.05,0.16]);
[llh, ~] = edge(lowresize,'canny',[0.12,0.16]);
[lhl, ~] = edge(lowresize,'canny',[0.1,0.14]);
[lhh, threshold] = edge(lowresize,'canny',[0.1,0.18]);
%figure
%imshow([lhh cannyedge_low]);
imwrite(cannyedge_low,'./Result_png/LP-canny-optimal.png');
imwrite(lll,'./Result_png/LP-canny-lowlow.png');
imwrite(llh,'./Result_png/LP-canny-highlow.png');
imwrite(lhl,'./Result_png/LP-canny-lowhigh.png');
imwrite(lhh,'./Result_png/LP-canny-highhigh.png');
