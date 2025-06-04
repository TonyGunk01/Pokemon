#include "../../../include/Pokemon/StatusEffects/SleepEffect.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/StatusEffects/StatusEffectType.hpp"

#include <iostream>

using namespace std;

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void SleepEffect::applyEffect(Pokemon* target)
        {
            cout << target->getName() << " is sleeping! It'll take a while for it to wake up...\n";

            turnsLeft = rand() % 3 + 1;
        }

        string SleepEffect::getEffectName()
        {
            return "Sleep";
        }

        bool SleepEffect::turnEndEffect(Pokemon* target)
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
                cout << target->getName() << " is now fast asleep! It'll take a while for it to wake up..!\n";
                return false;
            }

            cout << target->getName() << " brisks off the sleepiness vigourously and can move!\n";
            return true;
        }

        void SleepEffect::clearEffect(Pokemon* target)
        {
            cout << target->getName() << " is now awake!\n";
            target->clearEffect();
        }
    }
}