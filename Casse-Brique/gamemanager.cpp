#include "gamemanager.h"
//double equationcercle=sqrt();
GameManager::GameManager()
{
    for (int i=0;i<10;i++){
        for (int j=0;j<12;j++){
            listbricks_[i*12+j]=Square(10,2,-50+(i)*10.5+2.5,30-(j)*2.5,55,1);//To DO redefinir la taille des bricks et du palet et de la bille
        }
    }
    stick_=Palette(12,1.25,0,-25,55,5);
    bille_=Ball(0.75,0,-23.675,55,0.1);//(0.75 correspond au rayon on positionne à l'initialisation la balle sur la palette donc en (0 et en 25+rayon Bille +epaisseur palette/2)en y et sur le même plan en Z
    player=Player();
    nbwin=0;

}

void GameManager::updateListBricks_Score()//Elements de la liste Score
{
//    if (bille_.getState()==QString("fixed"))
//    {
//        return 0;
//    }
//    else
//    {
//        if()
//        {

//        }

//    }
}
void GameManager::updateBille()//Position de la Bille et Direction
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else
    {

    }
}

void GameManager::updateStick()//Position du palet
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else
    {

    }
}
void GameManager::updateLife()//Nbre de Point de vie
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else
    {

    }

}
void GameManager::updateNbWin()//Level sur lequel on se situe et comptage du nombre de victoire
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else
    {

    }
}

int GameManager::collisionBrick(Square brick)
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else{
        double  H = brick.height_/2;
        double W = brick.width_/2;
        QPoint BG = QPoint(brick.center_[0]-W,brick.center_[1]-H);
        QPoint BD = QPoint(brick.center_[0]+W,brick.center_[1]-H);
        QPoint HG = QPoint(brick.center_[0]-W,brick.center_[1]+H);
        QPoint HD = QPoint(brick.center_[0]+W,brick.center_[1]+H);
    }

}
int GameManager::collisionWall()
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else
    {

    }
}

int GameManager::collisionStick()
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else
    {

    }
}

