#ifndef PALETTE_H
#define PALETTE_H

/*!
  *\file Palette.h
  *\brief Gestionnaire de palette
  *\author Rouby Terenui
*/

#include "square.h"

class Palette: public Square
{
    /*!
      *\class Palette
      * \brief Classe gérant les caractéristiques de la palette
*/
private:
    double speed_;/*!< Vitesse de la palette */

public:
    /*!
     * \brief Palette
     * Constructeur
     * \param width Epaisseur de la palette
     * \param height Hauteur de la palette
     * \param x Position selon x
     * \param y Position selon y
     * \param z Position selon z
     * \param speed Vitesse de la palette
     */
    Palette(double width,double height,double x ,double y,double z,double speed);
    /*!
     * \brief Palette
     * Constructeur
     */
    Palette();
    /*!
     * \brief getSpeed
     * \return
     */
    double getSpeed(){return(speed_);}
    /*!
     * \brief setSpeed
     * \param sp Vitesse de la palette
     * \return
     */
    void setSpeed(double sp){speed_=sp;}
};

#endif // PALETTE_H
