#include "gamemanager.h"
#include <QDebug>
GameManager::GameManager()//Constructeur par défaut de la classe
{
    nbwin_=4;
    for (int i=0;i<10;i++){
        for (int j=0;j<7;j++){//7 lignes de bricks maximum
            int viebrick=rand()%(2+nbwin_);//Pour le niveau 1 les points de vies sont entre 0 et 1
            listbricks_[i*7+j]=Square(9,3,-40.5+(i)*9,17.2-(j)*3,-50,viebrick);//Rapport 1/3 Hauteur/Largeur
        }
    }
    stick_=Palette(9,1.25,0,-18,55,0);//Palette par défaut de taille 9 d'épaisseur.Situé au milieu de l'axe X
    bille_=Ball(0.6,0,-18+1.225,55,1);// Rayon 0.6 positionné au centre de la palette
    player=Player();//Nouveau Joueur
    state_=QString("In_Game");//Début d'une partie

}

void GameManager::reinitialiserBricks(){

    for (int i=0;i<10;i++){
        for (int j=0;j<7;j++){
            int viebrick=0;
            if (nbwin_<=5)
            {
                viebrick=rand()%(nbwin_+2);//Vie des bricks dépendant du nombre de victoire
            }
            else
            {
                viebrick=rand()%6;//à 4 le nombre de points de vie des bricks ne change plus
            }
            //Rajoute la Brick à la liste des 70 Bricks du jeu
            listbricks_[i*7+j]=Square(9,3,-40.5+(i)*9,17.2-(j)*3,55,viebrick);
        }
    }

}

void GameManager::updateBille_Score()//Position de la Bille et Direction et update de la vie des bricks
{
    // Collision avec les bricks

    QString statut=QString("untouched");
    for (int i=0;i<70;i++)
    {
        if(collisionBrick(listbricks_[i])!=0 && listbricks_[i].getLife()>0)
        {
            if (statut!=QString("touched"))
            {
                statut=QString("touched");//String permettant d'éviter de cumuler les changements de direction aprés détection d'une collision

                int direction=collisionBrick(listbricks_[i]);
                if (direction==1 || direction==2){//Horizontal
                    bille_.setDirectionY(bille_.getDirectionY()*(-1));
                }
                if (direction==3 || direction==4){//Vertical
                    bille_.setDirectionX(bille_.getDirectionX()*(-1));
                }
                if (direction==5 || direction==7){//Coins du bas // Lors de l'impact avec un coin renvoie à 45 degré dans le sens du coin
                    if (direction==5){
                        bille_.setDirectionX(-1/sqrt(2));
                    }
                    else{
                        bille_.setDirectionX(1/sqrt(2));
                    }
                    bille_.setDirectionY(-1/sqrt(2));
                }
                if (direction==6 || direction==8){// Coins du haut
                    if (direction==6){
                        bille_.setDirectionX(-1/sqrt(2));
                    }
                    else{
                        bille_.setDirectionX(1/sqrt(2));
                    }
                    bille_.setDirectionY(1/sqrt(2));
                }
            }
            listbricks_[i].setLife(listbricks_[i].getLife()-1);//update de la vie des bricks
            if (listbricks_[i].getLife()==0)
            {
                player.setScore(player.getScore()+listbricks_[i].getScore());
            }

        }
    }
    // Collision avec la palette
    if (collisionBrick(stick_)!=0){
        int direction=collisionBrick(stick_);
        if (direction==1 || direction==2){//Horizontal haut
            double position=searchPositionImpact(stick_);
            double res=2*(position-stick_.getX())/stick_.getWidth();
            double ang=(res*80);
            double angr=(ang*3.14)/180;
            bille_.setDirectionX(sin(angr));
            bille_.setDirectionY(fabs(cos(angr)));//Calcul de la direction dependant de la position ou l'impact à eu lieu sur la palette

        }
        if (direction==3 || direction==4){//Vertical gauche et droites
            bille_.setDirectionX(bille_.getDirectionX()*(-1));
        }
        if (direction >4){// Les coins
            if (direction==5 || direction==7){//Coins du bas // Lors de l'impact avec un coin renvoie à 45 degré dans le sens du coin
                if (direction==5){
                    bille_.setDirectionX(1/sqrt(2));
                }
                else{
                    bille_.setDirectionX(-1/sqrt(2));
                }
                bille_.setDirectionY(-1/sqrt(2));
            }
            if (direction==6 || direction==8){// Coins du haut
                if (direction==6){
                    bille_.setDirectionX(-1/sqrt(2));
                }
                else
                {
                    bille_.setDirectionX(1/sqrt(2));
                }
                bille_.setDirectionY(1/sqrt(2));
            }
        }
    }
    //Collision avec les murs
    if (collisionWall(45,1200,500)!=0){
        int direction=collisionWall(45,1200,500);
        if (direction==1){
            if(player.getLifePoint()>0){//Lors de l'arrivé sur le sol réinitialisation de la partie et soustraction d'un point de vie
                player.setLifePoint(player.getLifePoint()-1);
                bille_.reinitialiser(stick_.getX(),-18+1.225,55);
            }
            else{
                state_=QString("Game Over");
            }
        }
        if (direction==2){//Horizontal
            bille_.setDirectionY(bille_.getDirectionY()*(-1));
        }
        if (direction==3 || direction==4){//Vertical
            bille_.setDirectionX(bille_.getDirectionX()*(-1));
        }
        if (direction==5 || direction==7){//Coins du bas // Lors de l'impact avec un coin renvoie à 45 degré dans le sens du coin
            if (direction==5){
                bille_.setDirectionX(-1/sqrt(2));
            }
            else{
                bille_.setDirectionX(1/sqrt(2));
            }
            bille_.setDirectionY(-1/sqrt(2));
        }
        if (direction==6 || direction==8){// Coins du haut
            if (direction==5){
                bille_.setDirectionX(-1/sqrt(2));
            }
            else{
                bille_.setDirectionX(1/sqrt(2));
            }
            bille_.setDirectionY(1/sqrt(2));
        }
    }
    if (bille_.getState()==QString("unfixed"))//Mise à jour de la nouvelle position de la bille en fonction de ses attributs directionnelles
    {
        double newpositionX=bille_.getDirectionX()*bille_.getspeed()+bille_.getX();
        double newpositionY=bille_.getDirectionY()*bille_.getspeed()+bille_.getY();
        double newpositionZ=bille_.getDirectionZ()*bille_.getspeed()+bille_.getZ();
        bille_.setX(newpositionX);
        bille_.setY(newpositionY);
        bille_.setZ(newpositionZ);
    }

}

void GameManager::updatePositionPalette(){
    stick_.setX(stick_.getX()+stick_.getSpeed());
    if (bille_.getState()=="fixed"){
        bille_.setX(stick_.getX());
    }
}

void GameManager::updateNbWin()//Level sur lequel on se situe et comptage du nombre de victoire
{
    int i=0;
    bool cleared=true;
    while (i<70 && cleared==true){//Parcours de toute la liste de bricks pour tester si la partie est terminé
        if (listbricks_[i].getLife()>0){
            cleared=false;
        }
        else{
            i++;
        }
    }
    if (cleared){
        nbwin_+=1;
        bille_.setSpeed(bille_.getspeed()+0.1);
        reinitialiserBricks();
        bille_.reinitialiser(stick_.getX(),-18+1.225,55);
    }

}

bool GameManager::collisionPointCercle(double x,double y,Ball b){//Fonction testant la collision d'un point avec un cercle:sera utilisé pour les futurs calculs de collision
    double eq=(x-b.getX())*(x-b.getX())+(y-b.getY())*(y-b.getY());
    if (eq>b.getRadius()*b.getRadius()){
        return false;
    }
    else {
        return true;
    }
}

bool GameManager::collisionDroite(double aX, double aY,double bX,double bY, Ball C){//Fonction testant la collision d'un point avec une droite:sera utilisé pour les futurs calculs de collision
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

bool GameManager::collisionSegmentCercle(double aX, double aY,double bX,double bY, Ball C){//Fonction testant la collision d'un cercle avec un segment:utilise les 2 autres fonctions précédentes

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

double GameManager::searchPositionImpact(Palette brick)//Permet de détécter le point impacte selon X avec une brick
{
    double ecartgauche=brick.getX()-brick.getWidth()/2-bille_.getX();
    if(ecartgauche>=0){
        return(brick.getX()-brick.getWidth()/2);
    }
    else{
        if (ecartgauche<=-brick.getWidth()){
            return(brick.getX()+brick.getWidth()/2);
        }
        else{
            return(brick.getX()-brick.getWidth()/2-ecartgauche);
        }
    }
}

int GameManager::collisionBrick(Square brick)//Application des fonctions de collisions définies aux bricks
{
    int zoneImpact=0;
    if (bille_.getState()==QString("fixed"))
    {    }
    else{
        double  H = brick.getHeight()/2;
        double W = brick.getWidth()/2;
        //4 Coordonnées pour definir les bords
        double Gx = brick.getX()-W;//Gauche sur l'axe X
        double Dx = brick.getX()+W;//Droite sur l'axe X
        double By=brick.getY()-H;//Bas sur l'axe Y
        double Hy=brick.getY()+H;//Haut sur l'axe Y


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

int GameManager::collisionWall(double dimensionMax,double width,double height)// Application des fonctions de collisions définies précédement aux murs
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
