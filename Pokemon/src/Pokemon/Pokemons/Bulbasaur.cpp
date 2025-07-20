#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"  
#include "../../../include/Pokemon/PokemonType.hpp"  
#include "../../../include/Utility/Utility.hpp"  

#include <iostream>

using namespace N_Utility;

namespace N_Pokemon  
{  
    namespace N_Pokemons  
    {
        Bulbasaur::Bulbasaur()  
            :Pokemon("Bulbasaur", PokemonType::Grass, 150, {  
                    Move("Vine Whip", 35),  
                    Move("Sleep Powder", 5),  
                    Move("Tackle", 20)
        }) {}  

        void Bulbasaur::attack(Move selectedMove, Pokemon* target)  
        {  
            cout << "\n" << name << " tries to use " << selectedMove.name << " on " << target->name;

            if (selectedMove.name == "Tackle")  
            {  
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 80)  
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

            else if (selectedMove.name == "Vine Whip")  
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

            else if (selectedMove.name == "Sleep Powder")  
            {  
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 70)  
                {  
                    cout << "and it was successful!\n\n";
                    Utility::delay(1500);
                    Pokemon::attack(selectedMove, target);  
                    cout << target->getName() << " took " << selectedMove.damage << " damage!\n";
                    Utility::delay(2000);

                    if (target->canApplyEffect())  
                        target->applyEffect(StatusEffectType::Sleep);  
                }  

                else  
                    cout << "but it missed!\n";  

				Utility::delay(1000);
            }  
        }  
    }  
}