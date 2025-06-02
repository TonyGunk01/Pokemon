#pragma once

#include <string>

#include "../Pokemon.hpp"

using namespace std;
using namespace N_Pokemon;

namespace N_Battle
{
    class StatusEffect
    {
        public:
            virtual void applyEffect(Pokemon* target) = 0;

            virtual string getEffectName() = 0;

            virtual bool turnEndEffect(Pokemon* target) = 0;

            virtual void clearEffect(Pokemon* target) = 0;

            virtual ~StatusEffect() = 0;
    };
}
