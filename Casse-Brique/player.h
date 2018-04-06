#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    int lifePoint_;
    int score_;
public:
    Player();
    int getLifePoint(){return(lifePoint_);}
    int getScore(){return(score_);}
    void setScore(int score){score_=score;}
    void setLifePoint(int LifePoint){lifePoint_=LifePoint;}
};

#endif // PLAYER_H
