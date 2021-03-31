#include "CFillet.h"
//Solution
void CFillet::RemoveDead()
{
    auto it = m_butterflies.begin();
    while (it != m_butterflies.end())
    {
        if (!(*it)->isAlive())
            it = m_butterflies.erase(it);
        else
            it++;
    }
}
//Fin Solution
