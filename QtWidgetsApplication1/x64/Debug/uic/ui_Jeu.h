/********************************************************************************
** Form generated from reading UI file 'Jeu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JEU_H
#define UI_JEU_H

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

class Ui_Jeu
{
public:
    QAction *actionVraiment_quitter;
    QAction *actionMode_rapide;
    QAction *actionx1;
    QAction *actionx2;
    QAction *actionx3;
    QAction *actionMode_Contre_la_montre;
    QWidget *centralwidget;
    QLabel *Textpapillon;
    QMenuBar *menubar;
    QMenu *menuMode_de_jeu;
    QMenu *menuMode_multyplicateur;
    QMenu *menuQuitter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Jeu)
    {
        if (Jeu->objectName().isEmpty())
            Jeu->setObjectName(QString::fromUtf8("Jeu"));
        Jeu->resize(1280, 760);
        Jeu->setMinimumSize(QSize(1280, 760));
        Jeu->setMaximumSize(QSize(1280, 760));
        Jeu->setStyleSheet(QString::fromUtf8(""));
        actionVraiment_quitter = new QAction(Jeu);
        actionVraiment_quitter->setObjectName(QString::fromUtf8("actionVraiment_quitter"));
        actionMode_rapide = new QAction(Jeu);
        actionMode_rapide->setObjectName(QString::fromUtf8("actionMode_rapide"));
        actionx1 = new QAction(Jeu);
        actionx1->setObjectName(QString::fromUtf8("actionx1"));
        actionx2 = new QAction(Jeu);
        actionx2->setObjectName(QString::fromUtf8("actionx2"));
        actionx3 = new QAction(Jeu);
        actionx3->setObjectName(QString::fromUtf8("actionx3"));
        actionMode_Contre_la_montre = new QAction(Jeu);
        actionMode_Contre_la_montre->setObjectName(QString::fromUtf8("actionMode_Contre_la_montre"));
        centralwidget = new QWidget(Jeu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background: url(\"grass.png\") repeat-y;"));
        Textpapillon = new QLabel(centralwidget);
        Textpapillon->setObjectName(QString::fromUtf8("Textpapillon"));
        Textpapillon->setGeometry(QRect(10, 10, 451, 41));
        QFont font;
        font.setPointSize(20);
        Textpapillon->setFont(font);
        Jeu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Jeu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        menuMode_de_jeu = new QMenu(menubar);
        menuMode_de_jeu->setObjectName(QString::fromUtf8("menuMode_de_jeu"));
        menuMode_multyplicateur = new QMenu(menuMode_de_jeu);
        menuMode_multyplicateur->setObjectName(QString::fromUtf8("menuMode_multyplicateur"));
        menuQuitter = new QMenu(menubar);
        menuQuitter->setObjectName(QString::fromUtf8("menuQuitter"));
        Jeu->setMenuBar(menubar);
        statusbar = new QStatusBar(Jeu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Jeu->setStatusBar(statusbar);

        menubar->addAction(menuMode_de_jeu->menuAction());
        menubar->addAction(menuQuitter->menuAction());
        menuMode_de_jeu->addAction(actionMode_rapide);
        menuMode_de_jeu->addAction(menuMode_multyplicateur->menuAction());
        menuMode_de_jeu->addAction(actionMode_Contre_la_montre);
        menuMode_multyplicateur->addAction(actionx1);
        menuMode_multyplicateur->addAction(actionx2);
        menuMode_multyplicateur->addAction(actionx3);
        menuQuitter->addAction(actionVraiment_quitter);

        retranslateUi(Jeu);
        QObject::connect(actionVraiment_quitter, SIGNAL(triggered()), Jeu, SLOT(close()));
        QObject::connect(actionMode_rapide, SIGNAL(triggered()), Jeu, SLOT(ModeRapide()));
        QObject::connect(actionx1, SIGNAL(triggered()), Jeu, SLOT(Multiplicateurx1()));
        QObject::connect(actionx2, SIGNAL(triggered()), Jeu, SLOT(Multiplicateurx2()));
        QObject::connect(actionx3, SIGNAL(triggered()), Jeu, SLOT(Multiplicateurx3()));
        QObject::connect(actionMode_Contre_la_montre, SIGNAL(triggered()), Jeu, SLOT(TTini()));

        QMetaObject::connectSlotsByName(Jeu);
    } // setupUi

    void retranslateUi(QMainWindow *Jeu)
    {
        Jeu->setWindowTitle(QCoreApplication::translate("Jeu", "Jeu", nullptr));
        actionVraiment_quitter->setText(QCoreApplication::translate("Jeu", "Vraiment quitter", nullptr));
        actionMode_rapide->setText(QCoreApplication::translate("Jeu", "Mode rapide", nullptr));
        actionx1->setText(QCoreApplication::translate("Jeu", "x1", nullptr));
        actionx2->setText(QCoreApplication::translate("Jeu", "x2", nullptr));
        actionx3->setText(QCoreApplication::translate("Jeu", "x3", nullptr));
        actionMode_Contre_la_montre->setText(QCoreApplication::translate("Jeu", "Mode Contre-la-montre", nullptr));
        Textpapillon->setText(QCoreApplication::translate("Jeu", "Vous avez attrap\303\251 X Papillons", nullptr));
        menuMode_de_jeu->setTitle(QCoreApplication::translate("Jeu", "Mode de jeu", nullptr));
        menuMode_multyplicateur->setTitle(QCoreApplication::translate("Jeu", "Mode multyplicateur", nullptr));
        menuQuitter->setTitle(QCoreApplication::translate("Jeu", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Jeu: public Ui_Jeu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JEU_H
