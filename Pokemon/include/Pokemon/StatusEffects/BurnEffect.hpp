#pragma once

#include "StatusEffect.hpp"

namespace N_Pokemon
{
	namespace N_StatusEffects
	{
		class BurnEffect : public N_Battle::StatusEffect
		{
			private:
				int turnsLeft;
				int burn_dmg;
				int burn_start = 0;

			public:
				void applyEffect(Pokemon* target) override;
				std::string getEffectName() override;
				bool turnEndEffect(Pokemon* target) override;
				void clearEffect(Pokemon* target) override;
		};
	}
}