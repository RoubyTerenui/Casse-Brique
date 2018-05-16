#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public://(juste width height on suppose la profondeur constante on ne la précisera donc pas)
    double center_[3];
    double width_;
    double height_;
    double score;
    int life_;
public:
    Square();
    Square(double width,double height,double X,double Y,double Z,int life);
    double getX(){return center_[0];}
    double getY(){return center_[1];}
    double getZ(){return center_[2];}
    double getScore(){return score;}
    double getWidth(){return width_;}
    double getHeight(){return height_;}
    int getLife(){return life_;}
    void setLife(int life){ life_=life;}
    void setX(double X){center_[0]=X;}
    void setY(double Y){center_[1]=Y;}
    void setZ(double Z){center_[2]=Z;}
    void setWidth(double width){width_=width;}
};

#endif // SQUARE_H
