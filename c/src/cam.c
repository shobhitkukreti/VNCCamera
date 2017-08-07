#include <stdio.h>

#include <opencv/cv.h> // Include the OpenCV library
#include <opencv/highgui.h> // Include interfaces for video capturing
#include <opencv2/videoio/videoio_c.h>

int main()
{
    cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);
    CvCapture* capture =cvCreateCameraCapture(0);
    if (!capture){
        printf("Error. Cannot capture.");
    }
    else{
        cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);

//        while (1)
	{
            IplImage* frame = cvQueryFrame(capture);
            if(!frame){
                printf("Error. Cannot get the frame.");
//                break;
            }
        cvShowImage("Window",frame);
	printf("%d x %d, %p, %d\n", frame->width, frame->height, &frame->imageData, frame->imageSize);
       cvWaitKey(0);
	 }
        cvReleaseCapture(&capture);
        cvDestroyWindow("Window");
    }
    return 0;
}
