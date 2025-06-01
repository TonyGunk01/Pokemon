#include <iostream>

#include "../../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Zubat::Zubat() :Pokemon("Zubat", PokemonType::Electric, 100, 20) {}

		void Zubat::supersonic(Pokemon& target)
		{
			cout << name << " used SUPER SONIC!\n";

			target.takeDamage(attackPower);

			if (target.isFainted())
				cout << target.getName() << " fainted!\n";

			else
				cout << target.getName() << " has " << target.getHealth() << " HP left.\n";

			N_Utility::Utility::waitForEnter();
		}

		void Zubat::attack(Pokemon* target) 
		{
			supersonic(*target);
		}
	}
}