#include<iostream>
#include<cv.h>
#include<cxcore.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cvaux.h>

int main(){
	const char* fileName="./kk.bmp";
	IplImage *src=NULL;
	src=cvLoadImage((char*)fileName.CV_LOAD_IMAGE_ANYCOLOR);
	if(src == NULL && isImageTiff((char*)fileName)){
	src=loadImageTiff((char*)fileName);
	}
	if(src==NULL){
	std::cout<<"read error"<<std::endl;
	return 1;
	}else{
	std::cout<<"read OK"<<std::endl;
	return 0;
	}
}
