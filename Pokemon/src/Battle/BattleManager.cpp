#include "../../include/Character/Player/Player.hpp"
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>

using namespace std;

void N_BattleManager::BattleManager::startBattle(N_Player::Player& player, N_Pokemon::Pokemon& wildPokemon)
{
	battleState.playerPokemon = player.chosenPokemon;
	battleState.wildPokemon = &wildPokemon;
	battleState.playerTurn = true;  
	battleState.battleOngoing = true;

	cout << "A wild " << wildPokemon.getName() << " appeared!" << endl;
	battle();
}

void N_BattleManager::BattleManager::battle(N_Pokemon::Pokemon& playerPokemon, N_Pokemon::Pokemon& wildPokemon)
{
	while (!playerPokemon.isFainted() && !wildPokemon.isFainted())
	{
		playerPokemon.attack(wildPokemon);

		if (wildPokemon.isFainted())
		{
			wildPokemon.attack(playerPokemon);
		}

		N_Utility::Utility::waitForEnter();
	}

	handleBattleOutcome();
}

void N_BattleManager::BattleManager::battle() 
{
    while (battleState.battleOngoing) 
    {
        if (battleState.playerTurn) 
        {
            battleState.playerPokemon->attack(*battleState.wildPokemon);
        }
        else 
        {
            battleState.wildPokemon->attack(*battleState.playerPokemon);
        }

        updateBattleState();

        battleState.playerTurn = !battleState.playerTurn;

        N_Utility::Utility::waitForEnter();
    }

    handleBattleOutcome();
}  

void N_BattleManager::BattleManager::handleBattleOutcome(N_Player::Player& player, bool playerWon)  
{  
    if (playerWon)  
    {  
        cout << player.chosenPokemon->getName() << " is victorious! Keep an eye on your Pokemon's health.\n";  
    }  
    else  
    {  
        cout << "Oh no! " << player.chosenPokemon->getName() << " fainted! You need to visit the PokeCenter.\n";  
        N_Utility::Utility::waitForEnter();  
        cout << "Game Over!\n";  
    }  
}

namespace N_BattleManager 
{  
    void BattleManager::handleBattleOutcome()  
    {  
        if (battleState.playerPokemon->isFainted())  
        {  
            cout << battleState.playerPokemon->getName() << " has fainted! You lose the battle.\n";  
        }  
        else  
        {  
            cout << "You defeated the wild " << battleState.wildPokemon->getName() << "!\n";  
        }  
    }

    void BattleManager::updateBattleState() 
    {
        if (battleState.playerPokemon->isFainted()) 
        {
            battleState.battleOngoing = false;
        }
        else if (battleState.wildPokemon->isFainted()) 
        {
            battleState.battleOngoing = false;
        }
    }
}


