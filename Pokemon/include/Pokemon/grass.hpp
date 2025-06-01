#pragma once

#include <string>
#include <vector>

#include "../Pokemon/Pokemon.hpp"

namespace N_Pokemon
{
	struct Grass
	{
		public:
			string environmentType;
			vector<Pokemon*>wildPokemonList;
			int encounterRate;
	};
}