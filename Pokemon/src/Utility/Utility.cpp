#include "../../include/Utility/Utility.hpp"

#include <iostream>  
#include <limits>  
#include <thread>
#include <chrono>
#include <cstdlib>
#include "../../include/Character/Player/Player.hpp"

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;  

namespace N_Utility 
{
    void Utility::clearConsole()
    {
        #ifdef _WIN32  
                system("cls");
        #else  
                system("clear");
        #endif  
    }

    void Utility::enter()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void Utility::clearInputBuffer()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void Utility::delay(int s)
    {
		sleep_for(milliseconds(s));
    }

    void Utility::waitEffect()
    {
        int c = rand() % 3 + 3;

        for (int i = 0; i < c; ++i)
        {
            cout << ".";
            sleep_for(milliseconds(500));
        }

        cout << " ";
	}

    //implement vectors
    //change from Utility to seperate c++
    string Utility::pokemonUse()
    {
        int line = (rand() % 4) + 1;

        switch (line)
        {
            case 1:
                return " Go, ";
                break;

            case 2:
                return " Fight it, ";
                break;

            case 3:
                return " Protect me now, ";
                break;

            default:
                return " Be brave, ";
                break;
        }

        Utility::delay(2000);
    }

    //implement vectors
    //change from Utility to seperate c++
    void Utility::heavyHit()
    {
        int line = (rand() % 4) + 1;

        cout << "\n";

        switch (line)
        {
            case 1:
                cout << "Oof, that was a heavy hit!";
                break;

            case 2:
                cout << "Ouch, that must've hurt!";
                break;

            case 3:
				cout << "Oh no, that is going to leave a mark!";

            default:
                cout << "Ow, that should've been painful!";
                break;
        }

		cout << "\n";
        Utility::delay(1500);
    }

    string Utility::world()
    {
        std::vector<std::string> regions = {
                "Pallet Town",
                "Viridian City",
                "Pewter City",
                "Cerulean City",
                "Vermilion City",
                "Lavender Town",
                "Celadon City",
                "Fuchsia City",
                "Saffron City",
                "Cinnabar Island"
        };
        
        srand(time(nullptr));

        int randomIndex = rand() % regions.size();
        return regions[randomIndex];
    }
}