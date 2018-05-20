#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <GL/glu.h>
#include<gamemanager.h>
#include <QTimer>

// Classe dediee a l'affichage d'une scene OpenGL

class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);
    GameManager game;
public:/*
    void mouseMoveEvent(QMouseEvent *event);*/
    void updateCamMoveEvent(int vectX,int vectY);
protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    void drawBall();
    void drawPallet();
    void dessineCube(double centerX,double centerY,double centerZ,double width,double height,int lpTot, int lp);
private:
    // Timer d'animation
//    QTimer m_AnimationTimer;

    // Quelques variables a definir
    bool hide = TRUE;
    GLuint tab_text[23];

};

#endif // MYGLWIDGET_H
