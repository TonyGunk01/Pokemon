#include <iostream>

#include "../../../include/Pokemon/Pokemons/Caterpie.hpp"
#include "../../../include/Pokemon/PokemonType.hpp"
#include "../../../include/Utility/Utility.hpp"

using namespace N_Pokemon;

namespace N_Pokemon
{
	namespace N_Pokemons
	{
		Caterpie::Caterpie() :
			Pokemon("Caterpie", PokemonType::Bug, 100, {
					Move("Bug Bite", 25),
					Move("Tackle", 10)
				}) {
		}

        void Caterpie::attack(Move selectedMove, Pokemon* target)
        {
            int selectedMoveIndex = selectMove();
            selectedMove = moves[selectedMoveIndex]; 

            Pokemon::attack(selectedMove, target);
            selectAndUseMove(target);

            if (selectedMove.name == "Sticky Web")
            {
                int reducedDamage = 5;

                target->reduceAttackPower(reducedDamage);
            }
        }
	}
}