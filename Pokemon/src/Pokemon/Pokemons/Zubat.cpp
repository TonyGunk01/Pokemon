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
            cout << name << " uses Supersonic on " << target.getName() << "!\n";
            target.takeDamage(20);
        }

        void Zubat::attack(Pokemon& target) 
        { 
            supersonic(target); 
        }

    }
}