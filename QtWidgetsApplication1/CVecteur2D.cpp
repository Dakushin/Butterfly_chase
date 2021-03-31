#include "QVecteur2D.h"

QVecteur2D::QVecteur2D(double x, double y)
{
	setX(x);
	setY(y);
}

QVecteur2D::QVecteur2D(QPoint j)
{
	setX(j.x());
	setY(j.y());
}

double QVecteur2D::Norm() const
{
	return sqrt(x() * x() + y() * y());
}

//!\return L'orientation du vecteur
double QVecteur2D::Orientation() const
{
	return atan2(y(), x());
}

/*!\param norm La nouvelle norme du vecteur.
 *
 * Seule la norme du vecteur est modifiée, son orientation reste inchangée.
 */
void QVecteur2D::setNorm(double norm)
{
	double orient = Orientation();
	setX(norm * cos(orient));
	setY(norm * sin(orient));
}

/*!\param orient La nouvelle orientation du vecteur en radians.
 *
 * Seule l'orientation du vecteur est modifiée, sa norme reste inchangée.
 */
void QVecteur2D::setOrientation(double orient)
{
	double norm = Norm();
	setX(norm * cos(orient));
	setY(norm * sin(orient));
}
