#pragma once

#include <string>
#include "PokemonType.hpp" 
using namespace std;

namespace N_Pokemon
{
    class Pokemon
    {
        protected:
            string name;
            N_PokemonType::PokemonType type;
            int health;
            int maxHealth;
            int attackPower;

        public:
            Pokemon();

            Pokemon(const string& p_name, N_PokemonType::PokemonType p_type, int p_maxHealth, int p_attackPower);

            Pokemon(const Pokemon& p_other);

            ~Pokemon();

            virtual void attack(Pokemon* target) = 0;

            void takeDamage(int damage);

            bool isFainted() const;

            void heal();

            const string& getName() const;
    };
}