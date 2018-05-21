#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<opencvwidget.h>
#include <listplayer.h>
#include <QTimer>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent * event);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void updateF();

    void updateTabList();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    OpenCvWidget moveDetection;
    ListPlayer topPlayers;
    int count;
    QTimer tmrTimer;
};

#endif // MAINWINDOW_H
