#include <iostream>
#include "Pokemon.hpp"
#include "PokemonType.hpp"

using namespace std;

Pokemon::Pokemon() : name("Unknown"), type(PokemonType::NORMAL), health(50) 
{

}

Pokemon::Pokemon(std::string p_name, PokemonType p_type, int p_health): name(p_name), type(p_type), health(p_health) 
{

}

Pokemon::Pokemon(const Pokemon& other): name(other.name), type(other.type), health(other.health) 
{

}

Pokemon::~Pokemon() 
{

}

void Pokemon::attack(Pokemon& target) 
{
    int damage = 10;
    cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
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