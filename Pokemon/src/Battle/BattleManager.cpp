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

		cout << "\n\nA wild " << wildPokemon.getName() << " appeared!\n\n";
		Utility::delay(2000);
        cout << player.name << ":" << Utility::pokemonUse() << player.chosenPokemon->getName() << "!\n";
		Utility::delay(2000);
		battle();
	}

	void BattleManager::battle()
	{
		while (battleState.battleOnGoing)
		{	
			if (battleState.playerTurn)
			{
				if (battleState.playerPokemon->canAttack())
				{
					battleState.playerPokemon->selectAndUseMove(battleState.wildPokemon);
				}
			}

			else
			{
				if (battleState.wildPokemon->canAttack())
				{
					battleState.wildPokemon->selectAndUseMove(battleState.playerPokemon);
				}
			}

			handleBattleOutcome();
		}
	}

	void BattleManager::handleBattleOutcome()
	{
		if (battleState.playerPokemon->isFainted())
		{
			cout << "\nOh no! Your " << battleState.playerPokemon->getName() << " fainted! You need to visit the PokeCenter immediately!" << endl;
			Utility::delay(3000);
			battleState.wildPokemon->resetValues();
			battleState.battleOnGoing = false;
		}

		if (battleState.wildPokemon->isFainted())
		{
			cout << "\nVictory! You defeated the wild " << battleState.wildPokemon->getName() << "!" << endl;
			Utility::delay(1500);
			Utility::waitEffect();
			Utility::delay(2000);
			battleState.wildPokemon->resetValues();
			battleState.battleOnGoing = false;
		}
		
		battleState.playerTurn = !battleState.playerTurn;
	}

	void BattleManager::stopBattle()
	{
		cout << "\nThe battle has been stopped!" << endl;
		Utility::enter();
	}
}