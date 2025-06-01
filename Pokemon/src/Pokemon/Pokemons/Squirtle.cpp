#include <iostream>

#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Squirtle::Squirtle() : Pokemon("Squirtle", PokemonType::Water, 100, 35) {}

		void Squirtle::WaterSplash(Pokemon& target)
		{
			cout << name << " uses Water Splash on" << target.getName() << endl;
			target.takeDamage(20);
		}
		void Squirtle::attack(Pokemon* target) {
			WaterSplash(*target);
		}
	}
}