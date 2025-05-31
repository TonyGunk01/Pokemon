#include "../../include/Pokemon/Pokemon.hpp"  
#include "../../include/Pokemon/PokemonType.hpp"

#include <iostream>

using namespace std;
using namespace N_Pokemon;
using namespace N_PokemonType;

Pokemon::Pokemon() : name(""), type(N_PokemonType::PokemonType::Normal), health(0), maxHealth(0), attackPower(0)  
{  

}  

Pokemon::Pokemon(const Pokemon& p_other): name(p_other.name), type(p_other.type), health(p_other.health), maxHealth(p_other.maxHealth), attackPower(p_other.attackPower)  
{  

}  

Pokemon::Pokemon(const string& p_name, N_PokemonType::PokemonType p_type, int p_maxHealth, int p_attackPower): name(p_name), type(p_type), maxHealth(p_maxHealth), health(p_maxHealth), attackPower(p_attackPower)  
{  

}  

Pokemon::~Pokemon()  
{  

}  

void Pokemon::attack(Pokemon& target)  
{  
    int damage = 10;  
    cout << name << " attacks " << target.name << " for " << damage << " damage!\n";  
    target.takeDamage(damage);  
}  

void Pokemon::takeDamage(int damage)  
{  
    health -= damage;  
    if (health < 0) {  
        health = 0;  
    }  
    cout << name << " takes " << damage << " damage! Health is now " << health << ".\n";  
}  

bool Pokemon::isFainted() const  
{  
    return health <= 0;  
}  

void Pokemon::heal()  
{  
    health = maxHealth;
}  

const string& Pokemon::getName() const  
{  
    return name;  
}