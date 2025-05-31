#include "../../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include <iostream>

namespace N_Pokemon 
{
    namespace N_Pokemons 
    {
        using namespace std;

        Pidgey::Pidgey() : Pokemon("Pidgey", N_PokemonType::PokemonType::Normal, 100, 35) {}

        void Pidgey::attack(Pokemon& target) 
        { 
            wingAttack(target); 
        }

        void Pidgey::wingAttack(Pokemon& target) 
        {
            cout << name << " uses Wing Attack on " << target.getName() << "!\n";
            target.takeDamage(20);
        }
    }
}