#include "../../include/Pokemon/Pokemon.hpp" 
#include "../../include/Pokemon/grass.hpp"
#include <vector>

namespace N_WildEncounterManager
{
	using WildPokemon = N_Pokemon::Pokemon; 
	class WildEncounterManager
	{
		public:
			WildEncounterManager();
			WildPokemon getRandomPokemonFromGrass(const N_grass::Grass& grass); 
	};
}