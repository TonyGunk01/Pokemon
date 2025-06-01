#include <iostream>

#include "../../../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Caterpie::Caterpie() : Pokemon("Caterpie", PokemonType::Electric, 100, 25) {}

		void Caterpie::bugBite(Pokemon& target)
		{
			cout << name << " uses Bug Bite on" << target.getName() << endl;
			target.takeDamage(20);
		}

		void Caterpie::attack(Pokemon* target) {
			bugBite(*target);
		}
	}
}