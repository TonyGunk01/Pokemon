#include "../../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon 
{
    namespace N_Pokemons 
    {
        using namespace std;

        Zubat::Zubat() : Pokemon("Zubat", N_PokemonType::PokemonType::Poison, 100, 20) {}

        void Zubat::supersonic(Pokemon& target) 
        {
            cout << name << " uses Supersonic on " << target.name << "!\n";
            target.takeDamage(20);
        }

    }
}