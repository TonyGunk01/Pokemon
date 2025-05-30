#include "../../include/Pokemon/Pokemon.hpp"  
#include "../../include/Pokemon/PokemonType.hpp"

#include <iostream>

using namespace std;
using namespace N_Pokemon;
using namespace N_PokemonType;

Pokemon::Pokemon() : name("Unknown"), type(PokemonType::Normal), health(50), maxHealth(50), attackPower(10)  
{  

}  

Pokemon::Pokemon(const Pokemon& other): name(other.name), type(other.type), health(other.health), maxHealth(other.maxHealth), attackPower(other.attackPower)  
{  

}  

Pokemon::Pokemon(const string& p_name, PokemonType p_type, int p_maxHealth, int p_attackPower): name(p_name), type(p_type), maxHealth(p_maxHealth), health(p_maxHealth), attackPower(p_attackPower)  
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