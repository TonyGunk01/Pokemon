#pragma once
#include <string>
#include <vector>
#include "Move.hpp"
#include "StatusEffects/StatusEffectType.hpp"
#include "StatusEffects/StatusEffect.hpp"

using namespace N_Battle;
using namespace std;
using namespace N_Pokemon::N_StatusEffects;

namespace N_Pokemon 
{
    struct Move;
    enum class PokemonType;

    class Pokemon 
    {
        public:
            string name;
            PokemonType type;
            int health;
            int maxHealth;
            vector<Move> moves;
            StatusEffect* appliedEffect;

            Pokemon();
            Pokemon(string p_name, PokemonType p_type, int p_health, vector<Move> p_moves);
            Pokemon(Pokemon* other);

            bool isFainted() const;
            void heal();

            virtual void attack(Move selectedMove, Pokemon* target);
            void takeDamage(int damage);
            void selectAndUseMove(Pokemon* target);
            void reduceAttackPower(int reduced_damage);
            bool canAttack();

            bool canApplyEffect();
            void applyEffect(StatusEffectType effectToApply);
            void clearEffect();

            string getName() const;

        protected:
            void printAvailableMoves();
            int selectMove();
            void useMove(Move selectedMove, Pokemon* target);
    };
}