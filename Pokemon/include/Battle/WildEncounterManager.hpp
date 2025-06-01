#pragma once

#include "../Pokemon/Grass.hpp"

#include <vector>

using namespace N_Pokemon;

namespace N_Battle 
{
	class WildEncounterManager
	{
	public:
		WildEncounterManager();
		Pokemon &getRandomPokemonFromGrass(Grass & grass);
	};
}

	