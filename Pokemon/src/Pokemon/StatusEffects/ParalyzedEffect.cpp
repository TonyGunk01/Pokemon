#include "../../../include/Pokemon/StatusEffects/ParalyzedEffect.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/StatusEffects/StatusEffectType.hpp"

#include <iostream>

using namespace std;

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void ParalyzedEffect::applyEffect(Pokemon* target)
        {
            cout << target->getName() << " is paralyzed! It may not be able to move!\n";

            turnsLeft = rand() % 3 + 1;
        }

        string ParalyzedEffect::getEffectName()  
        {  
            return "Paralyzed";  
        }

        bool ParalyzedEffect::turnEndEffect(Pokemon* target)
        {
            if (turnsLeft <= 0) 
            {
                clearEffect(target);
                return true; 
            }

            turnsLeft--;

            int paralysis_chance = rand() % 4;

            if (paralysis_chance == 0)
            {
                cout << target->getName() << " is paralyzed! It can't move!\n";
                return false; 
            }

            cout << target->getName() << " shakes off the paralysis momentarily and can move!\n";
            return true;
        }

        void ParalyzedEffect::clearEffect(Pokemon* target)
        {
            cout << target->getName() << " is no longer paralyzed!\n";
            target->clearEffect();
        }
    }
}