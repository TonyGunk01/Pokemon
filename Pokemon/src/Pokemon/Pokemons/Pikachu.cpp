#include <iostream>

#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Pikachu::Pikachu() : Pokemon("Pikachu", PokemonType::Electric, 100, 15) {}

		void Pikachu::thunderShock(Pokemon& target)
		{
			cout << name << " used THUNDER SHOCK!\n";
			N_Utility::Utility::waitForEnter();

			target.takeDamage(attackPower);

			if (target.isFainted())
				cout << target.getName() << " fainted!\n";

			else
				cout << target.getName() << " has " << target.getHealth() << " HP left.\n";

			N_Utility::Utility::waitForEnter();
		}

		void Pikachu::attack(Pokemon* target) 
		{
			thunderShock(*target);
		}
	}
}