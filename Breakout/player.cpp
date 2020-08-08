#include "player.h"
#include <QString>
#include <fstream>
using namespace std;

Player::Player()
{
    lifePoint_=3;
    score_=0;
    nom_="unknown";
    nbwin_=0;
}

Player::Player(const Player &p){
    lifePoint_=p.lifePoint_;
    score_=p.score_;
    nom_=p.nom_;
    nbwin_=p.nbwin_;
}

void Player::charger(ifstream &is)
{
    string score;
    string nbWin;
    getline(is,nom_,';');
    getline(is,score,';');
    getline(is,nbWin);
    score_=stoi(score);
    nbwin_=stoi(nbWin);

}

void Player::sauver(ofstream &os)
{
    os<<nom_<<";"<<QString::number(score_).toStdString()<<";"<<QString::number(nbwin_).toStdString()<<endl;
}

//Permet d'effectuer le trie de listPlayer
bool Player::operator <(const Player &p)const{
    if (this->score_<p.score_)
    {
        return true;
    }
    else{
        if(this->score_==p.score_){
            if (this->nbwin_<p.nbwin_)
            {
                return true;
            }
            else{
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}

