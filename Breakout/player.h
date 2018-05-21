#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <string>

using namespace std;

class Player
{
private:
    string nom_;
    int lifePoint_;
    int score_;
    int nbwin_;
public:
    Player();
    Player(const Player &p);
    int getLifePoint(){return(lifePoint_);}
    int getScore(){return(score_);}
    void setScore(int score){score_=score;}
    void setLifePoint(int LifePoint){lifePoint_=LifePoint;}
    void setNbWin(int nb){nbwin_=nb;}
    void setName(string name){nom_=name;}
    string getName(){return nom_;}
    int getNbWin(){return(nbwin_);}
    void charger(ifstream &is);
    void sauver(ofstream &os);
    bool operator <(const Player &p)const;

};

#endif // PLAYER_H
