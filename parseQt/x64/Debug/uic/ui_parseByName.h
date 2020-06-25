/********************************************************************************
** Form generated from reading UI file 'parseByName.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARSEBYNAME_H
#define UI_PARSEBYNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parseByName
{
public:
    QTextEdit *results;
    QPushButton *start;
    QCheckBox *saveText;
    QRadioButton *folder;
    QRadioButton *doc;
    QLabel *label;
    QTextEdit *path;
    QLabel *label_2;
    QTextEdit *name;

    void setupUi(QWidget *parseByName)
    {
        if (parseByName->objectName().isEmpty())
            parseByName->setObjectName(QString::fromUtf8("parseByName"));
        parseByName->resize(1250, 800);
        parseByName->setMinimumSize(QSize(1250, 0));
        parseByName->setMaximumSize(QSize(1250, 800));
        results = new QTextEdit(parseByName);
        results->setObjectName(QString::fromUtf8("results"));
        results->setGeometry(QRect(20, 20, 1211, 591));
        start = new QPushButton(parseByName);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(50, 630, 361, 151));
        QFont font;
        font.setPointSize(14);
        start->setFont(font);
        saveText = new QCheckBox(parseByName);
        saveText->setObjectName(QString::fromUtf8("saveText"));
        saveText->setGeometry(QRect(430, 630, 171, 20));
        folder = new QRadioButton(parseByName);
        folder->setObjectName(QString::fromUtf8("folder"));
        folder->setGeometry(QRect(430, 760, 151, 20));
        doc = new QRadioButton(parseByName);
        doc->setObjectName(QString::fromUtf8("doc"));
        doc->setGeometry(QRect(430, 730, 151, 20));
        label = new QLabel(parseByName);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 660, 71, 31));
        path = new QTextEdit(parseByName);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(500, 660, 381, 31));
        label_2 = new QLabel(parseByName);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(900, 660, 81, 31));
        name = new QTextEdit(parseByName);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(980, 660, 211, 31));

        retranslateUi(parseByName);

        QMetaObject::connectSlotsByName(parseByName);
    } // setupUi

    void retranslateUi(QWidget *parseByName)
    {
        parseByName->setWindowTitle(QCoreApplication::translate("parseByName", "parseByName", nullptr));
        start->setText(QCoreApplication::translate("parseByName", "Parse!", nullptr));
        saveText->setText(QCoreApplication::translate("parseByName", "Save result in to txt file", nullptr));
        folder->setText(QCoreApplication::translate("parseByName", "For WHOLE FOLDER", nullptr));
        doc->setText(QCoreApplication::translate("parseByName", "For ONE DOCUMENT", nullptr));
        label->setText(QCoreApplication::translate("parseByName", "Enter path:", nullptr));
        label_2->setText(QCoreApplication::translate("parseByName", "Enter name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parseByName: public Ui_parseByName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARSEBYNAME_H
