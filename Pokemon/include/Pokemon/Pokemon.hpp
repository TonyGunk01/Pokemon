#pragma once

#include <string>
#include <vector>

#include "PokemonType.hpp"
#include "../Battle/Move.hpp" 

using namespace std;

namespace N_Pokemon
{
    struct Move;
	enum class PokemonType;

    class Pokemon
    {
        protected:
            string name;
            PokemonType type;
            int health;
            int maxHealth;
            int attackPower = 0;

        public:
            void setName(string n);
            string getName();

            void selectAndUseMove(Pokemon* target);
            vector<Move> moves;

            PokemonType setType(PokemonType t);
            PokemonType getType();

            void setHealth(int h);
            int getHealth();

            void setMaxHealth(int mh);

            int getMaxHealth();

            void setAttackPower(int ap);

            int getAttackPower();
            
            Pokemon();

            Pokemon(string p_name, PokemonType p_type, int p_maxHealth, int p_attackPower);

            Pokemon(const Pokemon& other);

            ~Pokemon();

            virtual void attack(Move selectedMove, Pokemon*target) = 0;

            void takeDamage(int damage);

            bool isFainted() const;

            Pokemon(string p_name, PokemonType p_type, int p_maxHealth, vector<Move> p_moves)
                    : name(p_name), type(p_type), maxHealth(p_maxHealth), health(p_maxHealth), attackPower(0), moves(p_moves) // Initialize attackPower to 0
            {}

            void heal();

            void reduceAttackPower(int amount);
        
        protected:

            void printAvailableMoves();

            int selectMove();

            void useMove(Move selectedMove, Pokemon* target);
        
    };
}