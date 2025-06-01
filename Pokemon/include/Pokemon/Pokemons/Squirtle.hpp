#pragma once

#include "../Pokemon.hpp"

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		class Squirtle :public Pokemon
		{
			private:
				void WaterSplash(Pokemon& target);

			public:
				Squirtle();
				void attack(Pokemon* target)override;
		};
	}
}