#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Pokemon/Move.hpp"
#include "../../../include/Utility/Utility.hpp"

#include <iostream>

namespace N_Pokemon 
{
    namespace N_Pokemons 
    {
        using namespace std;
		using namespace N_Utility;

        Pikachu::Pikachu()
            : Pokemon("Pikachu", PokemonType::Electric, 150, {
                Move("Thunder Shock", 5),
                Move("Tackle", 20),
                Move("Thunder Bolt", 40)
                }) {
        }

        void Pikachu::attack(Move selectedMove, Pokemon* target)
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

            else if (selectedMove.name == "Thunder Bolt")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if (rand() % 100 < 70)
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
            }

            else if (selectedMove.name == "Thunder Shock")
            {
                Utility::delay(200);
                Utility::waitEffect();

                if( rand() % 100 < 60)
                {
                    cout << " and it was successful!\n"; 
					Utility::delay(1500);
                    Pokemon::attack(selectedMove, target);

                    if (target->canApplyEffect())
                        target->applyEffect(StatusEffectType::Paralyze);
                }

                else
                    cout << " but it missed!\n";
            }
        }
    }
}