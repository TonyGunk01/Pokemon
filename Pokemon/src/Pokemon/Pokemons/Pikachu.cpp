#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Pokemon/Move.hpp"

#include <iostream>

namespace N_Pokemon 
{
    namespace N_Pokemons 
    {
        using namespace std;

        Pikachu::Pikachu()
            : Pokemon("Pikachu", PokemonType::Electric, 100, {
                Move("Thunder Shock", 25),
                Move("Tackle", 10),
                Move("Thunder Bolt", 80)
                }) {
        }

        void Pikachu::attack(Move selectedMove, Pokemon* target)
        {
            if (selectedMove.name == "Thunder Bolt")
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

            if (selectedMove.name == "Thunder Shock")
            {
                if (target->canApplyEffect())
                    target->applyEffect(StatusEffectType::Paralyzed);
            }
        }
    }
}