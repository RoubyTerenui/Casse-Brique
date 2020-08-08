#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
/*!
  *\file MyGlWidget.h
  *\brief Gestionnaire du widget OpenGL
  *\author Rouby Terenui,Ansart Valentin
*/

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
    /*!
      *\class MyGLWidget
      * \brief Classe gérant les caractéristiques du widget OpenGL
*/
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);/*!< Constructeur */
    GameManager game;/*!< Game manager */
public:
    /*!
     * \brief mouseMoveEvent
     * Detecte un mouvement de la souris
     */
    void mouseMoveEvent(QMouseEvent *event);
    /*!
     * \brief updateCamMoveEvent
     * Detecte un mouvement dans la camera
     * \param vectX Position selon x de la détection
     * \param vectY Position selon y de la détection
     */
    void updateCamMoveEvent(int vectX,int vectY);
protected:
    /*!
     * \brief initializeGL
     * Fonction d'initialisation
     */
    void initializeGL();

    /*!
     * \brief resizeGL
     * Fonction de redimensionnement
     * \param width Largeur de la fenêtre
     * \param height Hauteur de la fenêtre
     */
    void resizeGL(int width, int height);

    /*!
     * \brief paitnGL
     * Fonction d'affichage
     */
    void paintGL();
    /*!
     * \brief drawball
     * Fonction de dessin de la balle
     */
    void drawBall();
    /*!
     * \brief drawPallet
     * Fonction de dessin de la palette
     */
    void drawPallet();
    /*!
     * \brief dessineCube
     * Dessine les briques
     * \param centerX Position selon x de la brique
     * \param centerY Position selon y de la brique
     * \param centerZ Position selon z de la brique
     * \param width Largeur de la brique
     * \param height Hauteur de la brique
     * \param lpTot PdV totaux/Score de la brique
     * \param lp PdV restants de la brique
     */
    void dessineCube(double centerX,double centerY,double centerZ,double width,double height,int lpTot, int lp);
private:

    // Quelques variables a definir
    GLuint tab_text[23];/*!< Tableau des textures */

};

#endif // MYGLWIDGET_H
