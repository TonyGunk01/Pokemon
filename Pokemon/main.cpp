#include "include/Character/ProfessorOak.hpp"
#include "include/Main/Game.hpp"
#include "include/Character/Player/Player.hpp"

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    ProfessorOak professor("Professor Oak");
    Player player;

    professor.greetPlayer(player);
	professor.offerPokemonChoices(player);

    professor.explainMainQuest(player);

    Game game;
    game.gameLoop(player);

    return 0;

}