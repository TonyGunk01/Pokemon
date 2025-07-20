#pragma once

#include "StatusEffect.hpp"

namespace N_Pokemon
{
	namespace N_StatusEffects
	{
		class SleepEffect : public N_Battle::StatusEffect
		{
			private: 
				int turnsLeft;
				int sleep_start = 0;

			public:
				void applyEffect(Pokemon* target) override;
				std::string getEffectName() override;
				bool turnEndEffect(Pokemon* target) override;
				void clearEffect(Pokemon* target) override;
		};
	}
}