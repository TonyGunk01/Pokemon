#include <iostream>

#include "../../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Pidgey::Pidgey() :Pokemon("Pidgey", PokemonType::Normal, 100, 35) {}

		void Pidgey::wingAttack(Pokemon& target)
		{
			cout << name << " uses Wing Attack on" << target.getName() << endl;
			target.takeDamage(20);
		}
		void Pidgey::attack(Pokemon* target) {
			wingAttack(*target);
		}
	}
}