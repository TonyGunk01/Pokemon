#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        using namespace std;

        Bulbasaur::Bulbasaur() : Pokemon("Bulbasaur", PokemonType::Grass, 100, 35) {}

        void Bulbasaur::attack(Pokemon* target)
        {
            vineWhip(*target);
        }

        void Bulbasaur::vineWhip(Pokemon& target)
        {
            cout << name << " used VINE WHIP!\n";
            N_Utility::Utility::waitForEnter();

            target.takeDamage(attackPower);

            if (target.isFainted())
                cout << target.getName() << " fainted!\n";

            else
                cout << target.getName() << " has " << target.getHealth() << " HP left.\n";

            N_Utility::Utility::waitForEnter();
        }
    }
}