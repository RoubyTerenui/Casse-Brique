#ifndef PALETTE_H
#define PALETTE_H
#include "square.h"

class Palette: public Square
{
private:
    double speed_;

public:
    Palette(double width,double height,double x ,double y,double z,double speed);
    Palette();
    double getSpeed(){return(speed_);}
    void setSpeed(double sp){speed_=sp;}
};

#endif // PALETTE_H
