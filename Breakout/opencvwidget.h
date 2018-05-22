#ifndef OPENCVWIDGET_H
#define OPENCVWIDGET_H

/*!
  *\file OpenCvWidget.h
  *\brief Utiliser OpenCV
  * Réutilisation d'une classe donnée comme point de départ dans le cadre du projet
  * qui a été adapté pour l'utilisation dans ce projet
  *\author TSE,Rouby Terenui,Ansart Valentin
*/

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QWidget>
#include <cstdio>
#include <iostream>
/*! \namespace cv
 *
 * espace de nommage permettant d'utiliser la librairie openCV
 */
using namespace cv;

class OpenCvWidget
{
    /*!
      *\class OpenCvWidget
      *\brief Regroupe les éléments utilisés pour l'affichage de la caméra et la detection de mouvement
      */
public:
    /*!
     * \brief OpenCvWidget Constructeur
     */
    OpenCvWidget();
public:
    int frameWidth;
    int frameHeight;
    int subImageWidth;/*!< Largeur de la zone où l'on souhaite faire la detection de mouvement */
    int subImageHeight;/*!< Hauteur de la zone où l'on souhaite faire la detection de mouvement */
    int templateWidth;/*!< Largeur du rectangle template */
    int templateHeight;/*!< Hauteur du rectangle template */
    bool state;/*!< état de la caméra */
    Rect workingRect_;/*!< Rectangle correspondant à la zone dans laquel la detection de mouvement sera effectué */
    Rect templateRect_;/*!< Rectangle utilisé pour la comparaison avec le working rect sur 2 frames différentes*/
    Point workingCenter_;/*!< Centre de Working Rect */
    VideoCapture cap;/*!< Caméra */
};

#endif // OPENCVWIDGET_H
