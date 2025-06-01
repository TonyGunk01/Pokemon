#include <iostream>

#include "../../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Zubat::Zubat() :Pokemon("Zubat", PokemonType::Electric, 100, 20) {}

		void Zubat::supersonic(Pokemon& target)
		{
			cout << name << " uses Supersonic on" << target.getName() << endl;
			target.takeDamage(20);
		}

		void Zubat::attack(Pokemon* target) 
		{
			supersonic(*target);
		}
	}
}