#pragma once

#include <string>

using namespace std;

namespace N_Pokemon
{
	struct Move
	{
		string name;
		int damage;
		int originalDamage;

		Move(const string& moveName, int moveDamage) 
			: name(moveName), damage(moveDamage), originalDamage(moveDamage)
		{
			name = moveName;
			damage = moveDamage;
			originalDamage = moveDamage; 
		}
	};
}