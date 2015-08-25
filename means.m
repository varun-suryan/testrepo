# testrepo
function [J] =means(I,K)
I=im2double(I);
R=I(:,:,1);
G=I(:,:,2);
B=I(:,:,3);
R=R(:);
G=G(:);
B=B(:);
h=repmat((1:size(I,1))',size(I,2),1)/(size(I,1));
g=(repmat(1:size(I,2),size(I,1),1))/(size(I,2));
M=[R G B];
[idx,C]=kmeans(M,K);
M=C(idx,:);
for k=1:size(I,3)
t=1;
	for i=1:size(I,2)
		for j=1:size(I,1)
		J(j,i,k)=M(t,k);
		t=t+1;
		end
	end
end
f=J(:,:,:);
imshow(J);
end

