#pragma once

#include "../Pokemon/Grass.hpp"
#include "../Character/Player/Player.hpp"

#include <vector>

using namespace N_Player;
using namespace N_Pokemon;

namespace N_Main 
{
	class Game
	{
		bool keepPlaying = true;
		int choice;

		private:
			Grass forestGrass;
			Pokemon* wildPokemon;

		public:
			Game();
			~Game();
			void gameLoop(Player* player);
			void visitPokeCenter(Player* player);
	};
}
