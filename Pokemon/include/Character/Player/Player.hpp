#pragma once

#include <string>
#include "../../Pokemon/Pokemon.hpp" 

using namespace std;

namespace N_Player
{ 
	class Player
	{
		public:
			string name;
			N_Pokemon::Pokemon* chosenPokemon; 

			Player();

			Player(string p_name, N_Pokemon::Pokemon* p_chosenPokemon); 

			~Player();

			void choosePokemon(int choice);

			const string& getName() const 
			{ 
				return name; 
			}
	};
}
