#include "../../include/Pokemon/Pokemon.hpp"
#include "../../include/Character/Player/Player.hpp"
#include "../../include/Battle/BattleState.hpp"

class BattleManager 
{
    public:
        void startBattle(Player& player, Pokemon& wildPokemon);

    private:
        BattleState battleState;
        void battle();
        void battle(Pokemon& playerPokemon, Pokemon& wildPokemon);
        void handleBattleOutcome(Player& player, bool playerWon); 
        void handleBattleOutcome(); 
        void updateBattleState();
};