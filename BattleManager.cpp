#include "Player.hpp"
#include "Pokemon.hpp"
#include "BattleManager.hpp"
#include <iostream>

using namespace std;

void BattleManager::startBattle(Player& player, Pokemon& wildPokemon)
{
	cout << "A wild " << wildPokemon.name << " appeared!" << endl;
	battle(player.chosenPokemon, wildPokemon);
}

void BattleManager::battle(Pokemon &playerPokemon, Pokemon& wildPokemon)
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

	handleBattleOutcome(playerPokemon, playerPokemon.isFainted());
}

void BattleManager::handleBattleOutcome(Player& player, bool playerWon)
{
	if (playerWon)
	{
		cout << player.chosenPokemon.name << " is victorius! Keep an eye on your Pokemon's health.\n";
	}

	else
	{
		cout << "Oh no! " << player.chosenPokemon.name << " fainted! You need to visit the PokeCenter.\n";
		Utility::waitForEnter();
		cout << "Game Over!\n";
	}
}
