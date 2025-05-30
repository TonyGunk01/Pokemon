#include "WildEncounterManager.hpp"
#include <cstdlib>

WildEncounterManager::WildEncounterManager()
{
	srand(time(0));
}

WildPokemon WildEncounterManager::getRandomPokemonFromGrass(const Grass& grass)
{
	int randomIndex = rand() % grass.wildPokemonList.size();
	return grass.wildPokemonList[randomIndex];
}