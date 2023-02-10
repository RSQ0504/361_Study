function [features1,validPoints1] = matching(image,keypoint)
    x=[];
    y=[];
    
    for i = 1:size(keypoint,1)
        for j = 1:size(keypoint,2)
            if (keypoint(i,j)==1)
                x=[x j];
                y=[y i];
            end
        end
    end
    
    keypoint1 =[x', y'];
    
    [features1,validPoints1] = extractFeatures(image, keypoint1,'Method','SURF', 'SURFSize', 64);
end