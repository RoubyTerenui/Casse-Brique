#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <GL/glu.h>
#include<gamemanager.h>

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    void drawBall();
    void drawPallet();
    void dessineCube(double centerX,double centerY,double centerZ,double width,double height);
private:

    // Quelques variables a definir
    int forme = 1;
    float R = 0.5;
    float G = 0.5;
    float B = 0.5;
    float fR = 20;
    float fG = 20;
    float fB = 150;
    bool hide = TRUE;
    int posx = 0;
    int posy = 0;
    int angle = 3;
    GLuint tab_text[9];
    GameManager game;
};

#endif // MYGLWIDGET_H
