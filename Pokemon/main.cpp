#include<iostream>
#include<string>
using namespace std;

enum class PokemonChoice 
{
    CHARMANDER = 1,
    BULBASAUR,
    SQUIRTLE,
    PIKACHU
};

enum class PokemonType 
{
    FIRE,
    GRASS,
    WATER,
    ELECTRIC
};

class Pokemon 
{
    public:
        string name;
        PokemonType type;
        int health;

        Pokemon() 
        {
            name = "Unknown";
            type = PokemonType::Normal;
            health = 50;
            cout << "A new Pokemon has been created with the default constructor!\n";
        }

        Pokemon(string p_name, PokemonType p_type, int p_health) 
        {
            name = p_name;
            type = p_type;
            health = p_health;
            cout << "A new Pokemon named " << name << " has been created!\n";
        }

        Pokemon(const Pokemon& other)
        {
            name = other.name;
            type = other.type;
            heatlh = other.health;
            cout << "A new Pokemon has been copied from " << other.name << "!\n";
        }

        ~Pokemon()
        {
            cout << name << " has been released!\n";
        }

        void attack() 
        { 
            cout << name << "attacks with a powerful move!\n"; 
        }
};

class Player 
{
    public:
        string name;
        Pokemon chosenPokemon;

        Player()
        {
            name = "Trainer";
            chosenPokemon = Pokemon();
            cout << "A new player named " << name << " has been created!\n";
        }

        Player(std::string p_name, Pokemon p_chosenPokemon)
        {
            name = p.name;
            chosenPokemon = p_chosenPokemon;
            cout << "Player " << name << " has been created!\n";
        }

        void choosePokemon(int choice) 
        {
            switch ((PokemonChoice)choice) 
            {
                case PokemonChoice::CHARMANDER:
                    chosenPokemon = Pokemon("Charmander", PokemonType::FIRE, 100);
                    break;

                case PokemonChoice::BULBASAUR:
                    chosenPokemon = Pokemon("Bulbasaur", PokemonType::GRASS, 100);
                    break;

                case PokemonChoice::SQUIRTLE:
                    chosenPokemon = Pokemon("Squirtle", PokemonType::WATER, 100);
                    break;

                default:
                    chosenPokemon = Pokemon("Pikachu", PokemonType::ELECTRIC, 100);
                    break;
            }

            cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
        }
};

class ProfessorOak 
{
    public:
        string name;

        void greetPlayer(Player& player) 
        {
            cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
            cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
            cout << name << ": But enough about me. Let's talk about you!\n";
        }

        void offerPokemonChoices(Player& player) 
        {
            cout << name << ": First, tell me, what�s your name?\n";
            getline(cin, player.name);
            cout << endl << name << ": Ah, " << player.name << "! What a fantastic name!\n";
            cout << name << ": You must be eager to start your adventure. But first, you�ll need a Pokemon of your own!\n";

            cout << name << ": I have three Pokemon here with me. They�re all quite feisty!\n";
            cout << name << ": Choose wisely...\n"; cout << "1. Charmander - The fire type. A real hothead!\n";
            cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
            cout << "3. Squirtle - The water type. Cool as a cucumber!\n";

            int choice;
            cout << name << ": So, which one will it be? Enter the number of your choice: ";
            cin >> choice;
            player.choosePokemon(choice);
        }
};

int main() 
{
    Pokemon defaultPokemon;
    Pokemon charmander("Charmander", PokemonType::FIRE, 100);

    cout << "Pokemon Details:\n";
    cout << "Name: " << defaultPokemon.name << "\nType: " << (int)defaultPokemon.type << "\nHealth: " << defaultPokemon.health << "\n";
    cout << "Name: " << charmander.name << "\nType: " << (int)charmander.type << "\nHealth: " << charmander.health << "\n";

    Pokemon bulbasaur("Bulbasaur", PokemonType::GRASS, 100);
    Pokemon bulbasaurCopy = bulbasaur;
    cout << "Original Pokemon Health: " << bulbasaur.health << "\n";
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << "\n";

    bulbasaurCopy.health = 80;
    cout << "After Modification:\n";
    cout << "Original Pokemon Health: " << bulbasaur.health << "\n";
    cout << "Copied Pokemon Health: " << bulbasaurCopy.health << "\n";

    Pokemon squirtle("Squirtle", PokemonType::WATER, 100);

    ProfessorOak professor("Professor Oak");
    Player player("Ash", charmander);

    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);
 
    cout << "Professor Oak: " << player.chosenPokemon.name << " and you, " << player.name << ", are going to be the best of friends!\n";
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!\n";

    return 0;
}