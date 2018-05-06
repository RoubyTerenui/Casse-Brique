#include "square.h"
Square::Square(){
    width_=0;
    height_=0;
    center_[0]=0;
    center_[1]=0;
    center_[2]=0;
}
Square::Square(double width,double height,double X,double Y,double Z,int life)
{
    width_=width;
    height_=height;
    center_[0]=X;
    center_[1]=Y;
    center_[2]=Z;
    life_=life;
    score=life;
}
