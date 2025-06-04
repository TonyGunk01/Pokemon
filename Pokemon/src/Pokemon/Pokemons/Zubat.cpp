#include <iostream>

#include "../../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Zubat::Zubat() :
			Pokemon("Zubat", PokemonType::Poison, 100, {
					Move("Super Sonic", 20),
                    Move("Leech Life", 20),
					Move("Tackle", 10)
				}) {
		}

        void Zubat::attack(Move selectedMove, Pokemon* target) 
        {
            Pokemon::attack(selectedMove, target);

            if (selectedMove.name == "Leech Life")
            {
                this->health += selectedMove.power * 0.5;

                if (this->health > this->maxHealth)
                    this->health = this->maxHealth;

                cout << "... and regained health!\n";
            }
        }
	}
}