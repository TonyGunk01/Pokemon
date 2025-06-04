#include <iostream>

#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        Charmander::Charmander() :
            Pokemon("Charmander", PokemonType::Fire, 100, {
                    Move("Flame Burst", 5),
                    Move("Blazing Charge", 60),
                    Move("Tackle", 10)
                }) {
        }

        void Charmander::attack(Move selectedMove, Pokemon* target)
        {
            Pokemon::attack(selectedMove, target);

            if (selectedMove.name == "Blazing Charge")
            {
                this->takeDamage(10);
                cout << name << " takes 10 recoil damage from the Blazing Charge!\n";
                N_Utility::Utility::waitForEnter();
            }

            if (selectedMove.name == "Flame Burst")
            {
                if (target->canApplyEffect())
                    target->applyEffect(StatusEffectType::Burned);
            }
        }
    }
}