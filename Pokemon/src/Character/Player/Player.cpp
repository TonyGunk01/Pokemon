#include "../../../include/Character/Player/Player.hpp"
#include "../../../include/Pokemon/PokemonChoice.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"
#include "../../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../../include/Pokemon/Pokemons/Charmander.hpp"
#include "../../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../../include/Pokemon/Pokemons/Pikachu.hpp"

#include <iostream>

using namespace N_Utility;
using namespace N_Pokemon;
using namespace N_Player;
using namespace std;
using namespace N_Pokemon::N_Pokemons;

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
                cout << "\nNice choice! Bulbasaur is a grass type Pokemon and is super mighty!" << endl;
                break;

            case PokemonChoice::Charmander:
                chosenPokemon = new Charmander();
                cout << "\nAh, great selection! Charmander is a fire type Pokemon and can be quite formidable!" << endl;
                break;

            case PokemonChoice::Squirtle:
                chosenPokemon = new Squirtle();
                cout << "\nGood decision! Squirtle is a water type Pokemon with a tough fight in him!" << endl;
                break;

            default:
                chosenPokemon = new Pikachu();
				cout << "\nHmm, it looks like you didn't choose a Pokemon. Pikachu, the powerful electric type Pokemon will be your companion!" << endl;
                break;
        }

        Utility::delay(2000);
        cout << "\n" << chosenPokemon->getName() << " has been added to your team!" << endl;

        Utility::delay(2000);
        cout << "\nNow, " << name << ", you are ready to embark on your Pokemon journey!" << endl;

		Utility::delay(1500);
        Utility::waitEffect();
    }
}