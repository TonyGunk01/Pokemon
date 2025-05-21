#include <string>
enum PokemonType;

using namespace std;

class Pokemon
{
	public:
		string name;
		PokemonType type;
		int health;
		int maxhealth;
		int attackPower;

		Pokemon();

		Pokemon(string p_name, PokemonType p_type, int p_maxHealth, int p_attackPower);

		Pokemon(const Pokemon& p_other);

		~Pokemon();

		void attack(Pokemon& target);

		void takeDamage(int damage);

		bool isFainted() const;

		void heal();
};