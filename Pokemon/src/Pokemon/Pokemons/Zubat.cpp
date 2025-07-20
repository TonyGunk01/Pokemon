#include <iostream>

#include "../../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;
using namespace N_Utility;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Zubat::Zubat() :
			Pokemon("Zubat", PokemonType::Poison, 120, {
					Move("Super Sonic", 40),
                    Move("Leech Life", 10),
					Move("Tackle", 25)
				}) {
		}

        void Zubat::attack(Move selectedMove, Pokemon* target) 
        {
            cout << "\n" << name << " tries to use " << selectedMove.name << " on " << target->name;

            if (selectedMove.name == "Leech Life")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 75)
                {
                    cout << " and it was successful!\n\n";
                    Pokemon::attack(selectedMove, target);
                    Utility::delay(1500);
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n\n";

                    this->health += selectedMove.damage * 0.5;

                    if (this->health > this->maxHealth)
                        this->health = this->maxHealth;

                    Utility::delay(1500);
                    cout << "Zubat regained some health!\n";
                }

                else
                    cout << " but it missed!\n";

                Utility::delay(1000);
            }

            else if (selectedMove.name == "Super Sonic")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 60)
                {
                    cout << " and it was successful!\n\n";
                    Pokemon::attack(selectedMove, target);
                    Utility::delay(1500);
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
					Utility::delay(1500);
                    Utility::heavyHit();
                }

                else
                    cout << " but it missed!\n";

                Utility::delay(1000);
            }

            else if (selectedMove.name == "Tackle")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 80)
                {
                    cout << " and it was successful!\n\n";
                    Pokemon::attack(selectedMove, target);
                    Utility::delay(1500);
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
                }

                else
                    cout << " but it missed!\n";

                Utility::delay(1000);
            }
        }
	}
}