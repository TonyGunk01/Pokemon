#pragma once

#include <string>
#include "Player/Player.hpp"

using namespace N_Player;
using namespace std;

namespace N_Character
{
	class ProfessorOak
	{
		public:
		string name;

		ProfessorOak(string p_name);

		void greetPlayer(Player& player);

		void offerPokemonChoices(Player& player);

		void explainMainQuest(Player& player);
	};
}
