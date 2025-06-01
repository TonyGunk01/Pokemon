#pragma once

#include "BattleState.hpp"
#include "../Character/Player/Player.hpp"

using namespace N_Player;

namespace N_Battle
{
	class BattleManager
	{
	public:
		BattleManager() = default;

		void startBattle(Player& player, Pokemon& wildPokemon);
		void updateBattleState();

	private:
		BattaleState battleState;

		void battle();
		void handleBattleOutCome();

	};
}