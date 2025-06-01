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
				battleState.playerPokemon->attack(battleState.wildPokemon);
				updateBattleState();
			}

			else
			{
				battleState.wildPokemon->attack(battleState.playerPokemon);
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
		}

		if (battleState.wildPokemon->isFainted())
		{
			cout << "You defeated the wild " << battleState.wildPokemon->getName() << endl;
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
}