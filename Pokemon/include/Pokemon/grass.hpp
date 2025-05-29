#pragma once

#include <vector>
#include <string>
#include "Pokemon.hpp"

using namespace std;

struct Grass
{
	string environmentType;
	vector<Pokemon> wildPokemonList;
	int encounterRate;
};
