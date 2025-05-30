#include "include/Character/ProfessorOak.hpp"  
#include "include/Main/Game.hpp"  
#include "include/Character/Player/Player.hpp" // Ensure Player.hpp is included  

#include <iostream>  
#include <string>  
#include <limits>  
using namespace N_Game;

using namespace std;  
using namespace N_Player; 

int main()  
{  
    N_ProfessorOak::ProfessorOak professor("Professor Oak");  
    N_Player::Player player; 

    professor.greetPlayer(player);  
    professor.offerPokemonChoices(player);  

    professor.explainMainQuest(player);  

    Game game;  
    game.gameLoop(player);  

    return 0;  
}