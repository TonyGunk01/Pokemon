#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"  
#include "../../../include/Pokemon/PokemonType.hpp"  
#include "../../../include/Utility/Utility.hpp"  

#include <iostream>  

namespace N_Pokemon  
{  
    namespace N_Pokemons  
    {  
        using namespace std;  

        Bulbasaur::Bulbasaur()  
            :Pokemon("Bulbasaur", PokemonType::Grass, 110, {  
                    Move("Vine Whip", 25),
					Move("Sleep Powder", 5),
                    Move("Tackle", 10)  
        }) {}  

        void Bulbasaur::attack(Move selectedMove, Pokemon* target)
        {
            if (selectedMove.name == "Wine Whip")
            {
                if (rand() % 100 < 80)
                {
                    Pokemon::attack(selectedMove, target);
                    cout << "... and it hit successfully!\n";
                }

                else
                    cout << "... but it missed!\n";
            }

            else
                Pokemon::attack(selectedMove, target);

            if (selectedMove.name == "Sleep Powder")
            {
                if (target->canApplyEffect())
                    target->applyEffect(StatusEffectType::Sleeping);
            }
        }
    }  
}