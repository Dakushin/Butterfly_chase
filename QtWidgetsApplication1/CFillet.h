#pragma once
#include <set>
#include <memory>
#include "CPapillon.h"

//!\brief Classe de gestion d'un filet à papillon
class CFillet
{
	//!\brief Alias de type de donnée pour le stockages des papillons
	using butterfliesList = std::set<std::shared_ptr<CPapillon>>;

	butterfliesList m_butterflies;//!<Ensemble des papillons
	//!\brief supprime du filet tous les papillons morts
	void RemoveDead();

public:

	/*!\brief Ajoute un papillon dans le filet
	 * \param[in] pButterfly Pointeur intelligent vers le papillon à ajouter
	 */
	void AppendButterfly(const std::shared_ptr<CPapillon>& pButterfly) { m_butterflies.insert(pButterfly); }

	/*!\brief Retourne le nombre de papillons présent dans le filet
	 *
	 * Cette fonction supprime dans un premier temps tous les papillons morts du filet
	 *
	 * \return Le nombre de papillons vivants dans le filet
	 */
	size_t Count() { RemoveDead(); return m_butterflies.size(); }

};
