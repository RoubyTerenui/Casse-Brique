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
    bille_=Ball(0.75,0,-23,55,0.1);//(0.75 correspond au rayon on positionne à l'initialisation la balle sur la palette donc en (0 et en 25+rayon Bille +epaisseur palette/2)en y et sur le même plan en Z
    player=Player();
    nbwin=0;

}


void GameManager::updateBille_Score()//Position de la Bille et Direction et update de la vie des bricks
{
    for (int i=0;i<120;i++ && listbricks_[i].getLife()>0){
        if(collisionBrick(listbricks_[i])!=0)
        {
            int direction=collisionBrick(listbricks_[i]);
            if (direction==1 || direction==2){//Horizontal
                bille_.setDirectionY(bille_.getDirectionY()*(-1));
            }
            if (direction==3 || direction==4){//Vertical
                bille_.setDirectionX(bille_.getDirectionX()*(-1));
            }
            if (direction >4){//Coins
                bille_.setDirectionX(bille_.getDirectionX()*(-1));
                bille_.setDirectionY(bille_.getDirectionY()*(-1));
            }
            listbricks_[i].setLife(listbricks_[i].getLife()-1);//update de la vie des bricks
            if (listbricks_[i].getLife()==0){
                player.setScore(player.getScore()+listbricks_[i].getScore());
            }
        }
    }
    if (collisionBrick(stick_)!=0){// Creation d'une fonction pour rendre le code plus propre?
        int direction=collisionBrick(stick_);
        if (direction==1 || direction==2){//Horizontal
            bille_.setDirectionY(bille_.getDirectionY()*(-1));
        }
        if (direction==3 || direction==4){//Vertical
            bille_.setDirectionX(bille_.getDirectionX()*(-1));
        }
        if (direction >4){//Coins
            bille_.setDirectionX(bille_.getDirectionX()*(-1));
            bille_.setDirectionY(bille_.getDirectionY()*(-1));
        }
    }

}

void GameManager::updateStick()//Position du palet
{

}
void GameManager::updateLife()//Nbre de Point de vie
{


}
void GameManager::updateNbWin()//Level sur lequel on se situe et comptage du nombre de victoire
{
    int i=0;
    bool cleared=true;
    while (i<120 && cleared==true){
        if (listbricks_[i].getLife()>0){
            cleared=false;
        }
        else{
            i++;
        }
    }
    if (cleared){
        nbwin+=1;
        bille_.setSpeed(bille_.getspeed()+0.05);
    }

}

bool GameManager::collisionPointCercle(double x,double y,Ball b){
    double eq=(x-b.getX())*(x-b.getX())+(y-b.getY())*(y-b.getY());
    if (eq>b.getRadius()*b.getRadius()){
        return false;
    }
    else {
        return true;
    }
}

bool GameManager::collisionDroite(QPoint A, QPoint B, Ball C){
    QPoint u;
    u.setX(B.x()-A.x());
    u.setY(B.y()-A.y());
    QPoint AC;
    AC.setX(C.getX()-A.x());
    AC.setY(C.getY()-A.y());
    float numerateur=u.x()*AC.y()-u.y()*AC.x();
    if (numerateur<0){
        numerateur=-numerateur;
    }
    float denominateur=sqrt(u.x()*u.x()+u.y()*u.y());
    float CI=numerateur/denominateur;
    if (CI<C.getRadius())
    {
        return true;
    }
    else {
        return false;
    }
}

bool GameManager::collisionSegmentCercle(QPoint A, QPoint B, Ball C){

    if (collisionDroite(A,B,C)==false){
        return false; // Si on ne touche pas la droite on ne touchera pas le segment
    }
    QPoint AB,AC,BC;
    AB.setX(B.x()-A.x());
    AB.setY(B.y()-A.y());
    AC.setX(C.getX()-A.x());
    AC.setY(C.getY()-A.y());
    BC.setX(C.getX()-B.x());
    BC.setY(C.getY()-B.y());
    float pdscal1=AB.x()*AC.x()+AB.y()*AC.y();
    float pdscal2=(-AB.x())*BC.x()+(-AB.y())*BC.y();
    if (pdscal1>=0 && pdscal2>=0){
        return true;// I entre A et B
    }
    if (collisionPointCercle(A.x(),A.y(),C))
    {
        return true;
    }
    if (collisionPointCercle(B.x(),B.y(),C)){
        return true;
    }
    return false;
}

int GameManager::collisionBrick(Square brick)
{
    int zoneImpact=0;
    if (bille_.getState()==QString("fixed"))
    {    }
    else{
        double  H = brick.height_/2;
        double W = brick.width_/2;
        QPoint BG = QPoint(brick.center_[0]-W,brick.center_[1]-H);//Point en bas à gauche
        QPoint BD = QPoint(brick.center_[0]+W,brick.center_[1]-H);//Point en bas à droite
        QPoint HG = QPoint(brick.center_[0]-W,brick.center_[1]+H);//Point en haut à gauche
        QPoint HD = QPoint(brick.center_[0]+W,brick.center_[1]+H);//Point en haut à droite

        //On test d'abord le bas
        if (collisionSegmentCercle(BG,BD,bille_)){
            zoneImpact=1;
        }
        // Et le haut
        if (collisionSegmentCercle(HG,HD,bille_)){
            zoneImpact=2;
        }
        //Puis on s'occupe des cotés et des coins
        if (collisionSegmentCercle(HG,BG,bille_)){
            if(zoneImpact==0){
                zoneImpact=3;
            }
            else{
                zoneImpact+=4;
            }
        }
        if (collisionSegmentCercle(HD,BD,bille_)){
            if(zoneImpact==0){
                zoneImpact=4;
            }
            else{
                zoneImpact+=6;
            }
        }
    }
    return zoneImpact;

}
int GameManager::collisionWall()//TODO trouver les bords Réels de la widget
{
    if (bille_.getState()==QString("fixed"))
    {

    }
    else
    {

    }
}



