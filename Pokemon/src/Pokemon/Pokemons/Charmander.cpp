#include <iostream>

#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

using namespace N_Pokemon;
using namespace std;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Charmander::Charmander() : Pokemon("Charmander", PokemonType::Fire, 100, 35) {}

		void Charmander::flameBrust(Pokemon& target)
		{
			cout << name << " uses Flame Thrower on" << target.getName() << endl;
			target.takeDamage(20);
		}

		void Charmander::attack(Pokemon* target) 
		{
			flameBrust(*target);
		}
	}
}