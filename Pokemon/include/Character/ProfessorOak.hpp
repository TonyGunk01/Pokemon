#pragma once

#include <string>

#include "Player/Player.hpp"

using namespace N_Player;
using namespace std;
namespace N_Character
{
	class ProfessorOak
	{
		//PROPERTIES
		public:
		string name;

		//CONTRUCTOR
		ProfessorOak(string p_name);

		//METHOD FOR GREETING PLAYER
		void greetPlayer(Player& player);

		//METHOD FOR OFFERING POKEMON CHOICE
		void offerPokemonChoices(Player& player);

		//MAIN QUEST EXPLAINED
		void explainMainQuest(Player& player);
	};
}
