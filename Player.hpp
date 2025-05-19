#include <string>
#include "PokemonChoice.hpp"
#include "PokemonType.hpp"
#include "Utility.hpp"

using namespace std;

class Player
{
	public:
		string name;
		Pokemon chosenPokemon;

		Player();

		Player(string p_name, Pokemon p_chosenPokemon);

		void choosePokemon(int choice);
};
