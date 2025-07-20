#pragma once

#include "StatusEffect.hpp"

namespace N_Pokemon
{
	namespace N_StatusEffects
	{
		class PoisonEffect : public N_Battle::StatusEffect
		{
		private:
			int turnsLeft;
			int poison_dmg;
			int poison_start;

		public:
			void applyEffect(Pokemon* target) override;
			std::string getEffectName() override;
			bool turnEndEffect(Pokemon* target) override;
			void clearEffect(Pokemon* target) override;
		};
	}
}