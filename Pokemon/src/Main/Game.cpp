#include <iostream>
#include <string>

#include "../../include/Utility/Utility.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Main/Game.hpp"
#include "../../include/Pokemon/Grass.hpp"
#include "../../include/Battle/WildEncounterManager.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Pokemon/Pokemons/Zubat.hpp"
#include "../../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../../include/Pokemon/Pokemons/Pidgey.hpp"
#include "../../include/Pokemon/Pokemons/Pikachu.hpp"
#include "../../include/Pokemon/Pokemons/Squirtle.hpp"
#include "../../include/Pokemon/Pokemons/Bulbasaur.hpp"
#include "../../include/Pokemon/Pokemons/Charmander.hpp"

using namespace N_Pokemons;
using namespace N_Utility;
using namespace N_Player;
using namespace N_Pokemon;
using namespace N_Battle;

namespace N_Main
{
    Game::Game()
    {
        forestGrass = Grass
        {
            "Forest",
            { 
                new Zubat(),
                new Caterpie(),
                new Pidgey(),
				new Pikachu(),
                new Squirtle(),
                new Bulbasaur(),
                new Charmander()
            },
            80 };
    }

    Game::~Game() 
    {
        delete(wildPokemon);
    }

    void Game::visitPokeCenter(Player * player) 
    {
        cout << "You have arrived at Poke Center!" << endl;
		Utility::delay(1000);

		cout << "\nHealing your " << player->chosenPokemon->getName();
        Utility::waitEffect();
        player->chosenPokemon->resetValues();

        cout << "\n\n" << player->chosenPokemon->getName() << "'s health is fully restored! All effects have been removed!" << endl;
        Utility::enter();
    }

    void Game::gameLoop(Player* player)
    {
        bool keepPlaying = true;
        int choice;
        BattleManager battleManager;

        while (keepPlaying)
        {
            Utility::clearConsole();

            cout << "What would you like to do, " << player->name << "?" << endl;
            cout << "1. Battle wild Pokemon" << endl;
            cout << "2. Visit PokeCenter" << endl;
            cout << "3. Challenge Gyms" << endl;
            cout << "4. Enter Pokemon League" << endl;
            cout << "5. Quit\n" << endl;

            cin >> choice;

            Utility::clearInputBuffer();

            switch (choice)
            {
                Utility::delay(1300);
                case 1:
                {
                    if (player->chosenPokemon->health <= 0)
                    {
                        cout << "\nYou can't battle with a fainted Pokemon! Visit the PokeCenter first." << endl;
                        Utility::delay(3000);
						gameLoop(player);
                        break;
                    }

                    else
                    {
                        cout << "\nSearching the forest near " << Utility::world();
                        Utility::waitEffect();
                        WildEncounterManager encounterManager;
                        Pokemon* wildPokemon = &encounterManager.getRandomPokemonFromGrass(forestGrass);
                        battleManager.startBattle(*player, *wildPokemon);
                        break;
                    }
                }

                case 2:
                {
                    Game::visitPokeCenter(player);
                    break;
                }

                case 3:
                {
                    cout << player->name << " You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!" << endl;
                    Utility::delay(3000);
                    break;
                }

                case 4:
                {
                    cout << player->name << " You boldly step towards the Pokemon League, but the gatekeeper laughs and says, 'Maybe next time, champ!'" << endl;
                    Utility::delay(3000);
                    break;
                }

                case 5:
                {
                    cout << "Are you sure you want to Quit ?(Y/N)" << endl;

                    char quitChoice;

                    cin >> quitChoice;

                    if (quitChoice == 'Y' || quitChoice == 'y')
                    {
                        keepPlaying = false;

                        cout << "Goodbye, " << player->name << "! Thanks for playing" << endl;
                    }

                    else
                        keepPlaying = true;

                    break;
                }
                
                default:
                {
                    cout << "That's not a valid choice. Try again!" << endl;
                    break;
                }
            }
        }
    }
}