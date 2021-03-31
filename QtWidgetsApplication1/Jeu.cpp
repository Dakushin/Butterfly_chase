#include "Jeu.h"
#include <qdebug.h>
#include <string>

Jeu::Jeu(QWidget* parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);
    TimeLastBirth = std::chrono::high_resolution_clock::now(); //on dit le premier papillon viens de naitre, on enregistre ça date de naissance
    e.AppendButterfly(std::make_shared<CPapillon>(this->width(), this->height(), this)); //on rentre le premier papillon
    fillet = new QLabel(this);                                                                                               // |
    fillet_img_droite = new QPixmap("butterfly-net-right.png");                                                              // |
    fillet_img_gauche = new QPixmap("butterfly-net-left.png");                                                               // |
    fillet->setMouseTracking(true);//fonction qui va permettre au fillet de suivre la souris                                 // |
    fillet->setPixmap(*fillet_img_droite);                                                                                   // |________________> on rentre tous les paramètres du QLabel
    fillet->setScaledContents(true);                                                                                         // |
    fillet->setGeometry(640, 380, 150, 330);                                                                                 // |
    fillet->show();                                                                                                          // |
    time = new QTimer(this); //on initialise notre Qtimer qui va gerer la boucle
    time->connect(time, SIGNAL(timeout()), this, SLOT(Boucle())); //on connect son signal avec le slot de la boucle
    time->start(5); //on lui dit qu'il soit se lancer toute les 5 ms
    pushrapide = false; // on initialise les variable propres au fonctions
    rapide = false;
    second = 3;
}

void Jeu::Boucle()
{
   
    auto pPapillon = e.getFirst(); //on recupère le premier papillons de l'essain
    while (pPapillon)
    {
        pPapillon->MoveAfraidOf(PtMousePos); //fonction qui va le faire partir à l'oposé du fillet
        pPapillon->getLabel()->move(pPapillon->getPos()); //fonction qui va gerer l'affichage
        pPapillon = e.getNext(pPapillon); //on prend le suivant
    }
    
    if (bFaceToLeft) //gère la position du filet et son orientation
    {
        fillet->move(PtMousePos.x() -75, PtMousePos.y() - 50); 
        fillet->setPixmap(*fillet_img_gauche);
    }
    else
    {
        fillet->move(PtMousePos.x() -75, PtMousePos.y() - 50);
        fillet->setPixmap(*fillet_img_droite);
    }
    

    size_t cnt = 0; 
    //la variable compte les papillons
    cnt = net.Count();
    ui.Textpapillon->setText("Vous avez attraper " + QString::number(cnt) + " Papillon" + (cnt > 1 ? "s" : "")); //gère l'affichage du nombre de papillon qu'on a attraper

    if ((std::chrono::high_resolution_clock::now() - TimeLastBirth) >= std::chrono::seconds(second)) //quand le temps le temps passe après le dernier papillon, un autre est crée
    {
        TimeLastBirth = std::chrono::high_resolution_clock::now();
        //!\todo Ajouter ici un nouveau papillon à l'essaim
        //Solution
        if (rapide)
            e.AppendButterflyS(std::make_shared<CPapillon>(width(), height(), this));
        else
            e.AppendButterfly(std::make_shared<CPapillon>(width(), height(), this));
        //Fin Solution
    }
}


void Jeu::Multiplicateurx1() //fonction qui multiplie la frequence d'apparition par 1
{
    second = 3;
}

void Jeu::Multiplicateurx2() //fonction qui multiplie la frequence d'apparition par 2
{
    second = 2;
}

void Jeu::Multiplicateurx3()//fonction qui multiplie la frequence d'apparition par 3
{
    second = 1;
}

void Jeu::TTini() //fonction qui fais apparaitre la fenêtre 
{
    Timetrial = new TT(this);
    Timetrial->show();
    this->hide();
}

void Jeu::mouseMoveEvent(QMouseEvent* event) 
{
    this->setMouseTracking(true); //permet de suivre la position de la souris

    if (event->x() <= PtMousePos.x()) //gère l'orientation du fillet 
    {
        bFaceToLeft = true;
    }
    else
    {
        bFaceToLeft = false;
    }
    PtMousePos.setX(event->x()); //on recupère la position de la souris
    PtMousePos.setY(event->y());
    {
        auto pButterfly = e.getFirst(); //boucle qui gère la distance entre le fillet et les papillons, si elle est trop courte, les papillons vont dans le fillet
        while (pButterfly)
        {
            auto pNext = e.getNext(pButterfly);
            //calcul de la longueur entre tous les papillon et le fillet
            QPoint p_lenght = pButterfly->getPos() - PtMousePos;
            float norm =  sqrt(p_lenght.x() * p_lenght.x() + p_lenght.y() * p_lenght.y());


            if (norm <= 100)
            {
                e.RemoveButterfly(pButterfly);
                pButterfly->RemoveFromScreen();
                net.AppendButterfly(pButterfly);
            }
            pButterfly = pNext;
        }
    }
}

void Jeu::ModeRapide() //fonction qui permet de passer au mode rapide
{
    if (!pushrapide)
    {
        rapide = true;
        pushrapide = true;
    }
    else {
        rapide = false;
        pushrapide = false;
    }
    

}

