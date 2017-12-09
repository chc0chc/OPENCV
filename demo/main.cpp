#include <stdio.h>  
#include <cv.h>  
#include <highgui.h>  
#include <cxcore.h>  
int main()  
{  
        IplImage * image=NULL;  
  
        image = cvLoadImage("lena.jpg");  
        if( !image )  
                printf("loading error!\n");  
        else  
        {  
                cvNamedWindow("1");  
                cvShowImage("1", image);  
                cvWaitKey(0);  
                cvDestroyWindow("1");  
        }  
        return 0;  
}  