/********************************************************************************
** Form generated from reading UI file 'TT.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TT_H
#define UI_TT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TT
{
public:
    QAction *actionVraiment_quitter;
    QAction *actionMode_rapide;
    QAction *actionx1;
    QAction *actionx2;
    QAction *actionx3;
    QAction *actionMode_Contre_la_montre;
    QWidget *centralwidget;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *timeedit;
    QMenuBar *menubar;
    QMenu *menuMode_de_jeu;
    QMenu *menuMode_multyplicateur;
    QMenu *menuQuitter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TT)
    {
        if (TT->objectName().isEmpty())
            TT->setObjectName(QString::fromUtf8("TT"));
        TT->resize(1280, 760);
        TT->setMinimumSize(QSize(1280, 760));
        TT->setMaximumSize(QSize(1280, 760));
        TT->setStyleSheet(QString::fromUtf8(""));
        actionVraiment_quitter = new QAction(TT);
        actionVraiment_quitter->setObjectName(QString::fromUtf8("actionVraiment_quitter"));
        actionMode_rapide = new QAction(TT);
        actionMode_rapide->setObjectName(QString::fromUtf8("actionMode_rapide"));
        actionx1 = new QAction(TT);
        actionx1->setObjectName(QString::fromUtf8("actionx1"));
        actionx2 = new QAction(TT);
        actionx2->setObjectName(QString::fromUtf8("actionx2"));
        actionx3 = new QAction(TT);
        actionx3->setObjectName(QString::fromUtf8("actionx3"));
        actionMode_Contre_la_montre = new QAction(TT);
        actionMode_Contre_la_montre->setObjectName(QString::fromUtf8("actionMode_Contre_la_montre"));
        centralwidget = new QWidget(TT);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background: url(grass.png)"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 231, 41));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 40, 111, 31));
        label_5->setFont(font);
        timeedit = new QLabel(centralwidget);
        timeedit->setObjectName(QString::fromUtf8("timeedit"));
        timeedit->setGeometry(QRect(1210, 0, 71, 51));
        QFont font1;
        font1.setPointSize(30);
        timeedit->setFont(font1);
        TT->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TT);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        menuMode_de_jeu = new QMenu(menubar);
        menuMode_de_jeu->setObjectName(QString::fromUtf8("menuMode_de_jeu"));
        menuMode_multyplicateur = new QMenu(menuMode_de_jeu);
        menuMode_multyplicateur->setObjectName(QString::fromUtf8("menuMode_multyplicateur"));
        menuQuitter = new QMenu(menubar);
        menuQuitter->setObjectName(QString::fromUtf8("menuQuitter"));
        TT->setMenuBar(menubar);
        statusbar = new QStatusBar(TT);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TT->setStatusBar(statusbar);

        menubar->addAction(menuMode_de_jeu->menuAction());
        menubar->addAction(menuQuitter->menuAction());
        menuMode_de_jeu->addAction(actionMode_rapide);
        menuMode_de_jeu->addAction(menuMode_multyplicateur->menuAction());
        menuMode_de_jeu->addAction(actionMode_Contre_la_montre);
        menuMode_multyplicateur->addAction(actionx1);
        menuMode_multyplicateur->addAction(actionx2);
        menuMode_multyplicateur->addAction(actionx3);
        menuQuitter->addAction(actionVraiment_quitter);

        retranslateUi(TT);

        QMetaObject::connectSlotsByName(TT);
    } // setupUi

    void retranslateUi(QMainWindow *TT)
    {
        TT->setWindowTitle(QCoreApplication::translate("TT", "TT", nullptr));
        actionVraiment_quitter->setText(QCoreApplication::translate("TT", "Vraiment quitter", nullptr));
        actionMode_rapide->setText(QCoreApplication::translate("TT", "Mode rapide", nullptr));
        actionx1->setText(QCoreApplication::translate("TT", "x1", nullptr));
        actionx2->setText(QCoreApplication::translate("TT", "x2", nullptr));
        actionx3->setText(QCoreApplication::translate("TT", "x3", nullptr));
        actionMode_Contre_la_montre->setText(QCoreApplication::translate("TT", "Mode Contre-la-montre", nullptr));
        label_4->setText(QCoreApplication::translate("TT", "Record Actuel : X", nullptr));
        label_5->setText(QCoreApplication::translate("TT", "Score : X", nullptr));
        timeedit->setText(QCoreApplication::translate("TT", "60", nullptr));
        menuMode_de_jeu->setTitle(QCoreApplication::translate("TT", "Mode de jeu", nullptr));
        menuMode_multyplicateur->setTitle(QCoreApplication::translate("TT", "Mode multyplicateur", nullptr));
        menuQuitter->setTitle(QCoreApplication::translate("TT", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TT: public Ui_TT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TT_H
