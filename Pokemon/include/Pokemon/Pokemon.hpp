#pragma once

#include <string>
#include "PokemonType.hpp"
using namespace std;

class Pokemon
{
    public:
        string name;
        PokemonType type;
        int health;
        int maxHealth; 
        int attackPower;

        Pokemon();

        Pokemon(const string& p_name, PokemonType p_type, int p_maxHealth, int p_attackPower); // Use const reference for string

        Pokemon(const Pokemon& p_other);

        ~Pokemon();

        void attack(Pokemon& target);

        void takeDamage(int damage);

        bool isFainted() const;

        void heal();
};