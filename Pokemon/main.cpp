#include "include/Pokemon/PokemonChoice.hpp"
#include "include/Pokemon/PokemonType.hpp"
#include "include/Utility/Utility.hpp"
#include "include/Character/Player/Player.hpp"
#include "include/Character/ProfessorOak.hpp"
#include "include/Main/Game.hpp"

#include <iostream>
#include <string>
#include <limits>

using namespace N_Pokemon;
using namespace N_Player;
using namespace N_Utility;
using namespace N_Character;
using namespace N_Main;
using namespace std;

int main()
{
    ProfessorOak* professor = new ProfessorOak("Professor Oak");
    Player* player = new Player();

    professor->greetPlayer(*player);
    professor->offerPokemonChoices(*player);

    professor->explainMainQuest(*player);

    Game* game = new Game();
    game->gameLoop(player);

    system("pause");

    delete professor;
    delete player;
    delete game;

    professor = nullptr;
    player = nullptr;
    game = nullptr;

    return 0;

}