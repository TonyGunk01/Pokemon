#include "../../../include/Pokemon/StatusEffects/PoisonEffect.hpp"
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
        void PoisonEffect::applyEffect(Pokemon* target)
        {
            poison_dmg = rand() % 10 + 5;
            target->health -= poison_dmg;
            cout << "\n\n" << target->getName() << " is poisoned";
            Utility::waitEffect();
            cout << "\n\n" << target->getName() << " took " << poison_dmg << " damage!\n";
            turnsLeft = rand() % 3 + 1;
        }

        string PoisonEffect::getEffectName()
        {
            return "Poison";
        }

        bool PoisonEffect::turnEndEffect(Pokemon* target)
        {
            if (turnsLeft <= 0)
            {
                clearEffect(target);
                return true;
            }

            if (poison_start > 0)
            {
                cout << "\n" << target->getName() << " is still poisoned! It looses " << poison_dmg << " health as it tries to shake off from the poison\n\n";
				Utility::delay(2000);
                turnsLeft--;
                return false;
            }

            poison_start++;
        }

        void PoisonEffect::clearEffect(Pokemon* target)
        {
            cout << "\n" << target->getName() << " has recovered from the poison!\n";
            target->clearEffect();
        }
    }
}