#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
  *\file MainWindow.h
  *\brief Gestionnaire de Jeu
  *\author Rouby Terenui,Ansart Valentin
*/

#include<opencvwidget.h>
#include <listplayer.h>
#include <QTimer>
#include <QMainWindow>

namespace Ui {
/*! \namespace Ui
 *
 * espace de nommage regroupant les outils l'interface graphique
 */
class MainWindow;
}

class MainWindow : public QMainWindow
{/*!
   *\class MainWindow
   * \brief Class gèrant la fenêtre principale et les élèments d'interfaces
   *
   */
    Q_OBJECT
public:
    /*!
     * \brief MainWindow Constructeur
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     *\brief ~MainWindow destructeur
     */
    ~MainWindow();
    /*!
     * \brief keyPressEvent
     * Lancement de la boule
     * \param event:déclenchement touche alt
     */
    void keyPressEvent(QKeyEvent * event);

private slots:
    /*!
     * \brief updateF
     * Mise à jour de l'image caméra pour qu'elle fonctionne de façon fluide
     */
    void updateCamera();
    /*!
     * \brief updateTabList
     * Mise à jour du tableau à afficher dans l'interface
     */
    void updateTabList();
    /*!
     * \brief on_restart_Button_clicked
     * Réinitialisation du jeu et des paramètres par défaut
     */
    void on_restart_Button_clicked();
    /*!
     * \brief on_changeSizeStick_Button_clicked
     * Change la taille de la Palette en fonction de la position du slider
     */
    void on_changeSizeStick_Button_clicked();
    /*!
     * \brief on_saveTopPlayersButton_clicked
     * Sauvegarde le score et les tries pour afficher les meilleures scores
     */
    void on_saveTopPlayersButton_clicked();
    /*!
     * \brief on_changeModeButton_clicked
     * Bouton pour changer de Mode(Mise à jour textuel du Boutton)
     */
    void on_changeModeButton_clicked();

private:
    Ui::MainWindow *ui;/*!< ui contenant les éléments d'interfaces */
    OpenCvWidget moveDetection;/*!<  Classe contenant les paramétre utilisé pour l'utilisation de la caméra */
    ListPlayer topPlayers;/*!< Liste des meilleurs joueurs */
    int count;/*!< Compteur utilisé pour diminuer la charge imposé par l'utilisation de la WebCam */
    QTimer tmrTimer;/*!< Timer utilisé pour la boucle de jeu */
};

#endif // MAINWINDOW_H
