#pragma once

#include <string>

using namespace std;

namespace N_Pokemon
{
    class Pokemon;
}

namespace N_Battle
{
    class StatusEffect
    {
        public:
            virtual void applyEffect(N_Pokemon::Pokemon* target) = 0;

            virtual string getEffectName() = 0;

            virtual bool turnEndEffect(N_Pokemon::Pokemon* target) = 0;

            virtual void clearEffect(N_Pokemon::Pokemon* target) = 0;

            virtual ~StatusEffect() = 0;
    };
}
