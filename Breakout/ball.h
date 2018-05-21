#ifndef BALL_H
#define BALL_H
/*!
  *\file Ball.h
  *\brief Gestionnaire de Balle
  *\author Rouby Terenui
*/
#include <QString>

class Ball
{
    /*!
      *\class Ball
      * \brief Classe gérant les caractéristiques des balles
*/
private:
    double radius_; /*!< Rayon de la bille */
    double center_[3];/*!< Centre de la bille */
    double speed_;/*!< Vitesse de la bille */
    double directionX_;/*!< Direction de la bille selon x */
    double directionY_;/*!< Direction de la bille selon y */
    double directionZ_;/*!< Direction de la bille selon z */
    QString state_;/*!< Etat collée ou non de la bille à la palette */

public:
    /*!
     * \brief Ball
     * Constructeur Ball
     */
    Ball();
    /*!
     * \brief Ball
     * Constructeur Ball
     * \param radius Rayon de la bille
     * \param x Position selon x de la bille
     * \param y Position selon y de la bille
     * \param z Position selon z de la bille
     * \param speed Vitesse de la bille
     */
    Ball(double radius,double x,double y,double z,double speed);
    /*!
     * \brief reinitialiser
     * Replacement de la balle
     * \param radius Rayon de la bille
     * \param x Position selon x de la bille
     * \param y Position selon y de la bille
     * \param z Position selon z de la bille
     */
    void reinitialiser(double x,double y,double z);
    /*!
     * \brief getRadius
     * \return
     */
    double getRadius(){return radius_;}
    /*!
     * \brief getSpeed
     * \return
     */
    double getspeed(){return speed_;}
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
     * \brief getState
     * \return
     */
    QString getState(){return state_;}
    void setState(QString change){state_=change;}
    /*!
     * \brief getDirection
     * \return
     */
    double *getDirection();
    /*!
     * \brief getDirectionX
     * \return
     */
    double getDirectionX(){return directionX_;}
    /*!
     * \brief getDirectionY
     * \return
     */
    double getDirectionY(){return directionY_;}
    /*!
     * \brief getDirectionZ
     * \return
     */
    double getDirectionZ(){return directionZ_;}
    /*!
     * \brief setDirectionX
     * \param direcitonX Direction selon X
     * \return
     */
    void setDirectionX(double directionX){directionX_=directionX;}
    /*!
     * \brief setDirectionY
     * \param direcitonY Direction selon Y
     * \return
     */
    void setDirectionY(double directionY){directionY_=directionY;}
    /*!
     * \brief setDirectionZ
     * \param direcitonZ Direction selon Z
     * \return
     */
    void setDirectionZ(double directionZ){directionZ_=directionZ;}
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
     * \brief setRadius
     * \param radius Rayon de la bille
     * \return
     */
    void setRadius(double radius){radius_=radius;}
    /*!
     * \brief setSpeed
     * \param speed Vitesse de la bille
     * \return
     */
    void setSpeed(double speed){speed_=speed;}

};
#endif // BALL_H
