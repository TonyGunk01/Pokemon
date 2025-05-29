#include "../../../include/Character/Player/Player.hpp"
#include "../../../include/Pokemon/PokemonChoice.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Utility/Utility.hpp"

#include <iostream>

using namespace std;

Player::Player()
{
    name = "Trainer";
    chosenPokemon = new Pokemon();
}

Player::Player(string p_name, Pokemon* p_chosenPokemon)
{
    name = p_name;
    chosenPokemon = p_chosenPokemon;
}

void Player::choosePokemon(int choice)
{
    delete chosenPokemon;

    switch ((PokemonChoice)choice)
    {
        case PokemonChoice::CHARMANDER:
            chosenPokemon = new Pokemon("Charmander", PokemonType::FIRE, 100, 50);
            break;

        case PokemonChoice::BULBASAUR:
            chosenPokemon = new Pokemon("Bulbasaur", PokemonType::GRASS, 100, 45);
            break;

        case PokemonChoice::SQUIRTLE:
            chosenPokemon = new Pokemon("Squirtle", PokemonType::WATER, 100, 40);
            break;

        default:
            chosenPokemon = new Pokemon("Pikachu", PokemonType::ELECTRIC, 100, 55);
            break;
    }

    cout << "Player " << name << " chose " << chosenPokemon->name << "!\n";
    Utility::waitForEnter();
}

Player::~Player()
{
    delete chosenPokemon;
}