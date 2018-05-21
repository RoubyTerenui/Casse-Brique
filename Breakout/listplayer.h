#ifndef LISTPLAYER_H
#define LISTPLAYER_H
/*!
  *\file ListPlayer.h
  *\brief ListPlayer utilisé pour le tableau de score
  *\author Rouby Terenui
*/
#include<list>
#include<fstream>
#include <player.h>


class ListPlayer : public list<Player>
{
    /*!
      *\class ListPlayer
      *\brief Liste des meilleurs joueurs (hérite de list<Player>)
      *
      */
public:
    /*!
     * \Constructeur
     * \brief ListPlayer
     */
    ListPlayer();
    /*!
     * \brief charger
     * Fonction permettant de charger la liste dans un fichier texte
     * \param is :fichier où l'on va lire les données
     */
    void charger(std::ifstream &is);
    /*!
     * \brief sauver
     * Fonction permettant de sauvegarder la liste dans un fichier texte
     * \param os :fichier où l'on va écrire les données
     */
    void sauver(std::ofstream &os);
    /*!
     * \brief triList
     * Fonction permettant de trier la liste en fonction du score et du nombre de victoire
     */
    void triList();
};

#endif // LISTPLAYER_H
