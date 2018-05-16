#include "opencvwidget.h"

OpenCvWidget::OpenCvWidget()
{
    frameWidth=320;
    frameHeight=240;
    subImageWidth=100;
    subImageHeight=100;
    templateWidth=25;
    templateHeight=25;

    workingRect_= Rect((frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
    templateRect_=Rect((workingRect_.width-templateWidth)/2,(workingRect_.height-templateHeight)/2,templateWidth,templateHeight);
    workingCenter_=Point(workingRect_.x+subImageWidth/2,workingRect_.y+subImageHeight/2);
}

QPixmap OpenCvWidget::drawQPixMap()
{
    cap=VideoCapture(0); // open the default camera
    cap.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight);

    if(!cap.isOpened())  // check if we succeeded
    {
        cerr<<"Error openning the default camera"<<endl;
        state=false;
        return(QPixmap());
    }
    else {
        state=true;

        // Create the matchTemplate image result
        Mat resultImage;    // to store the matchTemplate result
        int result_cols =  frame1.cols-templateWidth  + 1;
        int result_rows = frame1.rows-templateHeight + 1;
        resultImage.create( result_cols, result_rows, CV_32FC1 );

        // Get frame2
        cap.read(frame2);
        // Mirror effect
        cv::flip(frame2,frame2,1);
        // Extract working rect in frame2 and convert to gray
        cv::cvtColor(Mat(frame2,workingRect_),frameRect2,COLOR_BGR2GRAY);

        // Extract template image in frame1
        Mat templateImage(frameRect1,templateRect_);
        // Do the Matching between the working rect in frame2 and the templateImage in frame1
        matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
        // Localize the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
        // Compute the translation vector between the origin and the matching rect
        Point vect(maxLoc.x-templateRect_.x,maxLoc.y-templateRect_.y);

        // Draw green rectangle and the translation vector
        rectangle(frame2,workingRect_,Scalar( 0, 255, 0),2);
        Point p(workingCenter_.x+vect.x,workingCenter_.y+vect.y);
        arrowedLine(frame2,workingCenter_,p,Scalar(255,255,255),2);
        QImage frameactu=QImage((uchar*) frame2.data, frame2.cols, frame2.rows, QImage::Format_RGB888);

        cerr<<frame2.cols;
        cerr<<"+"<<frame2.rows;
        // Swap matrixes
        swap(frameRect1,frameRect2);

        return(QPixmap::fromImage(frameactu));
    }
}




