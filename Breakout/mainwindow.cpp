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
{   count=0;
    resize( QSize(2000,1000));
    this->moveDetection=OpenCvWidget();
    if(!moveDetection.cap.isOpened())  // verification de l'ouverture de la Webcam
    {
        ui->label->setText("Error openning the default camera");
        moveDetection.state=false;
        return;
    }
    ui->setupUi(this);
    setMouseTracking(true);
    ui->centralWidget->setMouseTracking(true);
    ui->openGLWidget->setMouseTracking(true);
    connect(&tmrTimer,  &QTimer::timeout, [&] {
        if ((ui->openGLWidget->game.stick_.getX()+ui->openGLWidget->game.stick_.getSpeed())+ui->openGLWidget->game.stick_.getWidth()/2<=MAX_DIMENSION+1 && (ui->openGLWidget->game.stick_.getX()+ui->openGLWidget->game.stick_.getSpeed())-ui->openGLWidget->game.getStick().getWidth()/2>= -MAX_DIMENSION-1 )
        {
            ui->openGLWidget->game.updatePositionPalette();
        }
        ui->openGLWidget->game.updateBille_Score();
        ui->openGLWidget->game.updateNbWin();
        ui->openGLWidget->updateGL();

        if (count==0){// Counter pour réduire la fréquence d'affichage de la vidéo (diminue le temps CPU assigné à la tache)
            updateF();

        }

        count-=1;

    });
    tmrTimer.setInterval(20);
    tmrTimer.start();

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
    out << ui->lineEdit_2->text() + " :  " + QString::number(ui->openGLWidget->game.getNbWin())+ " : " + QString::number(ui->openGLWidget->game.getPlayer().getScore())+"\r\n" ;

}


void MainWindow::updateF(){
    //Réinitialise le counteur régulant la fréquence d'affichage
    count=5;

    //Définie hauteur et Largeur
    Mat frame1,frame2,frameRect1,frameRect2;
    moveDetection.cap.set(CV_CAP_PROP_FRAME_WIDTH,moveDetection.frameWidth);
    moveDetection.cap.set(CV_CAP_PROP_FRAME_HEIGHT,moveDetection.frameHeight);

    //Définie si la caméra est en état de marche ou pas
    moveDetection.state=true;

    // Obtien la frame1
    moveDetection.cap >> frame1;
    // Mirror effect
    cv::flip(frame1,frame1,1);
    // Extract rect1 and convert to gray
    cv::cvtColor(Mat(frame1,moveDetection.workingRect_),frameRect1,COLOR_BGR2GRAY);
    //Mat(frame1,rect).copyTo(frameRect1);

    // Crée le matchTemplate image result
    Mat resultImage;    // to store the matchTemplate result
    int result_cols =  frame1.cols-moveDetection.templateWidth  + 1;
    int result_rows = frame1.rows-moveDetection.templateHeight + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );


    // Obtien la frame2
    moveDetection.cap >> frame2;
    // Effet miroir
    cv::flip(frame2,frame2,1);
    // Extrait WorkingRect de la frame 2 et la convertie en niveau de gris
    cv::cvtColor(Mat(frame2,moveDetection.workingRect_),frameRect2,COLOR_BGR2GRAY);

    // Extract template image in frame1
    Mat templateImage(frameRect1,moveDetection.templateRect_);
    // Etablit la correspondance entre le workingrect de la frame2 et templateImage de la frame1
    matchTemplate( frameRect2, templateImage, resultImage, TM_CCORR_NORMED );
    // Choisit la valeur adapté en utilisant minMaxLoc
    double minVal; double maxVal; Point minLoc; Point maxLoc;
    minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);

    Point vect(maxLoc.x-moveDetection.templateRect_.x,maxLoc.y-moveDetection.templateRect_.y);

    // Dessine le rectangle d'action et le vecteur de mouvement
    rectangle(frame2,moveDetection.workingRect_,Scalar( 0, 255, 0),2);
    Point p(moveDetection.workingCenter_.x+vect.x,moveDetection.workingCenter_.y+vect.y);
    arrowedLine(frame2,moveDetection.workingCenter_,p,Scalar(255,255,255),2);

    // the camera will be deinitialized automatically in VideoCapture destructor
    // Swap matrixes
    swap(frameRect1,frameRect2);
    QImage actu=QImage((uchar*) frame2.data, frame2.cols, frame2.rows, QImage::Format_RGB888);
    //Detecte le vecteur de Mouvement permettant de bouger la Palette à partir de la Caméra
    ui->openGLWidget->updateCamMoveEvent(vect.x,vect.y);
    //Affiche l'image actuelle dans le Label
    ui->label->setPixmap(QPixmap::fromImage(actu));
}
