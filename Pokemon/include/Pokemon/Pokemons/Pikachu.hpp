#pragma once

#include "../Pokemon.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		class Pikachu :public Pokemon
		{
			private:
				void thunderShock(Pokemon& target);

			public:
				Pikachu();
				void attack(Pokemon* target)override;
		};
	}
}