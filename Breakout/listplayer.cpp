#include "listplayer.h"
#include <list>
#include<fstream>
#include<iostream>
ListPlayer::ListPlayer()
{

}


void ListPlayer::charger(ifstream &is)
{
    int n;
    clear();
    is>>n;
    is.ignore();
    for (int i=0;i<n;i++)
    {
        Player a;
        a.charger(is);
        push_back(a);
    }
}

void ListPlayer::sauver(ofstream &os)
{
    os<<size()<<endl;
    for (iterator it=begin();it!=end();it++) {
        it->sauver(os);
    }

}

void ListPlayer::triList() {

    sort();
    this->reverse();
    if (this->size()>10){
        this->pop_back();
    }
}
