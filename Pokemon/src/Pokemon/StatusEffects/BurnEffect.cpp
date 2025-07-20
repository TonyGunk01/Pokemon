#include "../../../include/Pokemon/StatusEffects/BurnEffect.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/StatusEffects/StatusEffectType.hpp"
#include "../../../include/Utility/Utility.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;
using namespace N_Utility;

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void BurnEffect::applyEffect(Pokemon* target)
        {
            burn_dmg = rand() % 10 + 5;
            target->health -= burn_dmg;
            cout << "\n" << target->getName() << " is burning";
            Utility::waitEffect();
            cout << "\n\n" << target->getName() <<" took " << burn_dmg << " damage!\n";
            turnsLeft = rand() % 3 + 1;
        }

        string BurnEffect::getEffectName()
        {
            return "Burn";
        }

        bool BurnEffect::turnEndEffect(Pokemon* target)
        {
            if (turnsLeft <= 0)
            {
                clearEffect(target);
                return true;
            }

            if (burn_start > 0)
            {
                cout << "\n" << target->getName() << " is still burning! It looses " << burn_dmg << " health as it tries to remove the flames";
                Utility::waitEffect();
                cout << "\n";
                turnsLeft--;
                return false;
            }

            burn_start++;
        }

        void BurnEffect::clearEffect(Pokemon* target)
        {
            cout << "\n" << target->getName() << " has stopped burning!\n";
            target->clearEffect();
        }
    }
}