#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "ball.h"
#include "square.h"
#include "palette.h"
#include "player.h"
class GameManager
{
public:
    Ball bille_;
    Square listbricks_[120];
    Palette stick_;
    Player player;
    int nbwin;

public:
    GameManager();
    int collisionBrick();//Renvoie un entier entre 0 et 8indiquant la collision avec une brick et met à jour sa vie
    int collisionWall();//Renvoie un entier entre 0 et 6 indiquant la collision avec les bords du plateau
    int collisionStick();// Renvoie vrai ou faux
    void updateListBricks_Score();//Elements de la liste Score
    void updateBille();//Position de la Bille et Direction
    void updateStick();//Position du palet
    void updateLife();//Nbre de Point de vie
    void updateNbWin();//Level sur lequel on se situe et comptage du nombre de victoire
};

#endif // GAMEMANAGER_H
