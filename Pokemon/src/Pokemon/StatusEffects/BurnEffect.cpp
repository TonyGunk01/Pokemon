#include "../../../include/Pokemon/StatusEffects/BurnEffect.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/StatusEffects/StatusEffectType.hpp"

#include <iostream>

using namespace std;

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void BurnEffect::applyEffect(Pokemon* target)
        {
            cout << target->getName() << " is burning! It loses health every turn\n";
            target->health -= 5;
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

            turnsLeft--;

            int burn_chance = rand() % 4;

            if (burn_chance == 0)
            {
                cout << target->getName() << " is still burning! He looses some health as he tries to extinguish the flames..!\n";
                return false;
            }

            cout << target->getName() << " braves through the hot flames as it tries to attack again..\n";
            return true;
        }

        void BurnEffect::clearEffect(Pokemon* target)
        {
            cout << target->getName() << " has stopped burning!\n";
            target->clearEffect();
        }
    }
}