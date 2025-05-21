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

		Pokemon();

		Pokemon(string p_name, PokemonType p_type, int p_health);

		Pokemon(const Pokemon& p_other);

		~Pokemon();

		void attack();

		void takeDamage(int damage);

		bool isFainted() const;
};