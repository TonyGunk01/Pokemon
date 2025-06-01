#include "../../../include/Character/Player/Player.hpp"
#include "../../../include/Pokemon/PokemonChoice.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"
#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"

#include <iostream>

using namespace N_Pokemons;
using namespace N_Utility;
using namespace N_Pokemon;
using namespace N_Player;
using namespace std;

namespace N_Player 
{
    Player::Player()
    {
        name = "Trainer";
    }

    Player::Player(string p_name) 
    {
        name = p_name;
    }

    void Player::choosePokemon(int choice) 
    {
        switch ((PokemonChoice)choice)
        {
            case PokemonChoice::Bulbasaur:
                chosenPokemon = new Bulbasaur();
                break;

            case PokemonChoice::Charmander:
                chosenPokemon = new Charmander();
                break;

            case PokemonChoice::Squirtle:
                chosenPokemon = new Squirtle();
                break;

            default:
                chosenPokemon = new Pikachu();
                break;
        }

        cout << "Player " << name << " chose " << chosenPokemon->getName() << endl;
        Utility::waitForEnter();
    }
}