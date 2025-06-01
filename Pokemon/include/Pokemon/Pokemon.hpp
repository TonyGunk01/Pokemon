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
            PokemonType type;
            int health;
            int maxHealth;
            int attackPower;

        public:
            void setName(string n);
            string getName();

            PokemonType setType(PokemonType t);
            PokemonType getType();

            void setHealth(int h);
            int getHealth();

            void setMaxHealth(int mh);
            int getMaxHealth();

            void setAttackPower(int ap);
            int getAttackPower();
            
            Pokemon();
            Pokemon(string p_name, PokemonType p_type, int p_health);
            Pokemon(string p_name, PokemonType p_type, int p_maxHealth, int p_attackPower);
            Pokemon(const Pokemon& other);
            ~Pokemon();

            virtual void attack(Pokemon*target) = 0;

            void takeDamage(int damage);

            bool isFainted() const;

            void heal();
    };
}