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
                    Move("Tackle", 10)  
        }) {}  

        void Bulbasaur::attack(Move selectedMove, Pokemon* target)  
        {  
            Pokemon::attack(selectedMove, target);  
            selectAndUseMove(target);  

            if (selectedMove.name == "Vine Whip")  
            {  
                int secondHitChance = rand() % 2;  

                if (secondHitChance == 1)  
                {  
                    Pokemon::attack(selectedMove, target);  
                    cout << name << " hits again with a second " << selectedMove.name << "!\n";  
                } 

                else  
                    cout << target->getName() << " dodged the second hit!\n";  
            }  
        }  
    }  
}