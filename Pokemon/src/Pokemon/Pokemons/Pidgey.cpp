#include <iostream>

#include "../../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"
#include "../../../include/Battle/BattleManager.hpp"

using namespace N_Pokemon;
using namespace N_Utility;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Pidgey::Pidgey() :
			Pokemon("Pidgey", PokemonType::Flying, 130, {
					Move("Wing Attack", 45),
                    Move("Gust", 0),
					Move("Tackle", 25)
				}) {
		}

        void Pidgey::attack(Move selectedMove, Pokemon* target) 
        {
            cout << "\n" << name << " tries to use " << selectedMove.name << " on " << target->name;

            if (selectedMove.name == "Gust")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 35)
                {
                    cout << " and it was successful!\n\n";
                    N_Battle::BattleManager battleManager;
					Utility::delay(1000);
                    battleManager.stopBattle();
                }

                else
                    cout << " but it missed!\n";

				Utility::delay(1000);
            }

            else if (selectedMove.name == "Wing Attack")
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
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n\n";
                }

                else
					cout << " but it missed!\n";

				Utility::delay(1000);
            }
        }
	}
}