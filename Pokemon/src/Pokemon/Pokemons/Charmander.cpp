#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        using namespace std;

        Charmander::Charmander() : Pokemon("Charmander", N_PokemonType::PokemonType::Fire, 100, 35) {}

        void Charmander::flameBurst(Pokemon& target)
        {
            cout << name << " uses flame burst on " << target.getName() << "!\n";
            target.takeDamage(20);
        }

        void Charmander::attack(Pokemon& target)
        {
            flameBurst(target);
        }

    }
}