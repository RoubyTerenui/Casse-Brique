#ifndef PLAYER_H
#define PLAYER_H
/*!
  *\file Player.h
  *\brief Gestionnaire de joueur
  *\author Rouby Terenui
*/

#include <fstream>
#include <string>

using namespace std;

class Player
{
    /*!
      *\class Player
      * \brief Classe gérant les caractéristiques du joueur
*/
private:
    string nom_;/*!< Nom du joueur */
    int lifePoint_;/*!< Vie du joueur */
    int score_;/*!< Score du joueur */
    int nbwin_;/*!< Nombre de victoires du joueur */
public:
    /*!
     * \brief Player
     * Constructeur
     */
    Player();
    /*!
     * \brief Player
     * Constructeur
     */
    Player(const Player &p);
    /*!
     * \brief getLifePoint
     * \return
     */
    int getLifePoint(){return(lifePoint_);}
    /*!
     * \brief getScore
     * \return
     */
    int getScore(){return(score_);}
    /*!
     * \brief setScore
     * \param score Score du joueur
     * \return
     */
    void setScore(int score){score_=score;}
    /*!
     * \brief setLifePoint
     * \param LifePoint PdV restants du joueur
     * \return
     */
    void setLifePoint(int LifePoint){lifePoint_=LifePoint;}
    /*!
     * \brief setNbWin
     * \param nb Nombre de victoires du joueur
     * \return
     */
    void setNbWin(int nb){nbwin_=nb;}
    /*!
     * \brief setName
     * \param name Nom du joueur
     * \return
     */
    void setName(string name){nom_=name;}
    /*!
     * \brief getName
     * \return
     */
    string getName(){return nom_;}
    /*!
     * \brief getNbWin
     * \return
     */
    int getNbWin(){return(nbwin_);}
    /*!
     * \brief charger
     * Permet de charger une partie sauvegardée
     */
    void charger(ifstream &is);
    /*!
     * \brief sauver
     * Permet de sauvegarder une partie
     */
    void sauver(ofstream &os);
    /*!
     * \brief Operator
     * Operateur
     */
    bool operator <(const Player &p)const;

};

#endif // PLAYER_H
