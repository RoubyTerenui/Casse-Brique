#ifndef PALETTE_H
#define PALETTE_H
#include "square.h"

class Palette: public Square
{
public:
    double speed_;

public:
    Palette(double width,double height,double x ,double y,double z,double speed);
    Palette();
};

#endif // PALETTE_H
