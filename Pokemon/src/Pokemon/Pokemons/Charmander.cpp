#include <iostream>

#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;
using namespace N_Utility;

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Charmander::Charmander() :
            Pokemon("Charmander", PokemonType::Fire, 150, {
                    Move("Flame Burst", 0),
                    Move("Blazing Charge", 40),
                    Move("Tackle", 20)
                }) {}

        void Charmander::attack(Move selectedMove, Pokemon* target)
        {
            cout << "\n" << name << " tries to use " << selectedMove.name << " on " << target->name;

            if (selectedMove.name == "Tackle")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 90)
                {
                    cout << " and it was successful!\n\n";
					Utility::delay(1500);
                    Pokemon::attack(selectedMove, target);
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
                }

                else
                    cout << " but it missed!\n";

				Utility::delay(1000);
            }

            else if (selectedMove.name == "Blazing Charge")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 75)
                {
                    cout << " and it was successful!\n\n";
					Utility::delay(1500);
                    Pokemon::attack(selectedMove, target);
                    this->takeDamage(10);

                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
                    Utility::delay(1500);
                    Utility::heavyHit();
					Utility::delay(1500);
                    cout << "\n" << name << " takes 10 recoil damage from the Blazing Charge!\n";
                }

                else
					cout << " but it missed!\n";

				Utility::delay(1000);
            }

            else if (selectedMove.name == "Flame Burst")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 60)
                {
                    cout << " and it was successful!\n";
					Utility::delay(1500);
                    Pokemon::attack(selectedMove, target);

                    if (target->canApplyEffect())
                        target->applyEffect(StatusEffectType::Burn);
                }

                else
					cout << " but it missed!\n";

				Utility::delay(1000);
            }
        }
    }
}