#include "QtWidgetsApplication1.h"
#include "Jeu.h"
#include <QtWidgets/QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    /*QLabel* papillon;
    QPixmap* papillon_img;
    papillon = new QLabel(&w);
    papillon_img = new QPixmap("butterfly.png");
    papillon->setPixmap(*papillon_img);
    papillon->setFixedHeight(90);
    papillon->setFixedWidth(70);*/
    w.show();
    return a.exec();
}
