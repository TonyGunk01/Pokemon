#include <iostream>

#include "../../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Pidgey::Pidgey() :Pokemon("Pidgey", PokemonType::Normal, 100, 35) {}

		void Pidgey::wingAttack(Pokemon& target)
		{
			cout << name << " used WING ATTACK!\n";
			N_Utility::Utility::waitForEnter();

			target.takeDamage(attackPower);

			if (target.isFainted())
				cout << target.getName() << " fainted!\n";

			else
				cout << target.getName() << " has " << target.getHealth() << " HP left.\n";

			N_Utility::Utility::waitForEnter();
		}

		void Pidgey::attack(Pokemon* target) 
		{
			wingAttack(*target);
		}
	}
}