#pragma once

#include "../Pokemon.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		class Zubat :public Pokemon
		{
			private:
				void supersonic(Pokemon& target);

			public:
				Zubat();
				void attack(Pokemon* target)override;
		};
	}
}