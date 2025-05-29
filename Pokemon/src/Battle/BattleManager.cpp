#include "../../include/Character/Player/Player.hpp"
#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Utility/Utility.hpp"
#include <iostream>

using namespace std;

void BattleManager::startBattle(Player& player, Pokemon& wildPokemon)
{
	battleState.playerPokemon = player.chosenPokemon;
	battleState.wildPokemon = &wildPokemon;
	battleState.playerTurn = true;  
	battleState.battleOngoing = true;

	cout << "A wild " << wildPokemon.name << " appeared!" << endl;
	battle();
}

void BattleManager::battle(Pokemon& playerPokemon, Pokemon& wildPokemon)
{
	while (!playerPokemon.isFainted() && !wildPokemon.isFainted())
	{
		playerPokemon.attack(wildPokemon);

		if (wildPokemon.isFainted())
		{
			wildPokemon.attack(playerPokemon);
		}

		Utility::waitForEnter();
	}

	handleBattleOutcome();
}

void BattleManager::battle() 
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

		Utility::waitForEnter();
	}

	handleBattleOutcome();
}

void BattleManager::handleBattleOutcome(Player& player, bool playerWon)
{
	if (playerWon)
	{
		cout << player.chosenPokemon->name << " is victorious! Keep an eye on your Pokemon's health.\n";
	}
	else
	{
		cout << "Oh no! " << player.chosenPokemon->name << " fainted! You need to visit the PokeCenter.\n";
		Utility::waitForEnter();
		cout << "Game Over!\n";
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

void BattleManager::handleBattleOutcome() 
{
	if (battleState.playerPokemon->isFainted()) 
	{
		cout << battleState.playerPokemon->name << " has fainted! You lose the battle.\\n";
	}

	else 
	{
		cout << "You defeated the wild " << battleState.wildPokemon->name << "!\\n";
	}
}