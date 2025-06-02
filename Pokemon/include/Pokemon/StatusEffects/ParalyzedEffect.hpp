#pragma once

#include "StatusEffect.hpp"

namespace N_Pokemon
{
	namespace N_StatusEffects
	{
		class ParalyzedEffect : public N_Battle::StatusEffect
		{
			private:
				int turnsLeft;

			public:
				void applyEffect(Pokemon* target) override;
				std::string getEffectName() const override;
				bool turnEndEffect(Pokemon* target) override;
				void clearEffect(Pokemon* target) override;
		};
	}
}