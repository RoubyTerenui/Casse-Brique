/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_10;
    MyGLWidget *openGLWidget;
    QPushButton *restart_Button;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QSlider *slider;
    QPushButton *changeSizeStick_Button;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QPushButton *saveTopPlayersButton;
    QLabel *label;
    QListWidget *topPlayers;
    QPushButton *changeModeButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1250, 1250);
        MainWindow->setMinimumSize(QSize(1250, 500));
        MainWindow->setMaximumSize(QSize(1250, 2000));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1300, 500));
        centralWidget->setMaximumSize(QSize(1300, 1500));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 50, 1202, 602));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new MyGLWidget(verticalLayoutWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(1200, 500));
        openGLWidget->setMaximumSize(QSize(1200, 500));

        verticalLayout_10->addWidget(openGLWidget);

        restart_Button = new QPushButton(verticalLayoutWidget);
        restart_Button->setObjectName(QStringLiteral("restart_Button"));
        restart_Button->setMinimumSize(QSize(1100, 25));
        restart_Button->setMaximumSize(QSize(1200, 25));

        verticalLayout_10->addWidget(restart_Button);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_10->setContentsMargins(-1, -1, 0, -1);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(200, 25));
        label_2->setMaximumSize(QSize(200, 25));

        horizontalLayout_10->addWidget(label_2, 0, Qt::AlignLeft|Qt::AlignTop);

        slider = new QSlider(verticalLayoutWidget);
        slider->setObjectName(QStringLiteral("slider"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
        slider->setSizePolicy(sizePolicy);
        slider->setMinimumSize(QSize(120, 25));
        slider->setMaximumSize(QSize(120, 25));
        slider->setFocusPolicy(Qt::WheelFocus);
        slider->setContextMenuPolicy(Qt::PreventContextMenu);
        slider->setMinimum(3);
        slider->setMaximum(40);
        slider->setValue(9);
        slider->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(slider, 0, Qt::AlignLeft|Qt::AlignVCenter);

        changeSizeStick_Button = new QPushButton(verticalLayoutWidget);
        changeSizeStick_Button->setObjectName(QStringLiteral("changeSizeStick_Button"));
        changeSizeStick_Button->setEnabled(true);
        changeSizeStick_Button->setMinimumSize(QSize(200, 25));
        changeSizeStick_Button->setMaximumSize(QSize(200, 25));

        horizontalLayout_10->addWidget(changeSizeStick_Button, 0, Qt::AlignLeft|Qt::AlignTop);


        verticalLayout_10->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(200, 25));
        label_4->setMaximumSize(QSize(200, 25));

        horizontalLayout_11->addWidget(label_4, 0, Qt::AlignLeft|Qt::AlignTop);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(60, 25));
        lineEdit_2->setMaximumSize(QSize(200, 25));

        horizontalLayout_11->addWidget(lineEdit_2, 0, Qt::AlignLeft|Qt::AlignTop);

        saveTopPlayersButton = new QPushButton(verticalLayoutWidget);
        saveTopPlayersButton->setObjectName(QStringLiteral("saveTopPlayersButton"));
        saveTopPlayersButton->setMinimumSize(QSize(200, 25));
        saveTopPlayersButton->setMaximumSize(QSize(200, 25));

        horizontalLayout_11->addWidget(saveTopPlayersButton, 0, Qt::AlignLeft|Qt::AlignTop);


        verticalLayout_10->addLayout(horizontalLayout_11);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 670, 400, 600));
        label->setMinimumSize(QSize(400, 600));
        label->setMaximumSize(QSize(400, 600));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        topPlayers = new QListWidget(centralWidget);
        topPlayers->setObjectName(QStringLiteral("topPlayers"));
        topPlayers->setGeometry(QRect(710, 670, 401, 221));
        changeModeButton = new QPushButton(centralWidget);
        changeModeButton->setObjectName(QStringLiteral("changeModeButton"));
        changeModeButton->setGeometry(QRect(480, 660, 201, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1250, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        restart_Button->setText(QApplication::translate("MainWindow", "Restart", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Taille de la palette", nullptr));
        changeSizeStick_Button->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Nom du joueur :", nullptr));
        saveTopPlayersButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QString());
        changeModeButton->setText(QApplication::translate("MainWindow", "Passer en Mode Souris", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
