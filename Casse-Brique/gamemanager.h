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
    Square listbricks_[120];
    Palette stick_;
    Player player;
    int nbwin;
private:
    bool collisionPointCercle(double x,double y,Ball b);
    bool collisionDroite(QPoint A,QPoint B,Ball C);
    bool collisionSegmentCercle(QPoint A,QPoint B,Ball C);
public:
    GameManager();
    int collisionBrick(Square brick);//Renvoie un entier entre 0 et 8 indiquant la collision avec une brick et met à jour sa vie
    int collisionWall();//Renvoie un entier entre 0 et 6 indiquant la collision avec les bords du plateau
    void updateListBricks_Score();//Elements de la liste Score
    void updateBille();//Position de la Bille et Direction
    void updateStick();//Position du palet
    void updateLife();//Nbre de Point de vie
    void updateNbWin();//Level sur lequel on se situe et comptage du nombre de victoire
};

#endif // GAMEMANAGER_H
