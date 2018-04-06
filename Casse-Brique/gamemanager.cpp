#include "gamemanager.h"

GameManager::GameManager()
{
    for (int i=0;i<10;i++){
        for (int j=0;j<12;j++){
            listbricks_[i*12+j]=Square(10,2,-50+(i)*10.5+2.5,25-(j)*2.5,55);//To DO redefinir la taille des bricks et du palet et de la bille
        }
    }
    stick_=Palette(12,1.25,0,-25,55,5);
    bille_=Ball(0.75,0,-23.675,55,10);//(0.75 correspond au rayon on positionne à l'initialisation la balle sur la palette donc en (0 et en 25+rayon Bille +epaisseur palette/2)en y et sur le même plan en Z
    player=Player();
    nbwin=0;

}
