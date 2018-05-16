#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

// Declaration des constantes
const unsigned int WIN_WIDTH  = 1200;
const unsigned int WIN_HEIGHT = 500;
const float MAX_DIMENSION     = 45.0f;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    ui->centralWidget->setMouseTracking(true);
    ui->openGLWidget->setMouseTracking(true);
    this->moveDetection=OpenCvWidget();
    ui->label->setPixmap(moveDetection.drawQPixMap());
    resize( QSize(2000,1000));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Fonction de gestion d'interactions clavier
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Activation/Arret de l'animation
        case Qt::Key_Alt:
        {
            if(ui->openGLWidget->game.bille_.getState()==QString("fixed"))
            {
               ui->openGLWidget->game.bille_.setState(QString("unfixed"));

            }


            break;
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

void MainWindow::on_pushButton_2_clicked()//Changement de la taille de la Palette (Poser peut-être des tailles limites?)
{
    ui->openGLWidget->game.stick_.setWidth(ui->lineEdit->text().toDouble());
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->openGLWidget->game=GameManager();
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("outputCasseBrique.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
       return;

    QTextStream out(&file);
    out << ui->lineEdit_2->text() + " :  " + QString::number(ui->openGLWidget->game.nbwin_)+ " : " + QString::number(ui->openGLWidget->game.player.getScore())+"\r\n" ;

}
