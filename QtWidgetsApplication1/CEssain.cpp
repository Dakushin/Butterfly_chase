#include "CEssain.h"

using namespace std;

void CEssain::AppendButterfly(const std::shared_ptr<CPapillon>& pButterfly)
{
    m_butterflies.insert(pButterfly);
 
}

void CEssain::AppendButterflyS(const std::shared_ptr<CPapillon>& pButterfly)
{
    m_butterflies.insert(pButterfly);
    pButterfly->Setspeed(2);
}

void CEssain::AppendButterflyTT(const std::shared_ptr<CPapillon>& pButterfly)
{
    m_butterflies.insert(pButterfly);
    pButterfly->Setspeed(2);
    pButterfly->setTT(true);
}


void CEssain::RemoveButterfly(const std::shared_ptr<CPapillon>& pButterfly)
{
    m_butterflies.erase(pButterfly);
}

void CEssain::RemoveOutOfScreenDead()
{
    auto it = m_butterflies.begin();
    while (it != m_butterflies.end())
    {
        if (!(*it)->isAlive() && (*it)->getPos().y() > m_fMaxHeight)
            it = m_butterflies.erase(it);
        else
            it++;
    }
}

/*!\return Un pointeur intelligent vers le premier papillon de l'essaim
 * \remark Si l'essaim est vide, la fonction retourne nullptr
 * \remark L'ordre des papillons n'a aucune signification et est spécifique à l'implémentation
 * \see getNext
 */
std::shared_ptr<CPapillon> CEssain::getFirst()
{
    if (m_butterflies.empty())
        return nullptr;
    return *m_butterflies.begin();
}

/*!\param[in] pButterfly Un pointeur intelligent vers un papillon présent dans l'essaim. Un premier pointeur peut être retrouvé par la fonction getFirst.
 * \return Un pointeur intelligent vers le papillon suivant de l'essaim
 * \remark S'il n'y a pas d'autre papillon, ou si le papillon \p pButterfly n'est pas dans l'essaim, la fonction retourne nullptr
 * \remark L'ordre des papillons n'a aucune signification et est spécifique à l'implémentation
 * \see getFirst
 */
std::shared_ptr<CPapillon> CEssain::getNext(const std::shared_ptr<CPapillon>& pButterfly)
{
    auto it = m_butterflies.find(pButterfly);
    if (it == m_butterflies.end())
        return nullptr;
    it++;
    if (it == m_butterflies.end())
        return nullptr;
    return *it;
}
