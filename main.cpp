#include <iostream>
#include <string>
using namespace std;

enum class PokemonChoice {

    Charmander,
    Bulbasaur,
    Squirtle,
    InvalidChoice
};

int main() {

    string name;
    PokemonChoice ch_pokemon = PokemonChoice::InvalidChoice;

    cout << "Professor Oak: Hello there! Welcome to the world of Pokemon!\n";
    cout << "Professor Oak: My name is Oak. People call me the Pokemon Professor!\n";
    cout << "Professor Oak: But enough about me. Let's talk about you!\n";

    cout << "Professor Oak: First, tell me, what’s your name?\n";
    cin >> name;

    cout << "Professor Oak: Ah, " << name << "! What a fantastic name!\n";
    cout << "Professor Oak: You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!\n";

    cout << "Professor Oak: I have three Pokemon here with me. They’re all quite feisty!\n";
    cout << "Professor Oak: Choose wisely...\n";
    cout << "Choice 1. Charmander - The fire type. A real hothead!\n";
    cout << "Choice 2. Bulbasaur - The grass type. Calm and collected!\n";
    cout << "Choice 3. Squirtle - The water type. Cool as a cucumber!\n";

    int ch;

    cout << "Professor Oak: So, which one will it be? Enter the number for your choice: ";
    cin >> ch;

    switch (ch) {

    case 1:
        ch_pokemon = PokemonChoice::Charmander;
        break;

    case 2:
        ch_pokemon = PokemonChoice::Bulbasaur;
        break;

    case 3:
        ch_pokemon = PokemonChoice::Squirtle;
        break;

    default:
        ch_pokemon = PokemonChoice::InvalidChoice;
        break;

    }

    switch (ch_pokemon) {

    case PokemonChoice::Charmander:
        cout << "Professor Oak: A fiery choice! Charmander is yours!\n";
        break;

    case PokemonChoice::Bulbasaur:
        cout << "Professor Oak: A fine choice! Bulbasaur is always ready to grow on you!\n";
        break;

    case PokemonChoice::Squirtle:
        cout << "Professor Oak: Splendid! Squirtle will keep you cool under pressure!\n";
        break;

    default:
        cout << "Professor Oak: Hmm, that doesn't seem right. Let me choose for you...\n";
        ch_pokemon = PokemonChoice::Charmander;
        cout << "Professor Oak: Just kidding! Let's go with Charmander, the fiery dragon in the making!\n";
        break;

    }

    cout << "Professor Oak: " << (ch_pokemon == PokemonChoice::Charmander ? "Charmander" : ch_pokemon == PokemonChoice::Bulbasaur ? "Bulbasaur" : "Squirtle") << " and you, " << name << ", are going to be the best of friends!\n";
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!\n";

    return 0;
}