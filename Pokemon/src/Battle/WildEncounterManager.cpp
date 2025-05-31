#include "../../include/Battle/WildEncounterManager.hpp"
#include <cstdlib>
#include <ctime> 

namespace N_WildEncounterManager 
{

	WildEncounterManager::WildEncounterManager()
	{
		srand(time(0)); 
	}

	WildPokemon* WildEncounterManager::getRandomPokemonFromGrass(const N_grass::Grass& grass)
	{
		if (grass.wildPokemonList.empty()) return nullptr;
		int randomIndex = rand() % grass.wildPokemonList.size();
		return grass.wildPokemonList[randomIndex];
	}
}