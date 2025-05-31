#pragma once

#include <vector>
#include <string>
#include "Pokemon.hpp" 

using namespace std;

namespace N_grass
{
	struct Grass
	{
		string environmentType;
		vector<N_Pokemon::Pokemon*> wildPokemonList;
		int encounterRate;

		Grass(const string& envType, const vector<N_Pokemon::Pokemon*>& wildPokemon, int rate) : environmentType(envType), wildPokemonList(wildPokemon), encounterRate(rate) 
		{
		
		}
		
		~Grass() 
		{
			for (auto p : wildPokemonList) delete p;
		}
	};
}
