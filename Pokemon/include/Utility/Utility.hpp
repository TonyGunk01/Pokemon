#pragma once

#include <iostream>
#include <limits>
#include "../Character/Player/Player.hpp" // Include the Player header
#include "../Pokemon/Pokemon.hpp"        // Include the Pokemon header

namespace N_Utility
{
    class Utility
    {
        public:
            static void clearConsole();
            static void enter();
            static void clearInputBuffer();
            static void delay(int s);
            static void waitEffect();
            static string pokemonUse();
            static void heavyHit();
            static string world();
    };
}