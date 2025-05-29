#include "../../include/Pokemon/grass.hpp"
#include "../../include/Pokemon/Pokemon.hpp" 
#include <vector>

using WildPokemon = Pokemon; 

class WildEncounterManager
{
	public:
		WildEncounterManager();
		WildPokemon getRandomPokemonFromGrass(const Grass& grass);
};
