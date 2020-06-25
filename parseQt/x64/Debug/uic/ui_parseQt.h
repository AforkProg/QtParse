/********************************************************************************
** Form generated from reading UI file 'parseQt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARSEQT_H
#define UI_PARSEQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parseQtClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *exitButton;
    QPushButton *timeButton;
    QPushButton *nameButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *parseQtClass)
    {
        if (parseQtClass->objectName().isEmpty())
            parseQtClass->setObjectName(QString::fromUtf8("parseQtClass"));
        parseQtClass->resize(430, 300);
        parseQtClass->setMinimumSize(QSize(430, 300));
        parseQtClass->setMaximumSize(QSize(430, 300));
        centralWidget = new QWidget(parseQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 401, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Tempus Sans ITC"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(170, 190, 93, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tempus Sans ITC"));
        font1.setBold(true);
        font1.setWeight(75);
        exitButton->setFont(font1);
        timeButton = new QPushButton(centralWidget);
        timeButton->setObjectName(QString::fromUtf8("timeButton"));
        timeButton->setGeometry(QRect(20, 100, 151, 61));
        timeButton->setFont(font1);
        nameButton = new QPushButton(centralWidget);
        nameButton->setObjectName(QString::fromUtf8("nameButton"));
        nameButton->setGeometry(QRect(260, 100, 151, 61));
        nameButton->setFont(font1);
        parseQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(parseQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 430, 26));
        parseQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(parseQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        parseQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(parseQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        parseQtClass->setStatusBar(statusBar);

        retranslateUi(parseQtClass);
        QObject::connect(exitButton, SIGNAL(clicked()), parseQtClass, SLOT(close()));
        QObject::connect(timeButton, SIGNAL(clicked()), parseQtClass, SLOT(hide()));
        QObject::connect(nameButton, SIGNAL(clicked()), parseQtClass, SLOT(hide()));

        QMetaObject::connectSlotsByName(parseQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *parseQtClass)
    {
        parseQtClass->setWindowTitle(QCoreApplication::translate("parseQtClass", "parseQt", nullptr));
        label->setText(QCoreApplication::translate("parseQtClass", "Hello stranger! Choose you destiny!", nullptr));
        exitButton->setText(QCoreApplication::translate("parseQtClass", "Exit", nullptr));
        timeButton->setText(QCoreApplication::translate("parseQtClass", "Parse by time!", nullptr));
        nameButton->setText(QCoreApplication::translate("parseQtClass", "Parse by name!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parseQtClass: public Ui_parseQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARSEQT_H
