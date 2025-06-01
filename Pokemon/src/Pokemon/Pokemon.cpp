#include <iostream>
#include <string>

#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"

using namespace N_Pokemon;
using namespace std;

namespace N_Pokemon
{
    void Pokemon::setName(string n) 
    { 
        name = n; 
    }

    string Pokemon::getName() 
    { 
        return name; 
    }

    PokemonType Pokemon::setType(PokemonType t) 
    { 
        type = t; 
        return type; 
    }

    PokemonType Pokemon::getType() 
    { 
        return type; 
    }

    void Pokemon::setHealth(int h) 
    { 
        health = h; 
    }

    int Pokemon::getHealth() 
    { 
        return health; 
    }

    void Pokemon::setMaxHealth(int mh) 
    { 
        maxHealth= mh; 
    }

    int Pokemon::getMaxHealth() 
    { 
        return maxHealth; 
    }

    void Pokemon::setAttackPower(int ap) 
    { 
        attackPower = ap; 
    }

    int Pokemon::getAttackPower() 
    { 
        return attackPower; 
    }
    
    Pokemon::Pokemon()
    {
        name = "Unknown";
        type = PokemonType::Normal;
        health = 50;
        maxHealth = 100;
        attackPower = 10;
    }

    Pokemon::Pokemon(string p_name, PokemonType p_type, int p_maxHealth, int p_attackPower)
    {
        name = p_name;
        type = p_type;
        health = p_maxHealth;
        maxHealth = p_maxHealth;
        attackPower = p_attackPower;
    }

    Pokemon::Pokemon(const Pokemon& other)
    {
        name = other.name;
        type = other.type;
        health = other.health;
        maxHealth = other.maxHealth;
        attackPower = other.attackPower;
    }

    Pokemon::~Pokemon()
    {
        
    }

    void Pokemon::takeDamage(int damage)
    {
        health -= damage;

        if (health < 0)
        {
            health = 0;
        }
    }

    bool Pokemon::isFainted() const
    {
        return (health <= 0);
    }

    void Pokemon::heal()
    {
        health = maxHealth;
    }

    void Pokemon::attack(Move selectedMove, Pokemon* target) 
    { 
        target->takeDamage(selectedMove.power); 
    }

    void Pokemon::selectAndUseMove(Pokemon* target) 
    {
        printAvailableMoves();

        int choice = selectMove();
        Move selectedMove = moves[choice - 1];

        useMove(selectedMove, target);
    }

    void Pokemon::reduceAttackPower(int amount)
    {
        attackPower -= amount;

        if (attackPower < 0)
        {
            attackPower = 0;
        }
    }

    void Pokemon::printAvailableMoves() 
    {
        cout << name << "'s available moves:\n";

        for (size_t i = 0; i < moves.size(); ++i) 
        {
            cout << i + 1 << ": " << moves[i].name << " (Power: " << moves[i].power << ")\n";
        }
    }

    int Pokemon::selectMove()
    {
        int choice;
        cout << "\nChoose a move: ";
        cin >> choice;

        while (choice < 1 || choice > static_cast<int>(moves.size())) 
        {
            cout << "\nInvalid choice. Try again: ";
            cin >> choice;
        }

        return choice;
    }

    void Pokemon::useMove(Move selectedMove, Pokemon* target) 
    {
        cout << "\n" << name << " used " << selectedMove.name << "!\n";

        attack(selectedMove, target);

        N_Utility::Utility::waitForEnter();

        cout << "...\n";
        N_Utility::Utility::waitForEnter();

        if (target->isFainted())
            cout << "\n" << target->name << " fainted!\n";

        else
            cout << "\n" << target->name << " has " << target->health << " HP left.\n";
    }

}