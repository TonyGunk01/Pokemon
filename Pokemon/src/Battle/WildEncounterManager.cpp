#pragma once

#include <cstdlib>
#include <ctime>

#include "../../include/Battle/WildEncounterManager.hpp"

using namespace std;

namespace N_Battle
{
	WildEncounterManager::WildEncounterManager()
	{
		srand(time(0));
	}
	
	Pokemon &WildEncounterManager::getRandomPokemonFromGrass(Grass& grass)
	{
		int randomIndex = rand() % grass.wildPokemonList.size();
		return *grass.wildPokemonList[randomIndex];
	}
}