#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "ball.h"
#include "square.h"
#include "palette.h"
#include "player.h"
#include <QPoint>

class GameManager
{
public:
    Ball bille_;
    Square listbricks_[70];// Liste avec pour taille le nombre de lignes de bricks maximum *10
    Palette stick_;
    Player player;
    QString state_;
    int nbwin_;
private:
    bool collisionPointCercle(double x,double y,Ball b);
    bool collisionDroite(double aX,double aY,double bX,double bY,Ball C);
    bool collisionSegmentCercle(double aX,double aY,double bX,double bY,Ball C);
public:
    GameManager();
    void reinitialiserBricks();
    void initializeNbWin(){nbwin_=0;}
    int collisionBrick(Square brick);//Renvoie un entier entre 0 et 8 indiquant la collision avec une brick et met à jour sa vie
    int collisionWall(double dimensionMax,double width,double height);//Renvoie un entier entre 0 et 8 indiquant la collision avec les bords du plateau
    void updateBille_Score();//Position de la Bille et Direction/Vie des briques et scores
    void updateNbWin();//Level sur lequel on se situe et comptage du nombre de victoire
    double searchPositionImpact(Square brick);
};

#endif // GAMEMANAGER_H
