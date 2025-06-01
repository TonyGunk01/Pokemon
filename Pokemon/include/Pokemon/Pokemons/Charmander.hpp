#pragma once

#include "../Pokemon.hpp"

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		class Charmander :public Pokemon
		{
			private:
				void flameBrust(Pokemon& target);

			public:
				Charmander();
				void attack(Pokemon* target)override;
		};
	}
}