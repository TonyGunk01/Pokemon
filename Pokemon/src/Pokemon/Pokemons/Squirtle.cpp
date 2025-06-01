#include <iostream>

#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
        Squirtle::Squirtle() :
            Pokemon("Squirtle", PokemonType::Water, 100, {
                    Move("Vine Whip", 35),
                    Move("Tackle", 10)
                }) {
        }

        void Squirtle::attack(Move selectedMove, Pokemon* target) 
        {
            Pokemon::attack(selectedMove, target);

            if (selectedMove.name == "RAPID SPIN")
            {
                int hits = (rand() % 4) + 2;

                for (int i = 0; i < hits; ++i) 
                {
                    Pokemon::attack(selectedMove, target);
                }

                cout << "... and hit " << hits << " times!\\n";
            }
        }
	}
}