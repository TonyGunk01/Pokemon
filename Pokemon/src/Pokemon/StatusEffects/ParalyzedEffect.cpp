#include "../../../include/Pokemon/StatusEffects/ParalyzedEffect.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/StatusEffects/StatusEffectType.hpp"
#include "../../../include/Utility/Utility.hpp"

#include <iostream>

using namespace std;
using namespace N_Utility;

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void ParalyzedEffect::applyEffect(Pokemon* target)
        {
            cout << "\n" << target->getName() << " is paralyzed! It may not be able to move";
            Utility::waitEffect();
            cout << "\n";

            turnsLeft = rand() % 3 + 1;
            turnEndEffect(target);
        }

        string ParalyzedEffect::getEffectName()  
        {  
            return "Paralyze";  
        }

        bool ParalyzedEffect::turnEndEffect(Pokemon* target)
        {
            if (turnsLeft <= 0) 
            {
                clearEffect(target);
                return true; 
            }

            else
            {
                if (paralysis_start > 0)
                {
                    cout << "\n" << target->getName() << " is still paralyzed! It can't move!\n";
					Utility::delay(2000);
                    turnsLeft--;
                    return false;
                }
            }

            paralysis_start++;
        }

        void ParalyzedEffect::clearEffect(Pokemon* target)
        {
            cout << "\n" << target->getName() << " is no longer paralyzed!\n";
            Utility::delay(2000);
            target->clearEffect();
        }
    }
}