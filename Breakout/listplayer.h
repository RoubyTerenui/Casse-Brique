#ifndef LISTPLAYER_H
#define LISTPLAYER_H

#include<list>
#include<fstream>
#include <player.h>


class ListPlayer : public list<Player>
{
public:
    ListPlayer();
    void charger(std::ifstream &is);
    void sauver(std::ofstream &os);
    void triList();
};

#endif // LISTPLAYER_H
