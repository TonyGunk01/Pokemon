#include "include/Main/Game.hpp"
#include "include/Character/Player/Player.hpp"
#include "include/Pokemon/PokemonChoice.hpp"
#include "include/Pokemon/PokemonType.hpp"
#include "include/Character/ProfessorOak.hpp"
#include "include/Utility/Utility.hpp"

#include <iostream>
#include <limits> 
#include <string>
#include <stdlib.h>

using namespace std;
using namespace N_ProfessorOak;
using namespace N_Game;
using namespace N_Player; 

int main()  
{  
    ProfessorOak* professor = new ProfessorOak("Professor Oak");  
    Player* player = new Player();

    professor -> greetPlayer(*player);  
    professor -> offerPokemonChoices(*player);  

    professor -> explainMainQuest(*player);  

    Game* game = new Game();  
    game -> gameLoop(*player);  

    delete(professor);
    delete(player);
    delete(game);

    return 0;  
}