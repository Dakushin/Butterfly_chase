#pragma once
#include <QtWidgets/qlabel.h>
#include "QVecteur2D.h"
#include <chrono>


class  CPapillon
{
	QPoint m_ptMax; //!<Point inférieur droit de la fenêtre -> permet de limiter la position
	QPoint m_ptPos; //!<Position du papillon 
	QVecteur2D m_vSpeed; //!<Vitesse instantanée du papillon
	unsigned int m_nViewingDistance; //!<Distance de détection du filet par le papillon
	std::chrono::high_resolution_clock::time_point m_timeBirth; //!<Temps auquel le papillon a été créé
	std::chrono::high_resolution_clock::time_point m_timeLastMove; //!<Temps de son dernier mouvement -> permet de gérer la vitesse
	unsigned int m_nLifeTimeInSec;  //!<Sa durée de vie en secondes
	QLabel* papillon; //QLabel qui va contenir l'image du papillon
	QPixmap* papillon_img;
	int speed; //variable qui permet de multyplié la vittesse 
	bool TT =  false; //bool qui va dire que on est en TT est désactive la mort des papillons

public:
	//!\brief Constructeur du papillon
	CPapillon(double dWorldWidth, double dWorldHeight, QWidget* parent);

	//!\{
	//!\brief Accesseurs
	QPoint getPos() const { return m_ptPos; }
	QVecteur2D getSpeed() const { return m_vSpeed; }
	QLabel* getLabel() const { return papillon; }
	//!\}

	//!\brief Determine si le papillon est vivant
	bool isAlive() const;

	//!\brief Déplace le papillon en évitant le filet
	void MoveAfraidOf(const QPoint& ptNet);
	void RemoveFromScreen() { papillon->hide(); } //permet d'enlever le papillon de l'ecran
	void Setspeed(int i) { speed = i; } //permet de modifier la vitesse
	void setTT(bool t) { TT = t; }
	bool getTT() { return TT; }
};
