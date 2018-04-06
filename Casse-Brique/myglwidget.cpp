#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>
#include <gamemanager.h>
// Declaration des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 55.0f;
// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
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
    QImage Background6 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 6.jpg"));
    QImage brickT = QGLWidget::convertToGLFormat(QImage(":/Images/brick.jpg"));
    QImage paletteT = QGLWidget::convertToGLFormat(QImage(":/Images/palette.jpg"));
    QImage billeT = QGLWidget::convertToGLFormat(QImage(":/Images/lune.jpg"));

    // Application des textures
    glGenTextures(9, tab_text);


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
    glTexImage2D( GL_TEXTURE_2D, 0, 4, Background6.width(), Background6.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Background6.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[6]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickT.width(), brickT.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickT.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[7]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, paletteT.width(), paletteT.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, paletteT.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[8]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, billeT.width(), billeT.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, billeT.bits() );
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
       glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);
    // Centre de l'image (0,0)

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,0,80,0,0,0,0,1,0);//On se positionne on -80 (sur z)
    // Nettoyage
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Effacer le buffer de couleur

    glBindTexture(GL_TEXTURE_2D, tab_text[0]);

    // Affichage du cube du background
    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex3f(55.0f, 55.0f, -10.0f);
    glTexCoord2d(1,0); glVertex3f(-55.0f, 55.0f, -10.0f);
    glTexCoord2d(1,1); glVertex3f(-55.0f, -55.0f, -10.0f);
    glTexCoord2d(0,1); glVertex3f(55.0f, -55.0f, -10.0f);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, tab_text[1]);
    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex3f(111.0f, 222.0f, -10.0f);
    glTexCoord2d(1,0); glVertex3f(0.0f, 222.0f, -10.0f);
    glTexCoord2d(1,1); glVertex3f(0.0f, 111.0f, -10.0f);
    glTexCoord2d(0,1); glVertex3f(111.0f, 111.0f, -10.0f);
    glEnd();

    glClear(GL_DEPTH_BUFFER_BIT);


    glBindTexture(GL_TEXTURE_2D, tab_text[6]);
    // Affichage du terrain de la partie initiale
    for (int i=0;i<120;i++){
        dessineCube(game.listbricks_[i].getX(),game.listbricks_[i].getY(),game.listbricks_[i].getZ(),game.listbricks_[i].getWidth(),game.listbricks_[i].getHeight());
    }
    glBindTexture(GL_TEXTURE_2D, tab_text[7]);
    dessineCube(game.stick_.getX(),game.stick_.getY(),game.stick_.getZ(),game.stick_.getWidth(),game.stick_.getHeight());

    drawBall();

}

void MyGLWidget::dessineCube(double centerX,double centerY,double centerZ,double width,double height){// Dessin des bricks
    glBegin(GL_QUADS);
    // Face arrière
    glTexCoord2d(0,0);glVertex3f(centerX+width/2, centerY+height/2,centerZ - 1.25f);
    glTexCoord2d(1,0); glVertex3f( centerX+width/2, centerY-height/2,centerZ - 1.25f);
    glTexCoord2d(1,1); glVertex3f(centerX-width/2, centerY-height/2,centerZ - 1.25f);
    glTexCoord2d(0,1); glVertex3f(centerX-width/2, centerY+height/2,centerZ - 1.25);

    // Face avant
    glTexCoord2d(0,0);glVertex3f(centerX+width/2, centerY+height/2,centerZ + 1.25f);
    glTexCoord2d(1,0);glVertex3f( centerX+width/2, centerY-height/2,centerZ + 1.25f);
    glTexCoord2d(1,1);glVertex3f(centerX-width/2, centerY-height/2,centerZ + 1.25f);
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
    glBindTexture(GL_TEXTURE_2D, tab_text[8]);
    GLUquadric* quadrique2=gluNewQuadric();
    gluQuadricDrawStyle(quadrique2, GLU_LINE);
    gluQuadricNormals(quadrique2, GLU_SMOOTH);
    gluQuadricTexture(quadrique2,GL_TRUE);
    glTranslatef(game.bille_.getX(),game.bille_.getY(),game.bille_.getZ());
    gluSphere(quadrique2, game.bille_.getRadius(), 20, 50);//Definition du Rayon
    glPopMatrix();

}







