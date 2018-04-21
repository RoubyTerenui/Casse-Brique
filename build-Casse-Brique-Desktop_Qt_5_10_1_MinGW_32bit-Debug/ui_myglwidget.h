/********************************************************************************
** Form generated from reading UI file 'myglwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYGLWIDGET_H
#define UI_MYGLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyGlWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *MyGlWidget)
    {
        if (MyGlWidget->objectName().isEmpty())
            MyGlWidget->setObjectName(QStringLiteral("MyGlWidget"));
        MyGlWidget->resize(400, 300);
        verticalLayoutWidget = new QWidget(MyGlWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 187, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MyGlWidget);

        QMetaObject::connectSlotsByName(MyGlWidget);
    } // setupUi

    void retranslateUi(QWidget *MyGlWidget)
    {
        MyGlWidget->setWindowTitle(QApplication::translate("MyGlWidget", "Form", nullptr));
        label_3->setText(QApplication::translate("MyGlWidget", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("MyGlWidget", "TextLabel", nullptr));
        label->setText(QApplication::translate("MyGlWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyGlWidget: public Ui_MyGlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYGLWIDGET_H
