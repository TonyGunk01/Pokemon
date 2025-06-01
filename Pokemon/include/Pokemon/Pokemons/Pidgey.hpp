#pragma once
#include "../Pokemon.hpp"
using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		class Pidgey :public Pokemon
		{
			private:
				void wingAttack(Pokemon& target);

			public:
				Pidgey();
				void attack(Pokemon* target)override;
		};
	}
}
