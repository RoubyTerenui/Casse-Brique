#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

// Declaration des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 55.0f;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    ui->centralWidget->setMouseTracking(true);
    ui->openGLWidget->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->setMouseTracking(true);
    if (event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION+ui->openGLWidget->game.stick_.getWidth()/2<=55 && event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION-ui->openGLWidget->game.stick_.getWidth()/2>= -55 )
    {
        ui->openGLWidget->game.stick_.setX(event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION);
        //Detecter la position de la souris
        qDebug() << "x::"<<QString::number(event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION);
        qDebug() << "y::"<< QString::number(-event->pos().y()*2*MAX_DIMENSION * WIN_HEIGHT / WIN_WIDTH/WIN_HEIGHT+MAX_DIMENSION * WIN_HEIGHT / WIN_WIDTH);
        //
        if(ui->openGLWidget->game.bille_.getState()==QString("fixed"))
        {
            ui->openGLWidget->game.bille_.setX(event->pos().x()*2*MAX_DIMENSION/WIN_WIDTH-MAX_DIMENSION);
        }
    }
}

// Fonction de gestion d'interactions clavier
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Activation/Arret de l'animation
        case Qt::Key_Space:
        {
            if(ui->openGLWidget->game.bille_.getState()==QString("fixed"))
            {
                ui->openGLWidget->game.bille_.setState(QString("unfixed"));

            }


            break;
        }

        // Sortie de l'application
        case Qt::Key_Escape:
        {
            exit(0);
        }

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }
}
