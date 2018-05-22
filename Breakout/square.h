#ifndef SQUARE_H
#define SQUARE_H

/*!
  *\file Square.h
  *\brief Gestionnaire de brique
  *\author Rouby Terenui
*/


class Square
{
    /*!
      *\class Square
      * \brief Classe gérant les caractéristiques des briques
*/
private://(juste width height on suppose la profondeur constante on ne la précisera donc pas)
    double center_[3];/*!< Position de la brique */
    double width_;/*!< Largeur de la brique */
    double height_;/*!< Longueur de la brique */
    double score;/*!< Score/PdV max de la brique */
    int life_;/*!< PdV restants de la brique */
public:
    /*!
     * \brief Square
     * Constructeur
     */
    Square();
    /*!
     * \brief Square
     * Constructeur
     * \param width Epaisseur
     * \param height Hauteur
     * \param X Position selon x
     * \param Y Position selon y
     * \param Z Positions selon z
     * \param life Vie de la brique
     */
    Square(double width,double height,double X,double Y,double Z,int life);
    /*!
     * \brief getX
     * \return
     */
    double getX(){return center_[0];}
    /*!
     * \brief getY
     * \return
     */
    double getY(){return center_[1];}
    /*!
     * \brief getZ
     * \return
     */
    double getZ(){return center_[2];}
    /*!
     * \brief getScore
     * \return
     */
    double getScore(){return score;}
    /*!
     * \brief getWidth
     * \return
     */
    double getWidth(){return width_;}
    /*!
     * \brief getHeight
     * \return
     */
    double getHeight(){return height_;}
    /*!
     * \brief getLife
     * \return
     */
    int getLife(){return life_;}
    /*!
     * \brief setLife
     * \param life PdV restants de la brique
     * \return
     */
    void setLife(int life){ life_=life;}
    /*!
     * \brief setX
     * \param X Position selon X
     * \return
     */
    void setX(double X){center_[0]=X;}
    /*!
     * \brief setY
     * \param Y Position selon Y
     * \return
     */
    void setY(double Y){center_[1]=Y;}
    /*!
     * \brief setZ
     * \param Z Position selon Z
     * \return
     */
    void setZ(double Z){center_[2]=Z;}
    /*!
     * \brief setWidth
     * \param width Largeur de la brique
     * \return
     */
    void setWidth(double width){width_=width;}
};

#endif // SQUARE_H
