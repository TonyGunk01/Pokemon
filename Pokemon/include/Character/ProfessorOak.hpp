#pragma once

#include <iostream>
#include "Player/Player.hpp" 

using namespace std;
using namespace N_Player;

namespace N_ProfessorOak
{
    class ProfessorOak
    {
        private:
            string name;

        public:
            ProfessorOak(string p_name);
            void greetPlayer(Player& player); 
            void offerPokemonChoices(Player& player); 
            void explainMainQuest(Player& player); 
    };
}
