#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public://(juste width height on suppose la profondeur constante on ne la précisera donc pas)
    double center_[3];
    double width_;
    double height_;
public:
    Square();
    Square(double width,double height,double X,double Y,double Z);
    double getX(){return center_[0];}
    double getY(){return center_[1];}
    double getZ(){return center_[2];}
    double getWidth(){return width_;}
    double getHeight(){return height_;}
    void setX(double X){center_[0]=X;}
    void setY(double Y){center_[1]=Y;}
    void setZ(double Z){center_[2]=Z;}
};

#endif // SQUARE_H
