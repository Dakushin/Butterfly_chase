#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_TT.h"
#include <QTimer>
#include "CPapillon.h"
#include "CEssain.h"
#include <chrono>
#include <memory>
#include "CFillet.h"
#include <QFile>
#include <QTextStream>


class TT : public QMainWindow
{
    Q_OBJECT

public:
    TT(QWidget* parent = Q_NULLPTR);

public slots:

    void Boucle();
    void close(); //permet de nous rebasculer dans le jeu 


protected:
    void mouseMoveEvent(QMouseEvent* event) override;

private: //si une partie des fonctions ne sont pas commenté, c'est car elle sont deja présente dans la classe jeu

    Ui::TT ui;
    QTimer* time;
    CEssain e{ height() };
    std::chrono::high_resolution_clock::time_point TimeLastBirth;
    CFillet net;
    bool bFaceToLeft;
    QLabel* fillet;
    QPixmap* fillet_img_gauche;
    QPixmap* fillet_img_droite;
    QMouseEvent* ev;
    QPoint PtMousePos;
    bool pushrapide;
    bool rapide;
    int second;
    QFile* file; //fonction Qt qui permet de gerer les fichier
    QByteArray data; //permet de recuperer le contenue de ses fichier
    QString ligne; //rentre le contenue des fichier dans une string
    QTimer* oneshot; //timer qui quand il sera finis nous rebasculera dans le jeu et enregistrera le score
    size_t cnt;
    QWidget* pa; //garde le parent en mémoire
    int timeedit; //permet d'afficher le temps
    int count;//
    int timetoshow;//

};

