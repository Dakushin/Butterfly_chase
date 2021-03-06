
const double pi = 3.14159265359; //!< C'est PI !
//Solution
#include "CPapillon.h"
#include <random>
using namespace std::chrono;
using namespace std;

/*!
 * \param[in] dWorldWidth Largeur de la fen?tre graphique : le papillon s'assure de ne pas sortir de cette espace
 * \param[in] dWorldHeight Hauteur de la fen?tre graphique : le papillon s'assure de ne pas sortir de cette espace
 */
CPapillon::CPapillon(double dWorldWidth, double dWorldHeight, QWidget* parent)
    : m_vSpeed{ 0, 0 }
    , m_ptMax{ dWorldWidth, dWorldHeight }
    , m_ptPos{ 0, 0 }
{
    //Qt // on rentre tous les param?tre du QLabel et on l'affiche
    papillon = new QLabel(parent);
    papillon_img = new QPixmap("butterfly.png");
    papillon->setPixmap(*papillon_img);
    papillon->setScaledContents(true);
    papillon->setGeometry(getPos().x(),getPos().y(), 70, 90);
    papillon->show();
    speed = 1;


    random_device rd;
    default_random_engine gen(rd());

    m_ptPos.setX(uniform_int_distribution<>{0, (int)dWorldWidth}(gen));
    m_ptPos.setY(uniform_int_distribution<>{0, (int)dWorldHeight}(gen));


    m_nLifeTimeInSec = uniform_int_distribution<unsigned int>{ 10, 30 }(gen);
    m_nViewingDistance = uniform_int_distribution<unsigned int>{ 100, 200 }(gen);;

    m_timeBirth = high_resolution_clock::now();
    m_timeLastMove = high_resolution_clock::now();
}

/*! Si le papillon ne voit pas le filet (le filet est ? une distance sup?rieure ? la valeur \c nViewingDistance d?finie
 *  ? la construction du papillon) alors il tourne en rond ? la vitesse de 250 pixels par secondes et 2 radians par secondes.
 *  S'il voit le filet, alors il fuit dans la direction oppos?e en acc?l?rant continuellement de 100 pixels par secondes suppl?mentaires.
 *
 * \param[in] ptNet Position du filet
 *
 * \remark Si le papillon est mort, cette fonction fait "chuter" le papillon ? la vitesse de 1000 pixels par seconde
 */
void CPapillon::MoveAfraidOf(const QPoint& ptNet)
{
    //Temps depuis le dernier mouvement exprim? en millisecondes en pr?cisions double
    duration<float, milli> dur = high_resolution_clock::now() - m_timeLastMove;

    if (isAlive())
    {
        QVecteur2D NetToPos{ (m_ptPos - ptNet) };
        if (NetToPos.Norm() < (double)m_nViewingDistance)
        {
            //Est effray? par le filet
            m_vSpeed.setNorm(m_vSpeed.Norm() + dur.count() / 10);
            m_vSpeed.setOrientation(NetToPos.Orientation());
        }
        else
        {
            m_vSpeed.setNorm(dur.count() / 5);
            m_vSpeed.setOrientation(m_vSpeed.Orientation() + dur.count() / 500);
        }
        
        m_vSpeed.setX(m_vSpeed.x() * speed);
        m_vSpeed.setY(m_vSpeed.y() * speed);

        m_ptPos += m_vSpeed.toPoint();

        if (m_ptPos.x() < 0)
            m_ptPos.setX(0);
        if (m_ptPos.y() < 0)
            m_ptPos.setY(0);
        if (m_ptPos.x() > m_ptMax.x())
            m_ptPos.setX(m_ptMax.x());
        if (m_ptPos.y() > m_ptMax.y())
            m_ptPos.setY(m_ptMax.y());

    }
    else
       m_ptPos += QPoint{ 0, 1 }*dur.count();

    m_timeLastMove = high_resolution_clock::now();
}

/*! V?rifie si le papillon est toujours vivant en comprarant sa dur?e de vie avec le temps ?coul? depuis la cr?ation de l'objet.
 *
 * \return \c true si le papillon est toujours vivant, \c false sinon.
 */
bool CPapillon::isAlive() const
{
    high_resolution_clock::duration dur = high_resolution_clock::now() - m_timeBirth;
    if (dur > seconds(m_nLifeTimeInSec))
        return false;
    else
        return true;
}