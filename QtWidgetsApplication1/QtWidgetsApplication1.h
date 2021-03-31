#pragma once
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "Jeu.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);


public slots :

    void click1() { QMessageBox::aboutQt(this); } //about Qt qui doit être sur toute les application qui utilise Qt
    void play() { //fonction qui va afficher la fenêtre de jeu
        j = new Jeu;
        j->show();
    }

private:
     Ui::QtWidgetsApplication1Class ui;
     Jeu* j; //on instantie la classe de la fen^tre

};
