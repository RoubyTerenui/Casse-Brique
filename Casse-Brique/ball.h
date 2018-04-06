#ifndef BALL_H
#define BALL_H


class Ball
{
private:
    double radius_;
    double center_[3];//Juste 2 coordonnées correspond à un z fixe
    double speed_;
    double directionX_;
    double directionY_;
    double directionZ_;

public:
    Ball();
    Ball(double radius,double x,double y,double z,double speed);
    double getRadius(){return radius_;}
    double getspeed(){return speed_;}
    double getX(){return center_[0];}
    double getY(){return center_[1];}
    double getZ(){return center_[2];}
    double *getDirection();
    void setDirectionX(double directionX){directionX_=directionX;}
    void setDirectionY(double directionY){directionY_=directionY;}
    void setDirectionZ(double directionZ){directionZ_=directionZ;}
    void setX(double X){center_[0]=X;}
    void setY(double Y){center_[1]=Y;}
    void setZ(double Z){center_[2]=Z;}
    void setRadius(double radius){radius_=radius;}
    void setSpeed(double speed){speed_=speed;}
};
#endif // BALL_H
