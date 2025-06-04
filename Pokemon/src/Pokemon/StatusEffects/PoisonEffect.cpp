#include "../../../include/Pokemon/StatusEffects/PoisonEffect.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/StatusEffects/StatusEffectType.hpp"

#include <iostream>

using namespace std;

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void PoisonEffect::applyEffect(Pokemon* target)
        {
            cout << target->getName() << " is poisoned! Special moves are blocked and normal damage is less effective...\n";
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

            turnsLeft--;

            int burn_chance = rand() % 4;

            if (burn_chance == 0)
            {
                cout << target->getName() << " is still poisoned! It tries its best to knock off the poison through its body....\n";
                return false;
            }

            cout << target->getName() << " braves through the poison as it gets ready to attack again..\n";
            return true;
        }

        void PoisonEffect::clearEffect(Pokemon* target)
        {
            cout << target->getName() << " has recovered from the poison!\n";
            target->clearEffect();
        }
    }
}