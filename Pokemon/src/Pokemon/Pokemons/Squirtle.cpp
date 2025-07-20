#include <iostream>
#include <string>

#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;
using namespace N_Utility;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
        Squirtle::Squirtle() :
            Pokemon("Squirtle", PokemonType::Water, 150, {
                    Move("Water Blast", 40),
                    Move("Rapid Spin", 10),
                    Move("Tackle", 20)
                }) {
        }

        void Squirtle::attack(Move selectedMove, Pokemon* target) 
        {
            cout << "\n" << name << " tries to use " << selectedMove.name << " on " << target->name;

            if (selectedMove.name == "Tackle") 
            {
				Utility::delay(200);
				Utility::waitEffect();

                if (rand() % 100 < 80) 
                {
                    cout << " and it was successful!\n\n";
                    Utility::delay(1000);
					Pokemon::attack(selectedMove, target);
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
                } 

                else 
                    cout << " but it missed!\n";

				Utility::delay(1000);
            } 

            else if (selectedMove.name == "Water Blast") 
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 80) 
                {					
                    cout << " and it was successful!\n\n";
                    Utility::delay(1500);
                    Pokemon::attack(selectedMove, target);
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
                    Utility::delay(1500);
                    Utility::heavyHit();
                } 

                else 
                    cout << " but it missed!\n";

				Utility::delay(1000);
            } 

            else if (selectedMove.name == "Rapid Spin") 
            {
                Utility::delay(200);
                Utility::waitEffect();

                int hits = (rand() % 4) + 2;

                if (rand() % 100 < 60)
                { 
                    Utility::delay(1000);
					cout << " and it was successful!\n\n";
                    Utility::delay(1000);

                    for (int i = 0; i < hits; ++i)
                    {
                        Pokemon::attack(selectedMove, target);
                        cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
						Utility::delay(1200);
                    }
                }

                else
                    cout << " but it missed!\n";

				Utility::delay(1000);
            }
        }
	}
}