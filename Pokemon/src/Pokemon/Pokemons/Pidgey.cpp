#include <iostream>

#include "../../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"
#include "../../../include/Battle/BattleManager.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Pidgey::Pidgey() :
			Pokemon("Squirtle", PokemonType::Normal, 100, {
					Move("Wing Attack", 20),
					Move("Tackle", 10)
				}) {
		}

        void Pidgey::attack(Move selectedMove, Pokemon* target) 
        {
            Pokemon::attack(selectedMove, target);

            if (selectedMove.name == "Gust")
            {
                if (rand() % 100 < 20)
                {
                    cout << "... and blew the opponent away!\n";
                    N_Battle::BattleManager battleManager; 
                    battleManager.stopBattle(); 
                    N_Utility::Utility::waitForEnter();
                }
            }
        }
	}
}