#include "palette.h"
Palette::Palette():Square(){
    speed_=0;
}

Palette::Palette(double width,double height,double x ,double y,double z,double speed):Square(width,height,x,y,z,10)
{

    speed_=speed;

}
