#include <iostream>

#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Charmander::Charmander() : Pokemon("Charmander", PokemonType::Fire, 100, 35) {}

		void Charmander::flameBurst(Pokemon& target)
		{
			cout << name << " used FLAME THROWER!\n";
			N_Utility::Utility::waitForEnter();

			target.takeDamage(attackPower); 

			if (target.isFainted()) 
				cout << target.getName() << " fainted!\n"; 

			else
				cout << target.getName() << " has " << target.getHealth() << " HP left.\n"; 

			N_Utility::Utility::waitForEnter();
		}

		void Charmander::attack(Pokemon* target) 
		{
			flameBurst(*target);
		}
	}
}