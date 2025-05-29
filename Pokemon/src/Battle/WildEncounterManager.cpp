#include "../../include/Battle/WildEncounterManager.hpp"
#include <cstdlib>
#include <ctime> // Added this include for the time function

WildEncounterManager::WildEncounterManager()
{
	srand(time(0)); // Initializes the random seed
}

WildPokemon WildEncounterManager::getRandomPokemonFromGrass(const Grass& grass)
{
	int randomIndex = rand() % grass.wildPokemonList.size();
	return grass.wildPokemonList[randomIndex];
}