#include "../../../include/Character/Player/Player.hpp"
#include "../../../include/Pokemon/PokemonChoice.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Pokemon/Pokemon.hpp"
#include "../../../include/Utility/Utility.hpp"

#include <iostream>

using namespace std;

N_Player::Player::Player()
{
    name = "Trainer";
    chosenPokemon = new N_Pokemon::Pokemon();
}

N_Player::Player::Player(string p_name, N_Pokemon::Pokemon* p_chosenPokemon)
{
    name = p_name;
    chosenPokemon = p_chosenPokemon;
}

void N_Player::Player::choosePokemon(int choice)
{
    delete chosenPokemon;

    switch ((PokemonChoice)choice)
    {
        case PokemonChoice::CHARMANDER:
            chosenPokemon = new N_Pokemon::Pokemon("Charmander", N_PokemonType::PokemonType::Fire, 100, 50);
            break;

        case PokemonChoice::BULBASAUR:
            chosenPokemon = new N_Pokemon::Pokemon("Bulbasaur", N_PokemonType::PokemonType::Grass, 100, 45);
            break;

        case PokemonChoice::SQUIRTLE:
            chosenPokemon = new N_Pokemon::Pokemon("Squirtle", N_PokemonType::PokemonType::Water, 100, 40);
            break;

        default:
            chosenPokemon = new N_Pokemon::Pokemon("Pikachu", N_PokemonType::PokemonType::Electric, 100, 55);
            break;
    }

    cout << "Player " << name << " chose " << chosenPokemon->name << "!\n";
    N_Utility::Utility::waitForEnter();
}

N_Player::Player::~Player()
{
    delete chosenPokemon;
}