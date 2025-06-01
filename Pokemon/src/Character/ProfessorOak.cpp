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
        cout << name << ": Hello there! Welcome to the world of Pokemon" << endl;
        Utility::waitForEnter();

        cout << name << ": My name is Oak. People call me the Pokemon Professor!" << endl;
        Utility::waitForEnter();

        cout << name << ": But enough about me. Let's talk about you" << endl;
        Utility::waitForEnter();
    }
    
    void ProfessorOak::offerPokemonChoices(Player& player)
    {
        cout << name << ": First of all, tell me. what's your name ?" << endl;
        getline(cin, player.name);

        cout << name << ": Ah! " << player.name << " Nice to meet you!" << endl;
        Utility::waitForEnter();

        cout << name << ": Are you ready for the adventure! But Dont you think ?" << endl;
        Utility::waitForEnter();

        cout << name << ": first you will need to have a Pokemon of your own." << endl;
        Utility::waitForEnter();

        cout << name << ": I have three Pokemon here with me. They are all quite feisty! \n" << endl;
        Utility::waitForEnter();

        cout << name << ": Choose wisely..." << endl;
        cout << "1. Bulbasaur - The grass type. Calm and collected! \n2. Charmander - The fire type. A real hothead! \n3. Squirtle - The water type. Cool and cucumber!" << endl;

        int choice;

        cout << "PROFESSOR OAK : So,which Pokemon would you like to choose ? Enter the number :";
        cin >> choice;

        player.choosePokemon(choice);

        Utility::waitForEnter();
    }
    void ProfessorOak::explainMainQuest(Player& player)
    {
        Utility::clearConsole();

        cout << "PROFESSOR OAK : Oak-ay " << player.name << "!, I am about to explain you about your upcoming grand adventure.\n";
        Utility::waitForEnter();

        cout << "PROFESSOR OAK : You see, becoming a Pokémon Master is no easy feat. It takes courage, wisdom, and a bit of luck!\n";
        Utility::waitForEnter();

        cout << "PROFESSOR OAK : Your mission, should you choose to accept it—and trust me, you really don’t have a choice—is to collect all the Pokémon Badges and conquer the Pokémon League.\n";
        Utility::waitForEnter();

        cout << "\n" << player.name << ": Wait... that sounds a lot like every other Pokémon game out there...\n";
        Utility::waitForEnter();

        cout << "PROFESSOR OAK : Shhh! Don't break the fourth wall, " << player.name << "! This is serious business!\n";
        Utility::waitForEnter();

        cout << "\nPROFESSOR OAK : To achieve this, you’ll need to battle wild Pokémon, challenge gym leaders, and of course, keep your Pokémon healthy at the PokeCenter.\n";
        Utility::waitForEnter();

        cout << "PROFESSOR OAK : Along the way, you'll capture new Pokémon to strengthen your team. Just remember—there’s a limit to how many Pokémon you can carry, so choose wisely!\n";
        Utility::waitForEnter();

        cout << "\n" << player.name << ": Sounds like a walk in the park... right?\n";
        Utility::waitForEnter();

        cout << "PROFESSOR OAK : Hah! That’s what they all say! But beware, young Trainer, the path to victory is fraught with challenges. And if you lose a battle... well, let’s just say you'll be starting from square one.\n";
        Utility::waitForEnter();

        cout << "\nPROFESSOR OAK : So, what do you say? Are you ready to become the next Pokémon Champion?\n";
        Utility::waitForEnter();

        cout << "\n" << player.name << ": Ready as I’ll ever be, Professor!\n";
        Utility::waitForEnter();

        cout << "\nPROFESSOR OAK : That’s the spirit! Now, your journey begins...\n";
        Utility::waitForEnter();

        cout << "PROFESSOR OAK : But first... let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!\n";
        Utility::waitForEnter();
    }
}
