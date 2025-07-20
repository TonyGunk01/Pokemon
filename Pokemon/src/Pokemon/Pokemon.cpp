#include <iostream>

#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Pokemon/StatusEffects/ParalyzedEffect.hpp"
#include "../../include/Pokemon/StatusEffects/SleepEffect.hpp"
#include "../../include/Pokemon/StatusEffects/BurnEffect.hpp"
#include "../../include/Pokemon/StatusEffects/PoisonEffect.hpp"
#include "../../include/Utility/Utility.hpp"

using namespace std;
using namespace N_Utility;

namespace N_Pokemon 
{
    Pokemon::Pokemon() 
    {
        name = "Unknown";
        type = PokemonType::Normal;
        health = 50;
        maxHealth = 50;
        appliedEffect = nullptr;
    }

    Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health, vector<Move> p_moves) 
    {
        name = p_name;
        type = p_type;
        maxHealth = p_health;
        health = p_health;
        moves = p_moves;
        appliedEffect = nullptr;
    }

    Pokemon::Pokemon(Pokemon* other) 
    {
        name = other->name;
        type = other->type;
        health = other->health;
        maxHealth = other->maxHealth;
        moves = other->moves;
    }

    void Pokemon::takeDamage(int damage) 
    {
        health -= damage;

        if (health < 0) 
        {
            health = 0;
        }
    }

    void Pokemon::selectAndUseMove(Pokemon* target)
    {
        printAvailableMoves();

        int choice = selectMove();

        if (choice - 1 < 0 || choice - 1 >= moves.size()) 
        {
            throw std::out_of_range("Invalid move index selected.");
        }

        Move selectedMove = moves[choice - 1];
        useMove(selectedMove, target);
    }

    void Pokemon::reduceAttackPower(int reduced_damage)
    {
        for (int i = 0; i < moves.size(); i++)
        {
            moves[i].damage -= reduced_damage;

            if (moves[i].damage < 0)
                moves[i].damage = 0;
        }
    } 

    bool Pokemon::canAttack()
    {
        if (appliedEffect == nullptr)
            return true;

        else
            return appliedEffect->turnEndEffect(this);
    }

    bool Pokemon::canApplyEffect() 
    { 
        return appliedEffect == nullptr; 
    }

    void Pokemon::resetValues()
    {
        health = maxHealth;
        appliedEffect = nullptr;
        for (auto& move : moves) 
        {
            move.damage = move.originalDamage;
		}
    }

    void Pokemon::applyEffect(StatusEffectType effectToApply)
    {
        switch (effectToApply)
        {
            case StatusEffectType::Paralyze:
                appliedEffect = new ParalyzedEffect();
                appliedEffect->applyEffect(this);
                break;

            case StatusEffectType::Sleep:
                appliedEffect = new SleepEffect();
                appliedEffect->applyEffect(this);
                break;

            case StatusEffectType::Burn:
                appliedEffect = new BurnEffect();
                appliedEffect->applyEffect(this);
                break;

            case StatusEffectType::Poison:
                appliedEffect = new PoisonEffect();
                appliedEffect->applyEffect(this);
                break;

            default:
                appliedEffect = nullptr;
        }
    }

    void Pokemon::clearEffect() 
    { 
        appliedEffect = nullptr; 
    }

    void Pokemon::printAvailableMoves()
    {
        cout << "\n" << name << "'s available moves:\n";

        for (size_t i = 0; i < moves.size(); ++i) 
            cout << i + 1 << ": " << moves[i].name << " (Power: " << moves[i].damage << ")\n";

        cout << "\n";
    }

    int Pokemon::selectMove()
    {
        int choice;
        cout << "Choose a move: ";
        cin >> choice;

        while (choice < 1 || choice > static_cast<int>(moves.size())) {
            cout << "Invalid choice. Try again: ";
            cin >> choice;
        }

        return choice;
    }

    void Pokemon::useMove(Move selectedMove, Pokemon* target)
    {
        attack(selectedMove, target);

        if (target->isFainted())
        {
            Utility::delay(1500);
            cout << "\n" << target->name << " fainted!\n";
            Utility::delay(2000);
        }

        else
        {
            Utility::delay(1500);
            cout << "\n" << target->name << " has " << target->health << " HP left. ";
            Utility::delay(1500);
            cout << name << " has " << health << " HP left.\n";
            Utility::delay(2200);
        }
    }

    void Pokemon::attack(Move selectedMove, Pokemon* target) 
    { 
        target->takeDamage(selectedMove.damage); 
    }

    bool Pokemon::isFainted() const 
    { 
        return health <= 0; 
    }

    string Pokemon::getName() const 
    {
        return name;
    }
}