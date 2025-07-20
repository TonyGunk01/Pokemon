#include "../../../include/Pokemon/StatusEffects/SleepEffect.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Pokemon/StatusEffects/StatusEffectType.hpp"
#include "../../../include/Utility/Utility.hpp"

#include <iostream>

using namespace std;
using namespace N_Utility;

int sleep_start;

namespace N_Pokemon
{
    namespace N_StatusEffects
    {
        void SleepEffect::applyEffect(Pokemon* target)
        {
            cout << "\n" << target->getName() << " is sleeping! It'll take a while for it to wake up";
			Utility::waitEffect();
			cout << "\n";

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

            else if (sleep_start > 0)
            {
                cout << "\n" << target->getName() << " is in a deep sleep! It can't move!\n";
                Utility::delay(2000);
                turnsLeft--;
                return false;
            }

            sleep_start++;
        }

        void SleepEffect::clearEffect(Pokemon* target)
        {
            cout << "\n" << target->getName() << " is now awake!\n";
            Utility::delay(2000);
            target->clearEffect();
        }
    }
}