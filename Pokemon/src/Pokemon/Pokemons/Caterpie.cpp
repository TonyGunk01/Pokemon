#include <iostream>

#include "../../../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;
using namespace N_Utility;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Caterpie::Caterpie() :
			Pokemon("Caterpie", PokemonType::Bug, 150, {
					Move("Bug Bite", 40),
                    Move("Sticky Web", 10),
					Move("Tackle", 20)

				}) {
		}

        void Caterpie::attack(Move selectedMove, Pokemon* target)
        {
            cout << "\n" << name << " tries to use " << selectedMove.name << " on " << target->name;

            if (selectedMove.name == "Tackle")
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
            }

            else if (selectedMove.name == "Bug Bite")
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
			}

            else if (selectedMove.name == "Sticky Web")
            {
                int reducedDamage = 5;

                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 70)
                {
                    cout << " and it was successful!\n\n";
                    Utility::delay(1500);
                    cout << target->getName() << " will have its attack power reduced by " << reducedDamage << " for the remainder of this battle!\n";
                    target->reduceAttackPower(reducedDamage);
                }

                else
					cout << " but it missed!\n";
            }
        }
	}
}