#include <iostream>

#include "../../../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Caterpie::Caterpie() : Pokemon("Caterpie", PokemonType::Electric, 100, 25) {}

		void Caterpie::bugBite(Pokemon& target)
		{
			cout << name << " used BUG BITE!\n";

			target.takeDamage(attackPower);

			if (target.isFainted())
				cout << target.getName() << " fainted!\n";

			else
				cout << target.getName() << " has " << target.getHealth() << " HP left.\n";

			N_Utility::Utility::waitForEnter();
		}

		void Caterpie::attack(Pokemon* target) 
		{
			bugBite(*target);
		}
	}
}