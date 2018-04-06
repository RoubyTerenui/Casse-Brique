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
};

#endif // GAMEMANAGER_H
