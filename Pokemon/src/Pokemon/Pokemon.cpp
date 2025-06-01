#include <iostream>
#include <string>

#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Pokemon/PokemonType.hpp"

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

    Pokemon::Pokemon(string p_name, PokemonType p_type, int p_health)
    {
        name = p_name;
        type = p_type;
        health = p_health;
        maxHealth = p_health;
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
}