#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>
#include <QTimer>
#include <gamemanager.h>
#include <QDebug>

// Declaration des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 55.0f;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    this->setMouseTracking(true);
    game=GameManager();
    //Boucle d'animation
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        game.updateBille_Score();
        game.updateNbWin();
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    // Activation des textures
    glEnable(GL_TEXTURE_2D);


    // Chargement des images
    QImage Background1 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 11.jpg"));
    QImage Background2 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 2.jpg"));
    QImage Background3 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 3.jpg"));
    QImage Background4 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 4.jpg"));
    QImage Background5 = QGLWidget::convertToGLFormat(QImage(":/Images/Background 5.jpg"));
    QImage brickT = QGLWidget::convertToGLFormat(QImage(":/Images/Brick.png"));
    QImage paletteT = QGLWidget::convertToGLFormat(QImage(":/Images/palette.jpg"));
    QImage billeT = QGLWidget::convertToGLFormat(QImage(":/Images/lune.jpg"));

    // Application des textures
    glGenTextures(8, tab_text);


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
    glTexImage2D( GL_TEXTURE_2D, 0, 4, brickT.width(), brickT.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, brickT.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[6]);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, paletteT.width(), paletteT.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, paletteT.bits() );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, tab_text[7]);
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
       glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width)+31*(game.nbwin % 9), MAX_DIMENSION * height / static_cast<float>(width)+31*(game.nbwin % 9), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f+31*game.nbwin);
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
    glOrtho(-MAX_DIMENSION, MAX_DIMENSION,-31, 31, -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f+31*game.nbwin);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,0,80,0,0,0,0,1,0);//On se positionne on -80 (sur z)
    // Nettoyage
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Effacer le buffer de couleur

    glBindTexture(GL_TEXTURE_2D, tab_text[game.nbwin % 7]);

    // Affichage du cube du background
    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex3f(55.0f,31.0f, -10.0f);
    glTexCoord2d(1,0); glVertex3f(-55.0f, 31.0f, -10.0f);
    glTexCoord2d(1,1); glVertex3f(-55.0f, -31.0f, -10.0f);
    glTexCoord2d(0,1); glVertex3f(55.0f, -31.0f, -10.0f);
    glEnd();



    glClear(GL_DEPTH_BUFFER_BIT);


    glBindTexture(GL_TEXTURE_2D, tab_text[5]);

    //Affichage du texte
    this->renderText(-53,30,-79,"life Point : " +QString::number(game.player.getLifePoint()),QFont());
    this->renderText(-53,29,-79,"score : "+QString::number(game.player.getScore()),QFont());
    this->renderText(-53,28,-79,"Level : " +QString::number(game.nbwin),QFont());

    // Affichage du terrain de la partie initiale
    for (int i=0;i<120;i++){
        if (game.listbricks_[i].getLife()>0)
        {
            dessineCube(game.listbricks_[i].getX(),game.listbricks_[i].getY(),game.listbricks_[i].getZ(),game.listbricks_[i].getWidth(),game.listbricks_[i].getHeight());
        }
    }
    glBindTexture(GL_TEXTURE_2D, tab_text[6]);
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
    glBindTexture(GL_TEXTURE_2D, tab_text[7]);
    GLUquadric* quadrique2=gluNewQuadric();
    gluQuadricDrawStyle(quadrique2, GLU_LINE);
    gluQuadricNormals(quadrique2, GLU_SMOOTH);
    gluQuadricTexture(quadrique2,GL_TRUE);
    glTranslatef(game.bille_.getX(),game.bille_.getY(),game.bille_.getZ());
    gluSphere(quadrique2, game.bille_.getRadius(), 20, 50);//Definition du Rayon
    glPopMatrix();

}




