#include <iostream>

#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
        Pikachu::Pikachu() :
            Pokemon("Pikachu", PokemonType::Electric, 100, {
                    Move("Thunder Shock", 35),
                    Move("Tackle", 10)
                }) {
        }

        void Pikachu::attack(Move selectedMove, Pokemon* target) 
        {
            if (selectedMove.name == "Thunder Bolt")
            {
                if (rand() % 100 < 80)
                {
                    Pokemon::attack(selectedMove, target);
                    std::cout << "... and it hit successfully!\n";
                }

                else
                    std::cout << "... but it missed!\n";
            }

            else
                Pokemon::attack(selectedMove, target);
        }
	}
}