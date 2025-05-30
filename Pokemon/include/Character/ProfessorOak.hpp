#pragma once

#include <iostream>
#include "Player/Player.hpp" 

namespace N_ProfessorOak
{
    class ProfessorOak
    {
    private:
        std::string name;

    public:
        ProfessorOak(std::string p_name);
        void greetPlayer(N_Player::Player& player); 
        void offerPokemonChoices(N_Player::Player& player); 
        void explainMainQuest(N_Player::Player& player); 
    };
}
