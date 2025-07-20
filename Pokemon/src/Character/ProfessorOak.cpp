#include <iostream>
#include <string>

#include "../../include/Utility/Utility.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Character/ProfessorOak.hpp"

using namespace N_Utility;
using namespace N_Player;
using namespace N_Character;
using namespace std;

namespace N_Character 
{
    ProfessorOak::ProfessorOak(string p_name)
    {
        name = p_name;
    }
    
    void ProfessorOak::greetPlayer(Player& player)
    {
        cout << name << ": Hello there! Welcome to the world of Pokemon!" << endl;
        Utility::delay(2000);

        cout << "\n" << name << ": My name is Oak. People call me the Pokemon Professor!" << endl;
        Utility::delay(2000);

        cout << "\n" << name << ": But enough about me. Let's talk about you!" << endl;
        Utility::delay(2000);
    }
    
    void ProfessorOak::offerPokemonChoices(Player& player)
    {
        cout << "\n" << name << ": First of all, tell me. What's your name?\n\n";
        getline(cin, player.name);

        cout << "\n" << name << ": Ah! " << player.name << ", nice to meet you!" << endl;
        Utility::delay(2000);

        cout << "\n" << name << ": First, you will need to have a Pokemon of your own." << endl;
        Utility::delay(2000);

        cout << "\n" << name << ": I have three Pokemon here with me. They are all quite feisty!" << endl;
        Utility::delay(2000);

        cout << "\n" << name << ": Choose wisely..." << endl;
        cout << "\n1. Bulbasaur - The grass type. Calm and collected!";
		Utility::delay(1200);
        cout << "\n2. Charmander - The fire type. A real hothead!";
		Utility::delay(1200);   
        cout << "\n3. Squirtle - The water type. Cool as a cucumber!" << endl;
		Utility::delay(1200);

        int choice;

        cout << "\n" << name << ": So, which Pokemon would you like to choose ? Enter the number : ";
        cin >> choice;

		Utility::delay(1200);
        player.choosePokemon(choice);
    }

    void ProfessorOak::explainMainQuest(Player& player)
    {
        Utility::clearConsole();

        cout << name << ": Okey dokey " << player.name << ", I'm gonna explain to you about your upcoming grand adventure!\n";
        Utility::delay(2200);

        cout << "\n" << name << ": You see, becoming a Pokemon Master is no easy feat. It takes courage, wisdom and a bit of luck!\n";
        Utility::delay(2500);

        cout << "\n" << name << ": Your mission, should you choose to accept it, and trust me, you really don't have a choice, is to collect all the Pokemon Badges and conquer the Pokemon League!\n";
        Utility::delay(3000);

        cout << "\n" << player.name << ": Wait, that sounds a lot like every other Pokemon game out there!\n";
        Utility::delay(2200);

        cout << "\n" << name << ": Shhh! Don't break the fourth wall, " << player.name << "! This is serious business!\n";
        Utility::delay(2500);

        cout << "\n" << name << ": To achieve this, you'll need to battle wild Pokemon, challenge gym leaders, and of course, keep your Pokemon healthy at the PokeCenter.\n";
        Utility::delay(2500);

        cout << "\n" << name << ": Along the way, you'll capture new Pokemon to strengthen your team. Just remember: there's a limit to how many Pokemon you can carry, so choose wisely!\n";
        Utility::delay(2600);

        cout << "\n" << player.name << ": Sounds like a walk in the park, right?\n";
        Utility::delay(2000);

        cout << "\n" << name << ": Hah! That's what they all say! But beware, young Trainer, the path to victory is fraught with challenges. And if you lose a battle, well, let's just say you'll be starting from square one.\n";
        Utility::delay(3000);

        cout << "\n" << name << ": So, what do you say? Are you ready to become the next Pokemon Champion? \n";
        Utility::delay(2200);

        cout << "\n" << player.name << ": Ready as I'll ever be, Professor!\n";
        Utility::delay(2000);

        cout << "\n" << name << ": That's the spirit! Now, your journey begins!\n";
        Utility::delay(2000);
        Utility::waitEffect();
    }
}
