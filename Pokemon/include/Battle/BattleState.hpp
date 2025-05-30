#pragma once

#include "../../include/Pokemon/Pokemon.hpp" 

namespace N_BattleState
{ 
	struct BattleState
	{
		N_Pokemon::Pokemon *playerPokemon; 
		N_Pokemon::Pokemon *wildPokemon;  
		bool playerTurn;
		bool battleOngoing;
	};
}
