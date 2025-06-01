#include <iostream>

#include "../../include/Character/Player/Player.hpp"
#include "../../include/Battle/BattleManager.hpp"
#include "../../include/Utility/Utility.hpp"

using namespace N_Player;
using namespace N_Utility;
using namespace std;

namespace N_Battle 
{
	void BattleManager::startBattle(Player& player, Pokemon& wildPokemon)
	{
		battleState.playerPokemon = player.chosenPokemon;
		battleState.wildPokemon = &wildPokemon;
		battleState.playerTurn = true;
		battleState.battleOnGoing = true;

		cout << "A wild " << wildPokemon.getName() << " appeared!\n";
		battle();
	}

	void BattleManager::battle()
	{
		while (battleState.battleOnGoing)
		{
			if (battleState.playerTurn)
			{
				battleState.playerTurn = false;
				battleState.playerPokemon -> selectAndUseMove(battleState.wildPokemon);
				updateBattleState();
			}

			else
			{
				battleState.playerTurn = true;
				battleState.wildPokemon -> selectAndUseMove(battleState.playerPokemon);
				updateBattleState();
			}
		}

		Utility::waitForEnter();
	}

	void BattleManager::handleBattleOutCome()
	{
		if (battleState.playerPokemon->isFainted())
		{
			cout << "Oh no! " << battleState.playerPokemon->getName() << " fainted! You need to visit the PokeCenter." << endl;
			cout << "Game Over.\n";
			Utility::waitForEnter();
		}

		if (battleState.wildPokemon->isFainted())
		{
			cout << "Victory! You defeated the wild " << battleState.wildPokemon->getName() << endl;
			Utility::waitForEnter();
		}

		Utility::waitForEnter();
	}

	void BattleManager::updateBattleState()
	{
		if (battleState.playerPokemon->isFainted()) 
		{
			battleState.battleOnGoing = false;
		}

		else if (battleState.wildPokemon->isFainted()) 
		{
			battleState.battleOnGoing = false;
		}
	}

	void BattleManager::stopBattle()
	{
		cout << "The battle has been stopped!" << endl;
	}

	void BattleManager::stopBattleInstance()
	{
		battleState.battleOnGoing = false;
	}
}