#ifndef BALL_H
#define BALL_H
#include <QString>

class Ball
{
private:
    double radius_;
    double center_[3];//Juste 2 coordonnées correspond à un z fixe
    double speed_;
    double directionX_;// vaut -1 ou 1
    double directionY_;// vaut -1 ou 1
    double directionZ_;// vaut -1 ou 1
    QString state_;

public:
    Ball();
    Ball(double radius,double x,double y,double z,double speed);
    void reinitialiser(double x,double y,double z);
    double getRadius(){return radius_;}
    double getspeed(){return speed_;}
    double getX(){return center_[0];}
    double getY(){return center_[1];}
    double getZ(){return center_[2];}
    QString getState(){return state_;}
    void setState(QString change){state_=change;}
    double *getDirection();
    double getDirectionX(){return directionX_;}
    double getDirectionY(){return directionY_;}
    double getDirectionZ(){return directionZ_;}
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
