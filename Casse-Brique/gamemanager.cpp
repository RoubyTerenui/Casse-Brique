#include "gamemanager.h"
GameManager::GameManager()
{
    for (int i=0;i<10;i++){
        for (int j=0;j<12;j++){
            listbricks_[i*12+j]=Square(10,2,-50+(i)*10.5+2.5,30-(j)*2.5,55,1);
        }
    }
    stick_=Palette(12,1.25,0,-25,55,5);
    bille_=Ball(0.725,0,-23.6,55,0.1);
    player=Player();
    nbwin=0;
    state_=QString("In_Game");

}


void GameManager::updateBille_Score()//Position de la Bille et Direction et update de la vie des bricks
{

    QString statut=QString("untouched");
    for (int i=0;i<120;i++)
    {
        if(collisionBrick(listbricks_[i])!=0 && listbricks_[i].getLife()>0)
        {
            if (statut!=QString("touched"))
            {
                statut=QString("touched");

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
            }
            listbricks_[i].setLife(listbricks_[i].getLife()-1);//update de la vie des bricks
            if (listbricks_[i].getLife()==0)
            {
                player.setScore(player.getScore()+listbricks_[i].getScore());
            }

        }
    }
    if (collisionBrick(stick_)!=0){
        int direction=collisionBrick(stick_);
        if (direction==1 || direction==2){//Horizontal haut uniquement
            bille_.setDirectionY(bille_.getDirectionY()*(-1));
        }
        if (direction==3 || direction==4){//Vertical gauche et droites
            bille_.setDirectionX(bille_.getDirectionX()*(-1));
        }
        if (direction >4){// Les coins
            bille_.setDirectionX(bille_.getDirectionX()*(-1));
            bille_.setDirectionY(bille_.getDirectionY()*(-1));
        }
    }
    if (collisionWall(55,1600,900)!=0){
        int direction=collisionWall(55,1600,900);
        if (direction==1){
            if(player.getLifePoint()>0){
                player.setLifePoint(player.getLifePoint()-1);
                bille_.reinitialiser(stick_.getX(),-23.6,55);
            }
            else{//TO DO Faire un écran Game over
                state_=QString("Game Over");
            }
        }
        if (direction==2){//Horizontal
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
    if (bille_.getState()==QString("unfixed"))
    {
        double newpositionX=bille_.getDirectionX()*bille_.getspeed()+bille_.getX();
        double newpositionY=bille_.getDirectionY()*bille_.getspeed()+bille_.getY();
        double newpositionZ=bille_.getDirectionZ()*bille_.getspeed()+bille_.getZ();
        bille_.setX(newpositionX);
        bille_.setY(newpositionY);
        bille_.setZ(newpositionZ);
    }

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

bool GameManager::collisionPointCercle(double x,double y,Ball b){//TO DO résoudre les problemes présent avec les collisions
    double eq=(x-b.getX())*(x-b.getX())+(y-b.getY())*(y-b.getY());
    if (eq>b.getRadius()*b.getRadius()){
        return false;
    }
    else {
        return true;
    }
}

bool GameManager::collisionDroite(double aX, double aY,double bX,double bY, Ball C){
    double ux=bX-aX;
    double uy=bY-aY;
    double ACx=C.getX()-aX;
    double ACy=C.getY()-aY;
    float numerateur=ux*ACy-uy*ACx;
    if (numerateur<0){
        numerateur=-numerateur;
    }
    float denominateur=sqrt(ux*ux+uy*uy);
    float CI=numerateur/denominateur;
    if (CI<C.getRadius())
    {
        return true;
    }
    else {
        return false;
    }
}

bool GameManager::collisionSegmentCercle(double aX, double aY,double bX,double bY, Ball C){

    if (collisionDroite(aX,aY,bX,bY,C)==false){
        return false; // Si on ne touche pas la droite on ne touchera pas le segment
    }
    double ABx=bX-aX;
    double ABy=bY-aY;
    double ACx=C.getX()-aX;
    double ACy=C.getY()-aY;
    double BCx=C.getX()-bX;
    double BCy=C.getY()-bY;
    float pdscal1=ABx*ACx+ABy*ACy;
    float pdscal2=(-ABx)*BCx+(-ABy)*BCy;
    if (pdscal1>=0 && pdscal2>=0){
        return true;// I entre A et B
    }
    if (collisionPointCercle(aX,aY,C))
    {
        return true;
    }
    if (collisionPointCercle(bX,bY,C)){
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
        //4 Coordonnées pour definir les bords
        double Gx = brick.center_[0]-W;//Gauche sur l'axe X
        double Dx = brick.center_[0]+W;//Droite sur l'axe X
        double By=brick.center_[1]-H;//Bas sur l'axe Y
        double Hy=brick.center_[1]+H;//Haut sur l'axe Y


        //On test d'abord le bas
        if (collisionSegmentCercle(Gx,By,Dx,By,bille_)){
            zoneImpact=1;
        }
        // Et le haut
        if (collisionSegmentCercle(Gx,Hy,Dx,Hy,bille_)){
            zoneImpact=2;
        }
        //Puis on s'occupe des cotés et des coins
        if (collisionSegmentCercle(Gx,Hy,Gx,By,bille_)){
            if(zoneImpact==0){
                zoneImpact=3;
            }
            else{
                zoneImpact+=4;
            }
        }
        if (collisionSegmentCercle(Dx,Hy,Dx,By,bille_)){
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
int GameManager::collisionWall(double dimensionMax,double width,double height)//TO DO Trouver un moyen pour que les bords Réels de la widget s'adapte avec les niveaux
{
    int zoneImpact=0;
    if (bille_.getState()==QString("fixed"))
    {    }
    else{
        //4 Coordonnées pour definir les bords(on pourrait en definir que 2 mais pour la clarté du code on en gardera 4)
        double Gx = -dimensionMax;//Gauche sur l'axe X
        double Dx = dimensionMax;//Droite sur l'axe X
        double By=-dimensionMax * height / width;//Bas sur l'axe Y
        double Hy= dimensionMax * height / width;//Haut sur l'axe Y
        //On test d'abord le bas
        if (collisionSegmentCercle(Gx,By,Dx,By,bille_)){
            zoneImpact=1;
        }
        // Et le haut
        if (collisionSegmentCercle(Gx,Hy,Dx,Hy,bille_)){
            zoneImpact=2;
        }
        //Puis on s'occupe des cotés et des coins
        if (collisionSegmentCercle(Gx,Hy,Gx,By,bille_)){
            if(zoneImpact==0){
                zoneImpact=3;
            }
            else{
                zoneImpact+=4;
            }
        }
        if (collisionSegmentCercle(Dx,Hy,Dx,By,bille_)){
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



