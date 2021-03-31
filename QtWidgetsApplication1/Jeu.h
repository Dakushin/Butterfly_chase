#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_Jeu.h"
#include <QTimer>
#include "CPapillon.h"
#include "CEssain.h"
#include <chrono>
#include <memory>
#include "CFillet.h"
#include "TT.h"

class Jeu : public QMainWindow
{
    Q_OBJECT

public:
    Jeu(QWidget* parent = Q_NULLPTR);
    
public slots :

    void Boucle(); //fonction qui gère la boucle de rafraichissement de l'application
    void ModeRapide(); //fonction qui gère le mode rapide (le mode ou les papillon vont plus vite
    void Multiplicateurx1(); //ses 3 fonctions sont des fonctions set une valeur sur le nombre de seconde ou un papillon se génère afin d'en générer plus si on veux
    void Multiplicateurx2();
    void Multiplicateurx3();
    void TTini(); //fonction qui initialise le mode contre la montre qui sera sur une nouvelle fenêtre


protected:
    void mouseMoveEvent(QMouseEvent* event) override; //fonction qui va se lancer à chaque mouvement de souris

private:
    Ui::Jeu ui;
    QTimer* time; //initialise le timer qui va lancer la fonction boucle() toute les 5ms
    CEssain e{ height() }; //initialisation de l'essain qui va contenir les papillons
    CFillet net; //initialisation du fillet qui va contenir les papillons attraper
    QLabel* fillet; //QLabel qui va permettre l'affichage du fillet
    QPixmap* fillet_img_gauche; //QPixmap qui va charger l'image du fillet gauche
    QPixmap* fillet_img_droite; //QPixmap qui va charger l'image du fillet gauche
    QPoint PtMousePos; //Qpoint qui va contenir la postion de la souris
    std::chrono::high_resolution_clock::time_point TimeLastBirth; //chrono qui va gerer le temps entre chaque papillon
    bool bFaceToLeft; //booleen qui va savoir de quelle coté le fillet doit se tourner
    bool pushrapide; //booleen qui va savoir si le bouton moderapide a été appuiller 
    bool rapide; //booleen qui est changer grace à la fonction mode rapide pour que la boucle prenne en compte que le moderapide est activer
    int second; //variable que la fonction des multyplicateur vont changer pour gerer l'apparition des papillons
    TT* Timetrial; //on instantie la classe qui gère le time trial 
};

