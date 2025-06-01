#include <iostream>

#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Squirtle::Squirtle() : Pokemon("Squirtle", PokemonType::Water, 100, 35) {}

        void Squirtle::WaterSplash(Pokemon& target)
        {
            cout << name << " used WATER SPLASH!\n";
            N_Utility::Utility::waitForEnter();

            target.takeDamage(attackPower); 

            if (target.isFainted())
                cout << target.getName() << " fainted!\n";

            else
                cout << target.getName() << " has " << target.getHealth() << " HP left.\n";

            N_Utility::Utility::waitForEnter();
        }

		void Squirtle::attack(Pokemon* target) 
		{
			WaterSplash(*target);
		}
	}
}