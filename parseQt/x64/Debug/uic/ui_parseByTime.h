/********************************************************************************
** Form generated from reading UI file 'parseByTime.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARSEBYTIME_H
#define UI_PARSEBYTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parseByTime
{
public:
    QLabel *label;
    QTextEdit *results;
    QTextEdit *path;
    QCheckBox *saveText;
    QRadioButton *doc;
    QRadioButton *folder;
    QPushButton *startParse;
    QTextEdit *Sec1;
    QTextEdit *min1;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *hour1;
    QLabel *label_4;
    QTextEdit *day1;
    QLabel *label_5;
    QTextEdit *mon1;
    QLabel *label_6;
    QTextEdit *year1;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QTextEdit *mon1_2;
    QTextEdit *hour1_2;
    QTextEdit *min1_2;
    QTextEdit *day1_2;
    QLabel *label_11;
    QLabel *label_12;
    QTextEdit *year1_2;
    QTextEdit *Sec1_2;
    QLabel *label_13;

    void setupUi(QWidget *parseByTime)
    {
        if (parseByTime->objectName().isEmpty())
            parseByTime->setObjectName(QString::fromUtf8("parseByTime"));
        parseByTime->resize(1250, 800);
        parseByTime->setMinimumSize(QSize(1250, 800));
        parseByTime->setMaximumSize(QSize(1250, 800));
        label = new QLabel(parseByTime);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 635, 91, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Tempus Sans ITC"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        results = new QTextEdit(parseByTime);
        results->setObjectName(QString::fromUtf8("results"));
        results->setGeometry(QRect(19, 20, 1211, 591));
        path = new QTextEdit(parseByTime);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(270, 630, 321, 31));
        saveText = new QCheckBox(parseByTime);
        saveText->setObjectName(QString::fromUtf8("saveText"));
        saveText->setGeometry(QRect(550, 730, 231, 31));
        saveText->setFont(font);
        doc = new QRadioButton(parseByTime);
        doc->setObjectName(QString::fromUtf8("doc"));
        doc->setGeometry(QRect(260, 670, 391, 20));
        doc->setFont(font);
        folder = new QRadioButton(parseByTime);
        folder->setObjectName(QString::fromUtf8("folder"));
        folder->setGeometry(QRect(260, 700, 381, 20));
        folder->setFont(font);
        startParse = new QPushButton(parseByTime);
        startParse->setObjectName(QString::fromUtf8("startParse"));
        startParse->setGeometry(QRect(170, 730, 371, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tempus Sans ITC"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        startParse->setFont(font1);
        Sec1 = new QTextEdit(parseByTime);
        Sec1->setObjectName(QString::fromUtf8("Sec1"));
        Sec1->setGeometry(QRect(730, 630, 41, 31));
        min1 = new QTextEdit(parseByTime);
        min1->setObjectName(QString::fromUtf8("min1"));
        min1->setGeometry(QRect(790, 630, 41, 31));
        label_2 = new QLabel(parseByTime);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(770, 640, 16, 16));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_3 = new QLabel(parseByTime);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(830, 640, 16, 16));
        label_3->setFont(font2);
        hour1 = new QTextEdit(parseByTime);
        hour1->setObjectName(QString::fromUtf8("hour1"));
        hour1->setGeometry(QRect(850, 630, 41, 31));
        label_4 = new QLabel(parseByTime);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(730, 610, 161, 16));
        QFont font3;
        font3.setPointSize(8);
        label_4->setFont(font3);
        day1 = new QTextEdit(parseByTime);
        day1->setObjectName(QString::fromUtf8("day1"));
        day1->setGeometry(QRect(910, 630, 41, 31));
        label_5 = new QLabel(parseByTime);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(950, 640, 16, 16));
        label_5->setFont(font2);
        mon1 = new QTextEdit(parseByTime);
        mon1->setObjectName(QString::fromUtf8("mon1"));
        mon1->setGeometry(QRect(960, 630, 41, 31));
        label_6 = new QLabel(parseByTime);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1000, 640, 16, 16));
        label_6->setFont(font2);
        year1 = new QTextEdit(parseByTime);
        year1->setObjectName(QString::fromUtf8("year1"));
        year1->setGeometry(QRect(1010, 630, 81, 31));
        label_7 = new QLabel(parseByTime);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(910, 610, 181, 16));
        label_8 = new QLabel(parseByTime);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(660, 630, 61, 31));
        label_9 = new QLabel(parseByTime);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(660, 670, 55, 31));
        label_10 = new QLabel(parseByTime);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1000, 680, 16, 16));
        label_10->setFont(font2);
        mon1_2 = new QTextEdit(parseByTime);
        mon1_2->setObjectName(QString::fromUtf8("mon1_2"));
        mon1_2->setGeometry(QRect(960, 670, 41, 31));
        hour1_2 = new QTextEdit(parseByTime);
        hour1_2->setObjectName(QString::fromUtf8("hour1_2"));
        hour1_2->setGeometry(QRect(850, 670, 41, 31));
        min1_2 = new QTextEdit(parseByTime);
        min1_2->setObjectName(QString::fromUtf8("min1_2"));
        min1_2->setGeometry(QRect(790, 670, 41, 31));
        day1_2 = new QTextEdit(parseByTime);
        day1_2->setObjectName(QString::fromUtf8("day1_2"));
        day1_2->setGeometry(QRect(910, 670, 41, 31));
        label_11 = new QLabel(parseByTime);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(950, 680, 16, 16));
        label_11->setFont(font2);
        label_12 = new QLabel(parseByTime);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(830, 680, 16, 16));
        label_12->setFont(font2);
        year1_2 = new QTextEdit(parseByTime);
        year1_2->setObjectName(QString::fromUtf8("year1_2"));
        year1_2->setGeometry(QRect(1010, 670, 81, 31));
        Sec1_2 = new QTextEdit(parseByTime);
        Sec1_2->setObjectName(QString::fromUtf8("Sec1_2"));
        Sec1_2->setGeometry(QRect(730, 670, 41, 31));
        label_13 = new QLabel(parseByTime);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(770, 680, 16, 16));
        label_13->setFont(font2);

        retranslateUi(parseByTime);

        QMetaObject::connectSlotsByName(parseByTime);
    } // setupUi

    void retranslateUi(QWidget *parseByTime)
    {
        parseByTime->setWindowTitle(QCoreApplication::translate("parseByTime", "parseByTime", nullptr));
        label->setText(QCoreApplication::translate("parseByTime", "Enter path:", nullptr));
        saveText->setText(QCoreApplication::translate("parseByTime", "Save logs in to .txt file", nullptr));
        doc->setText(QCoreApplication::translate("parseByTime", "Press this button to parse ONE DOCUMENT!", nullptr));
        folder->setText(QCoreApplication::translate("parseByTime", "Press this button to parse WHOLE FOLDER!", nullptr));
        startParse->setText(QCoreApplication::translate("parseByTime", "Parse!", nullptr));
        label_2->setText(QCoreApplication::translate("parseByTime", ":", nullptr));
        label_3->setText(QCoreApplication::translate("parseByTime", ":", nullptr));
        label_4->setText(QCoreApplication::translate("parseByTime", "Sec       : Min        : Hours", nullptr));
        label_5->setText(QCoreApplication::translate("parseByTime", "/", nullptr));
        label_6->setText(QCoreApplication::translate("parseByTime", "/", nullptr));
        label_7->setText(QCoreApplication::translate("parseByTime", "Day    / Mounth / Year", nullptr));
        label_8->setText(QCoreApplication::translate("parseByTime", "Start time", nullptr));
        label_9->setText(QCoreApplication::translate("parseByTime", "End time", nullptr));
        label_10->setText(QCoreApplication::translate("parseByTime", "/", nullptr));
        label_11->setText(QCoreApplication::translate("parseByTime", "/", nullptr));
        label_12->setText(QCoreApplication::translate("parseByTime", ":", nullptr));
        label_13->setText(QCoreApplication::translate("parseByTime", ":", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parseByTime: public Ui_parseByTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARSEBYTIME_H
