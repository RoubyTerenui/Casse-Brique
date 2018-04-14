#include "ball.h"
Ball::Ball(){
    radius_=0;
    center_[0]=0;
    center_[1]=0;
    center_[2]=0;
    speed_=0;
}
Ball::Ball(double radius,double x ,double y,double z,double speed)
{
    radius_=radius;
    center_[0]=x;
    center_[1]=y;
    center_[2]=z;
    speed_=speed;
    directionX_=1;
    directionY_=1;
    directionZ_=0;
    state_=QString("unfixed");// A l'initialisation la bille est collé
}
double *Ball::getDirection(){
    double direction[3];
    direction[0]=directionX_;
    direction[1]=directionY_;
    direction[2]=directionZ_;

    return(direction);
}
