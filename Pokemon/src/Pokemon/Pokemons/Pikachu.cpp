#include <iostream>

#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Pikachu::Pikachu() : Pokemon("Pikachu", PokemonType::Electric, 100, 15) {}

		void Pikachu::thunderShock(Pokemon& target)
		{
			cout << name << " uses Thunder Shock on" << target.getName() << endl;
			target.takeDamage(20);
		}

		void Pikachu::attack(Pokemon* target) 
		{
			thunderShock(*target);
		}
	}
}