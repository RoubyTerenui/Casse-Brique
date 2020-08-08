#include "opencvwidget.h"

OpenCvWidget::OpenCvWidget()
{
    frameWidth=320;
    frameHeight=240;
    subImageWidth=100;
    subImageHeight=100;
    templateWidth=25;
    templateHeight=25;
    cap=VideoCapture(0); // open the default camera
    workingRect_= Rect((frameWidth-subImageWidth)/2,frameHeight/2+(frameHeight/2-subImageHeight)/2,subImageWidth,subImageHeight);
    templateRect_=Rect((workingRect_.width-templateWidth)/2,(workingRect_.height-templateHeight)/2,templateWidth,templateHeight);
    workingCenter_=Point(workingRect_.x+subImageWidth/2,workingRect_.y+subImageHeight/2);
}





