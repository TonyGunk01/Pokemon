#include "../../include/Main/Game.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Pokemon/PokemonType.hpp"
#include "../../include/Utility/Utility.hpp"
#include "../../include/Battle/WildEncounterManager.hpp"
#include "../../include/Battle/BattleManager.hpp" 

#include <iostream>

using namespace std;
using namespace N_Game;
using namespace N_Pokemon;
using namespace N_PokemonType;
using namespace N_Utility;
using namespace N_BattleManager;
using namespace N_Player;
using namespace N_WildEncounterManager;


Game::Game() : forestGrass(
    "Forest",
    {
        new Pokemon("Pidgey", PokemonType::Normal, 40, 10),
        new Pokemon("Caterpie", PokemonType::Psychic, 35, 5),
        new Pokemon("Zubat", PokemonType::Poison, 30, 8)
    },
    70
)
{
}

void Game::gameLoop(Player& player) 
{
    BattleManager battleManager;
    int choice;
    bool keepPlaying = true;

    while (keepPlaying) 
    {
        Utility::clearConsole();

        cout << "\nWhat would you like to do next, " << player.getName() << "?\n";
        cout << "1. Battle Wild Pokemon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokemon League\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        Utility::clearInputBuffer();

        switch (choice) 
        {
            case 1: 
            {
                WildEncounterManager encounterManager;
                Pokemon* encounteredPokemon = encounterManager.getRandomPokemonFromGrass(forestGrass);
                
                if (encounteredPokemon) 
                {
                    battleManager.startBattle(player, *encounteredPokemon);
                }
                break;
            }

            case 2: 
            {
                cout << "\nYou head to the PokeCenter\n";
                player.chosenPokemon->heal();
				cout << player.chosenPokemon->getName() << "'s health is fully restored!\n";
                break;
            }

            case 3: 
            {
                cout << "\nYou march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n";
                break;
            }

            case 4: 
            {
                cout << "\nYou boldly step towards the Pokemon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n";
                break;
            }

            case 5: 
            {
                keepPlaying = false;
                break;
            }

            default: 
            {
                cout << "\nThat's not a valid choice. Try again!\n";
                break;
            }
        }

        Utility::waitForEnter();
    }

    cout << "Goodbye, " << player.getName() << "! Thanks for playing!\n";
}