#pragma once
#include <set>
#include <memory>
#include "CPapillon.h"

//!\brief Classe de gestion d'un essaim de papillons
class CEssain
{
	//!\brief Alias de type de donnée pour le stockages des papillons
	using butterfliesList = std::set<std::shared_ptr<CPapillon>>;

	butterfliesList m_butterflies;//!<Ensemble des papillons
	float m_fMaxHeight;//!<Hauteur de la fenêtre d'affichage

public:
	/*!\brief Constructeur
	 * \param[in] fMaxHeight Hauteur de la fenêtre d'affichage. Ce paramètre
	 * est utilisé pour savoir si un papillon mort est en dehors de l'écran.
	 * Si c'est le cas, il sera supprimé automatiquement lors de l'appel de la
	 * fonction RemoveOutOfScreenDead()
	 */
	CEssain(float fMaxHeight) { m_fMaxHeight = fMaxHeight; }

	/*!\brief Ajoute un papillon dans l'essaim
	* \param[in] pButterfly Pointeur intelligent vers le papillon à ajouter
	*/
	void AppendButterfly(const std::shared_ptr<CPapillon>& pButterfly);
	void AppendButterflyS(const std::shared_ptr<CPapillon>& pButterfly); //fonction qui va rajouté un papillon en lui activant le mode speed
	void AppendButterflyTT(const std::shared_ptr<CPapillon>& pButterfly);
	/*!\brief Supprime un papillon de l'essaim
	* \param[in] pButterfly Pointeur intelligent vers le papillon à supprimer
	*/
	void RemoveButterfly(const std::shared_ptr<CPapillon>& pButterfly);
	/*!\brief Supprime tous les papillons morts qui sont en dehors de l'écran.
	 * \see CSwarm::CSwarm
	 */
	void RemoveOutOfScreenDead();

	//!\brief Retourne le premier papillon de l'essaim
	std::shared_ptr<CPapillon> getFirst();
	//!\brief Retourne le papillon suivant dans l'essaim
	std::shared_ptr<CPapillon> getNext(const std::shared_ptr<CPapillon>& pButterfly);
};