#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>
#include <QTimer>
#include <gamemanager.h>
#include <QDebug>
#include <math.h>

// Declaration des constantes
const unsigned int WIN_WIDTH  = 1200;
const unsigned int WIN_HEIGHT = 500;
const float MAX_DIMENSION     = 45.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    this->setMouseTracking(true);
    game=GameManager();

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    // Activation des textures
    glEnable(GL_TEXTURE_2D);


    // Chargement des images
    QImage Background1 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 1.jpg"));
    QImage Background2 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 2.jpg"));
    QImage Background3 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 3.jpg"));
    QImage Background4 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 4.jpg"));
    QImage Background5 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 5.jpg"));
    QImage BackgroundGO = QGLWidget::convertToGLFormat(QImage(":/Images/GameOver.jpg"));

    QImage paletteT = QGLWidget::convertToGLFormat(QImage(":/Images/palette.jpg"));
    QImage billeT = QGLWidget::convertToGLFormat(QImage(":/Images/lune.jpg"));

    QImage bricka1 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick a1.jpg"));

    QImage brickb1 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick b1.jpg"));
    QImage brickb2 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick b2.jpg"));

    QImage brickc1 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick c1.jpg"));
    QImage brickc2 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick c2.jpg"));
    QImage brickc3 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick c3.jpg"));

    QImage brickd1 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick d1.jpg"));
    QImage brickd2 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick d2.jpg"));
    QImage brickd3 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick d3.jpg"));
    QImage brickd4 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick d4.jpg"));

    QImage bricke1 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick e1.jpg"));
    QImage bricke2 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick e2.jpg"));
    QImage bricke3 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick e3.jpg"));
    QImage bricke4 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick e4.jpg"));
    QImage bricke5 = QGLWidget::convertToGLFormat(QImage(":/Images/Brick e5.jpg"));


    // Application des textures
    glGenTextures(23, tab_text);


    glBindTexture(GL_TEXTURE_2D, tab_text[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, Background1.width(), Background1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Background1.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[1]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, Background2.width(), Background2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Background2.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[2]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, Background3.width(), Background3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Background3.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[3]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, Background4.width(), Background4.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Background4.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[4]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, Background5.width(), Background5.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Background5.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[5]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, paletteT.width(), paletteT.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, paletteT.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[6]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, billeT.width(), billeT.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, billeT.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[7]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, bricka1.width(), bricka1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bricka1.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[8]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickb1.width(), brickb1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickb1.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[9]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickb2.width(), brickb2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickb2.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[10]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickc1.width(), brickc1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickc1.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[11]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickc2.width(), brickc2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickc2.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[12]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickc3.width(), brickc3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickc3.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[13]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickd1.width(), brickd1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickd1.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[14]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickd2.width(), brickd2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickd2.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[15]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickd3.width(), brickd3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickd3.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[16]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickd4.width(), brickd4.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickd4.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[17]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, bricke1.width(), bricke1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bricke1.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[18]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, bricke2.width(), bricke2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bricke2.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[19]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, bricke3.width(), bricke3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bricke3.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[20]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, bricke4.width(), bricke4.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bricke4.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[21]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, bricke5.width(), bricke5.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bricke5.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[22]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, BackgroundGO.width(), BackgroundGO.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, BackgroundGO.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height); // On définit l'origine aux coordonnées (0,0) avec la largeur et la hauteur de la fenêtre par défaut

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width != 0)
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width)+(MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH), MAX_DIMENSION * height / static_cast<float>(width)+(MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH), -MAX_DIMENSION * 2.0f, MAX_DIMENSION);
    // Centre de l'image (0,0)

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-MAX_DIMENSION, MAX_DIMENSION,-MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f+(MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH));

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,0,50,0,0,0,0,1,0);//On se positionne on -50 (sur z)
    // Nettoyage
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Effacer le buffer de couleur

    if(game.getState()!="Game Over")
    {
        glBindTexture(GL_TEXTURE_2D, tab_text[game.getNbWin() % 5]);

        // Affichage du cube du background
        glBegin(GL_QUADS);
        glTexCoord2d(0,0); glVertex3f(MAX_DIMENSION,MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glTexCoord2d(1,0); glVertex3f(-MAX_DIMENSION, MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glTexCoord2d(1,1); glVertex3f(-MAX_DIMENSION, -MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glTexCoord2d(0,1); glVertex3f(MAX_DIMENSION, -MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glEnd();



        glClear(GL_DEPTH_BUFFER_BIT);



        //Affichage du texte
        this->renderText(-MAX_DIMENSION+0.5,MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH-1,-20,"life Point : " +QString::number(game.getPlayer().getLifePoint()),QFont());
        this->renderText(-MAX_DIMENSION+0.5,MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH-2,-20,"score : "+QString::number(game.getPlayer().getScore()),QFont());
        this->renderText(-MAX_DIMENSION+0.5,MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH-3,-20,"Level : " +QString::number(game.getNbWin()+1),QFont());



        // Affichage du terrain de la partie initiale
        for (int i=0;i<70;i++){
            if (game.getBrickI(i).getLife()>0)
            {
                dessineCube(game.getBrickI(i).getX(),game.getBrickI(i).getY(),game.getBrickI(i).getZ(),game.getBrickI(i).getWidth(),game.getBrickI(i).getHeight(),game.getBrickI(i).getScore(),game.getBrickI(i).getLife());
            }
        }
        dessineCube(game.getStick().getX(),game.getStick().getY(),game.getStick().getZ(),game.getStick().getWidth(),game.getStick().getHeight(),0,0);
        drawBall();
    }
    else{
        glBindTexture(GL_TEXTURE_2D, tab_text[22]);

        // Affichage du cube du background
        glBegin(GL_QUADS);
        glTexCoord2d(1,1); glVertex3f(MAX_DIMENSION,MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glTexCoord2d(0,1); glVertex3f(-MAX_DIMENSION, MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glTexCoord2d(0,0); glVertex3f(-MAX_DIMENSION, -MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glTexCoord2d(1,0); glVertex3f(MAX_DIMENSION, -MAX_DIMENSION*WIN_HEIGHT/WIN_WIDTH, -20.0f);
        glEnd();

        //Affichage du texte
        this->renderText(-3,10,-20,"life Point : " +QString::number(game.getPlayer().getLifePoint()),QFont());
        this->renderText(-3,11,-20,"score : "+QString::number(game.getPlayer().getScore()),QFont());
        this->renderText(-3,12,-20,"Level : " +QString::number(game.getNbWin()+1),QFont());


    }

}

void MyGLWidget::dessineCube(double centerX,double centerY,double centerZ,double width,double height,int lpTot,int lp){// Dessin des bricks

    switch (lpTot) {

    case 0 :
        glBindTexture(GL_TEXTURE_2D, tab_text[5]);
        break;

    case 1 :
        glBindTexture(GL_TEXTURE_2D, tab_text[7]);
        break;

    case 2 :
        switch (lp) {
        case 2 :
            glBindTexture(GL_TEXTURE_2D, tab_text[8]);
            break;
        case 1 :
            glBindTexture(GL_TEXTURE_2D, tab_text[9]);
            break; }
        break;

    case 3 :
        switch (lp) {
        case 3 :
            glBindTexture(GL_TEXTURE_2D, tab_text[10]);
            break;
        case 2 :
            glBindTexture(GL_TEXTURE_2D, tab_text[11]);
            break;
        case 1 :
            glBindTexture(GL_TEXTURE_2D, tab_text[12]);
            break; }
        break;

    case 4 :
        switch (lp) {
        case 4 :
            glBindTexture(GL_TEXTURE_2D, tab_text[13]);
            break;
        case 3 :
            glBindTexture(GL_TEXTURE_2D, tab_text[14]);
            break;
        case 2 :
            glBindTexture(GL_TEXTURE_2D, tab_text[15]);
            break;
        case 1 :
            glBindTexture(GL_TEXTURE_2D, tab_text[16]);
            break; }
        break;

    case 5 :
        switch (lp) {
        case 5 :
            glBindTexture(GL_TEXTURE_2D, tab_text[17]);
            break;
        case 4 :
            glBindTexture(GL_TEXTURE_2D, tab_text[18]);
            break;
        case 3 :
            glBindTexture(GL_TEXTURE_2D, tab_text[19]);
            break;
        case 2 :
            glBindTexture(GL_TEXTURE_2D, tab_text[20]);
            break;
        case 1 :
            glBindTexture(GL_TEXTURE_2D, tab_text[21]);
            break; }
        break;
    }

    glBegin(GL_QUADS);

    // Face arrière
    glTexCoord2d(0,0);glVertex3f(centerX+width/2, centerY+height/2,centerZ - 1.25f);
    glTexCoord2d(1,0); glVertex3f( centerX+width/2, centerY-height/2,centerZ - 1.25f);
    glTexCoord2d(1,1); glVertex3f(centerX-width/2, centerY-height/2,centerZ - 1.25f);
    glTexCoord2d(0,1); glVertex3f(centerX-width/2, centerY+height/2,centerZ - 1.25);

    // Face avant
    glTexCoord2d(1,1);glVertex3f(centerX+width/2, centerY+height/2,centerZ + 1.25f);
    glTexCoord2d(1,0);glVertex3f( centerX+width/2, centerY-height/2,centerZ + 1.25f);
    glTexCoord2d(0,0);glVertex3f(centerX-width/2, centerY-height/2,centerZ + 1.25f);
    glTexCoord2d(0,1);glVertex3f(centerX-width/2, centerY+height/2,centerZ + 1.25);
    //Face dessous
    glTexCoord2d(0,0);glVertex3f(centerX+width/2, centerY+height/2,centerZ + 1.25f);
    glTexCoord2d(1,0);glVertex3f( centerX+width/2, centerY+height/2,centerZ- 1.25f);
    glTexCoord2d(1,1);glVertex3f(centerX-width/2, centerY+height/2,centerZ - 1.25f);
    glTexCoord2d(0,1);glVertex3f(centerX-width/2, centerY+height/2,centerZ + 1.25);
    //Face dessus
    glTexCoord2d(0,0);glVertex3f(centerX+width/2, centerY-height/2,centerZ + 1.25f);
    glTexCoord2d(1,0);glVertex3f( centerX+width/2, centerY-height/2,centerZ- 1.25f);
    glTexCoord2d(1,1);glVertex3f(centerX-width/2, centerY-height/2,centerZ - 1.25f);
    glTexCoord2d(0,1);glVertex3f(centerX-width/2, centerY-height/2,centerZ + 1.25);
    //Faces coté gauche et droite
    glTexCoord2d(0,0);glVertex3f(centerX-width/2, centerY+height/2,centerZ + 1.25f);
    glTexCoord2d(1,0);glVertex3f( centerX-width/2, centerY-height/2,centerZ+ 1.25f);
    glTexCoord2d(1,1);glVertex3f(centerX-width/2, centerY-height/2,centerZ - 1.25f);
    glTexCoord2d(0,1);glVertex3f(centerX-width/2, centerY+height/2,centerZ - 1.25);

    glTexCoord2d(0,0);glVertex3f(centerX+width/2, centerY-height/2,centerZ + 1.25f);
    glTexCoord2d(1,0);glVertex3f( centerX+width/2, centerY-height/2,centerZ- 1.25f);
    glTexCoord2d(1,1);glVertex3f(centerX+width/2, centerY+height/2,centerZ - 1.25f);
    glTexCoord2d(0,1);glVertex3f(centerX+width/2, centerY+height/2,centerZ + 1.25);

    glEnd();

}


void MyGLWidget::drawBall(){//Dessin de la bille

    glEnable(GL_FRONT);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, tab_text[6]);
    GLUquadric* quadrique2=gluNewQuadric();
    gluQuadricDrawStyle(quadrique2, GLU_LINE);
    gluQuadricNormals(quadrique2, GLU_SMOOTH);
    gluQuadricTexture(quadrique2,GL_TRUE);
    glTranslatef(game.getBille().getX(),game.getBille().getY(),game.getBille().getZ());
    gluSphere(quadrique2, game.getBille().getRadius(), 20, 50);//Definition du Rayon
    glPopMatrix();

}

void MyGLWidget::updateCamMoveEvent(int vectX,int vectY){
    if (vectY>=10 || vectY<=-10){
        game.stick_.setSpeed(0);
    }
    else {
        if (vectX>=10){
            game.stick_.setSpeed(0.7);
        }
        if (vectX<=-10){
            game.stick_.setSpeed(-0.7);
        }

    }

}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(game.mouseEventAct){
        this->setMouseTracking(true);
        if (event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION+game.getStick().getWidth()/2<=MAX_DIMENSION && event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION-game.getStick().getWidth()/2>= -MAX_DIMENSION )
        {
            game.stick_.setX(event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION);
            //Detecter la position de la souris

            if(game.getBille().getState()==QString("fixed"))
            {
                game.bille_.setX(event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION);
            }
        }
    }
}






