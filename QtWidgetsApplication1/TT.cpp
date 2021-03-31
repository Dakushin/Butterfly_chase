#include "TT.h"

TT::TT(QWidget* parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);
    pa = parent;
    TimeLastBirth = std::chrono::high_resolution_clock::now();
    QTimer::singleShot(60000, this, SLOT(close()));
    e.AppendButterfly(std::make_shared<CPapillon>(this->width(), this->height(), this));
    fillet = new QLabel(this);
    fillet_img_droite = new QPixmap("butterfly-net-right.png");
    fillet_img_gauche = new QPixmap("butterfly-net-left.png");
    fillet->setMouseTracking(true);
    fillet->setPixmap(*fillet_img_droite);
    fillet->setScaledContents(true);
    fillet->setGeometry(this->width() / 2, this->height() / 2, 150, 330);
    fillet->show();
    time = new QTimer(this);
    time->connect(time, SIGNAL(timeout()), this, SLOT(Boucle()));
    time->start(5);
    pushrapide = false;
    rapide = false;
    second = 2;
    QFile file("score.txt"); //permet d'ouvrir le fichier
    file.open(QIODevice::ReadOnly); //ouvre le fichier en lecture
    data = file.readAll(); //lit le fichier
    ligne = QString(data); //rentre le contenue du fichier dans ligne
    cnt = 0;
    count = 0;
    timetoshow = 60;
}

void TT::Boucle()
{
    count++;
    if (count == 195) //compte le nombre de fois ou on passe dans la boucle 
    {
        timetoshow--; //toute les 1 sec on enleve 1
        count = 0;
    }
    auto pPapillon = e.getFirst();
    while (pPapillon)
    {
        pPapillon->MoveAfraidOf(PtMousePos);
        pPapillon->getLabel()->move(pPapillon->getPos());
        pPapillon = e.getNext(pPapillon);
    }

    if (bFaceToLeft)
    {
        fillet->move(PtMousePos.x() - 75, PtMousePos.y() - 50);
        fillet->setPixmap(*fillet_img_gauche);
    }
    else
    {
        fillet->move(PtMousePos.x() - 75, PtMousePos.y() - 50);
        fillet->setPixmap(*fillet_img_droite);
    }



    
    //Affichage Qt
    ui.label_4->setText("Record Actuel : " + ligne);
    ui.label_5->setText("Score : " + QString::number(cnt));
    ui.timeedit->setText(QString::number(timetoshow)); 

    if ((std::chrono::high_resolution_clock::now() - TimeLastBirth) >= std::chrono::seconds(second))
    {
        TimeLastBirth = std::chrono::high_resolution_clock::now();
        //!\todo Ajouter ici un nouveau papillon à l'essaim
        //Solution
         e.AppendButterflyS(std::make_shared<CPapillon>(width(), height(), this));
      
        //Fin Solution
    }

}

void TT::mouseMoveEvent(QMouseEvent* event)
{
    this->setMouseTracking(true);

    if (event->globalPos().x() <= PtMousePos.x())
    {
        bFaceToLeft = true;
    }
    else
    {
        bFaceToLeft = false;
    }
    PtMousePos.setX(event->x());
    PtMousePos.setY(event->y());
    {
        //!\todo Créer ici une boucle sur tous les papillons de l'essaim pour voir s'il sont à moins de 25 pixels du filet. Si c'est le cas alors les retirer de l'essaim et les ajouter au filet.
        //Solution
        auto pButterfly = e.getFirst();
        while (pButterfly)
        {
            auto pNext = e.getNext(pButterfly);
            //calcul de la longueur entre tous les papillon et le fillet
            QPoint p_lenght = pButterfly->getPos() - PtMousePos;
            float norm = sqrt(p_lenght.x() * p_lenght.x() + p_lenght.y() * p_lenght.y());


            if (norm <= 100)
            {
                e.RemoveButterfly(pButterfly);
                pButterfly->RemoveFromScreen();
                net.AppendButterfly(pButterfly);
                cnt++;
            }
            pButterfly = pNext;
        }
    }


}

void TT::close()
{
    QTextStream score("score.txt", QIODevice::WriteOnly); //ecrit le score sur le fichier
    score.setCodec("UTF-8"); //codage du fichier
    score << QString::number(cnt) << endl; //ecrit
    this->hide(); //ferme la fenètre
    pa->show(); //reouvre l'autre
}

