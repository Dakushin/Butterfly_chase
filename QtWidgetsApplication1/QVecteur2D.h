#pragma once
#include <qvector2d.h>

class QVecteur2D: public QVector2D //classe qui a pour but de rajout� quelque fonction du TP5 dans un QVector2D
{
public : 
	QVecteur2D(double, double);
	QVecteur2D(QPoint);
	double Norm() const; //recup�re la norm d'un vecteur
	double Orientation() const; //recup�re l'orientation

	void setNorm(double norm); //permet de rentrer une norm
	void setOrientation(double orient); //permet de rentrer une orientation
};

