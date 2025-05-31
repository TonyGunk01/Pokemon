#pragma once

#include "../../include/Pokemon/Grass.hpp"
#include "../../include/Character/Player/Player.hpp" 

namespace N_Game
{
    class Game
    {
        private:
            N_grass::Grass forestGrass; 

        public:
            Game();
            void gameLoop(N_Player::Player& player); 
    };
}