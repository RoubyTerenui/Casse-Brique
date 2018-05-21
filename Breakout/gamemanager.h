#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
/*!
  *\file GameManager.h
  *\brief Gestionnaire de Jeu
  *\author Rouby Terenui,Ansart Valentin
*/

#include "ball.h"
#include "square.h"
#include "palette.h"
#include "player.h"
#include <QPoint>

class GameManager
{
    /*!
      *\class GameManager
      * \brief Classe regroupant et gérant les éléments du jeu
*/
public:
    Ball bille_;/*!< Bille du jeu */
    Square listbricks_[70];/*!< Liste avec pour taille le nombre de lignes de bricks maximum *10 */
    Palette stick_;/*!< Palette du jeu permettant de renvoyer la balle et de la diriger */
    Player player;/*!< Joueur */
    QString state_;/*!< Etats du jeu (peut prendre deux valeurs*/
    int nbwin_;/*!< Niveau de difficulté du jeu */
    bool mouseEventAct=false;/*! Mode de Jeu */
private:
    /*!
     * \brief collisionPointCercle
     * \param x Coordonné en X du Point tester
     * \param y Coordonné en Y du Point tester
     * \param b bille(avec les attributs cercles que l'on souhaite tester)
     * \return boolean indiquant si il y a collision entre le Point et la bille
     */
    bool collisionPointCercle(double x,double y,Ball b);
    /*!
     * \brief collisionDroite
     * \param aX Coordonnée en X d'une extremité a de la droite
     * \param aY Coordonnée en Y d'une extremité a de la droite
     * \param bX Coordonnée en X d'une extremité b de la droite
     * \param bY Coordonnée en Y d'une extremité b de la droite
     * \param C  bille(avec les attributs cercles que l'on souhaite tester)
     * \return boolean indiquant si il y a collision entre le Point et la bille
     */
    bool collisionDroite(double aX,double aY,double bX,double bY,Ball C);
    /*!
     * \brief collisionSegmentCercle
     * \param aX Coordonnée en X d'un point a de la droite
     * \param aY Coordonnée en Y d'un point a de la droite
     * \param bX Coordonnée en X d'un point b de la droite
     * \param bY Coordonnée en Y d'un point b de la droite
     * \param C  bille(avec les attributs cercles que l'on souhaite tester)
     * \return
     */
    bool collisionSegmentCercle(double aX,double aY,double bX,double bY,Ball C);
public:
    /*!
     * \brief Constructeur
     *
     * Constructeur de la classe GameManager
     *
     */
    GameManager();
    /*!
     * \brief changeMode
     *
     * Changement du mode de Jeu (Mode souris ou caméra)
     */
    void changeMode(){mouseEventAct=!mouseEventAct;}
    /*!
     * \brief reinitialiserBricks
     *
     * Réinitialise la liste de brick en fonction du niveau de difficulté
     */
    void reinitialiserBricks();/*!
     * \brief initializeNbWin
     *
     * initialise la variable nbwin_
     *
     */
    void initializeNbWin(){nbwin_=0;}
    /*!
     * \brief collisionBrick
     *
     * Detecte si il y a collision entre la bille et la brick
     *
     * \param brick :Brick sur laquelle on cherche à determiner si il y a collision
     * \return :Renvoie un entier entre 0 et 8 indiquant la collision avec une brick et met à jour sa vie
     */
    int collisionBrick(Square brick);
    /*!
     * \brief collisionWall
     *
     * Detecte si il y a collision entre la bille et les murs
     *
     * \param dimensionMax :Dimension Max du Plateau
     * \param width :Largeur du plateau
     * \param height :Hauteur du plateau
     * \return Renvoie un entier entre 0 et 8 indiquant la collision avec les bords du plateau
     */
    int collisionWall(double dimensionMax,double width,double height);
    /*!
     * \brief updateBille_Score
     * Met à jour Position de la Bille,la Vie des briques et le score du joueur en fonction de l'état de la liste de brick
     *
     */
    void updateBille_Score();
    /*!
     * \brief updateNbWin
     *
     * Met à jour le Level sur lequel on se situe et le comptage du nombre de victoire
     */
    void updateNbWin();
    /*!
     * \brief updatePositionPalette
     *
     * Met à jour la position de la palette dans le mode Camera
     */
    void updatePositionPalette();
    /*!
     * \brief searchPositionImpact
     * Cherche la position de l'impact entre la bille et la palette
     * \param brick : Palette de jeu
     * \return Position en X de l'impact
     */
    double searchPositionImpact(Palette brick);
    /*!
     * \brief getBille
     * \return
     */
    Ball getBille(){return(bille_);}
    /*!
     * \brief getStick
     * \return
     */
    Palette getStick(){return(stick_);}
    /*!
     * \brief getPlayer
     * \return
     */
    Player getPlayer(){return(player);}
    /*!
     * \brief getNbWin
     * \return
     */
    int getNbWin(){return(nbwin_);}
    /*!
     * \brief getState
     * \return
     */
    QString getState(){return(state_);}
    /*!
     * \brief getBrickI
     * \param i:numéro de la brick que l'on souhaite obtenir
     * \return  Brick numéro i de listbricks
     */
    Square getBrickI(int i){return(listbricks_[i]);}
};

#endif // GAMEMANAGER_H
