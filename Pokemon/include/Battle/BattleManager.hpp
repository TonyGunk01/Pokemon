#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Character/Player/Player.hpp" 
#include "../../include/Battle/BattleState.hpp"

namespace N_BattleManager
{ 
    class BattleManager 
    {
        public:
            void startBattle(N_Player::Player& player, N_Pokemon::Pokemon& wildPokemon); 

        private:
            N_BattleState::BattleState battleState;
            void battle();
            void battle(N_Pokemon::Pokemon& playerPokemon, N_Pokemon::Pokemon& wildPokemon);
            void handleBattleOutcome(N_Player::Player& player, bool playerWon); 
            void handleBattleOutcome(); 
            void updateBattleState();
    };
}