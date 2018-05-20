#ifndef OPENCVWIDGET_H
#define OPENCVWIDGET_H

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QWidget>
#include <cstdio>
#include <iostream>
using namespace cv;
using namespace std;
class OpenCvWidget
{
public:
    OpenCvWidget();
public:
    int frameWidth;
    int frameHeight;
    int subImageWidth;
    int subImageHeight;
    int templateWidth;
    int templateHeight;
    bool state;
    Rect workingRect_;
    Rect templateRect_;
    Point workingCenter_;
    VideoCapture cap;
};

#endif // OPENCVWIDGET_H
