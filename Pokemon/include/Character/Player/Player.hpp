#pragma once

#include <string>

#include "../../Pokemon/Pokemon.hpp"

using namespace N_Pokemon;

namespace N_Player 
{
    class Player
    {
        public:
            string name;
            Pokemon* chosenPokemon;

            Player();
            Player(string p_name);
            void choosePokemon(int choice);
    };
}
