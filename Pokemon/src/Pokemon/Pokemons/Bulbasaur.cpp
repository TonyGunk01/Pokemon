#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon
{
    namespace N_Pokemons
    {
        using namespace std;

        Bulbasaur::Bulbasaur() : Pokemon("Bulbasaur", N_PokemonType::PokemonType::Grass, 100, 35) {}

        void Bulbasaur::vineWhip(Pokemon& target)
        {
            cout << name << " uses vine whip on " << target.getName() << "!\n";
            target.takeDamage(20);
        }

        void Bulbasaur::attack(Pokemon& target)
        {
            vineWhip(target); // Or put the attack logic directly here
        }

    }
}