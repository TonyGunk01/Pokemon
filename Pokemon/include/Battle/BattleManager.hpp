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

        static void stopBattle();

	private:
		BattleState battleState;

		void battle();
		void handleBattleOutcome(); 

	};
}