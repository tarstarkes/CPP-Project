#ifndef PLAYER_CHARACTER_HEADER
#define PLAYER_CHARACTER_HEADER
#include <string>
using namespace std;
class player_character{
	private:
		string name;
		string char_class;
		string race;
		int level;
		int current_scene;
		int max_hp;
		int current_hp;
		int attack;
		int armor_class;
		int strength;
		int dexterity;
		int constitution;
		int wisdom;
		int intelligence;
		int charisma;
		int magic;
		int gold;

	public:
		player_character();
		string get_name();
		string get_class();
		string get_race();
		int get_level();
		int get_scene();
		int get_max_hp();
		int get_current_hp();
		int get_attack();
		int get_armor_class();
		int get_strength();
		int get_dexterity();
		int get_constitution();
		int get_wisdom();
		int get_intelligence();
		int get_charisma();
		int get_magic();
		int get_gold();

		void set_name(const string n);
		void set_class(const string classToSet);
		void set_race(const string raceToSet);
		void set_level(const int x);
		void set_current_scene(const int x);
		void set_max_hp(const int x);
		void set_current_hp(const int x);
		void set_attack(const int x);
		void set_armor_class(const int x);
		void set_strength(const int x);
		void set_dexterity(const int x);
		void set_constitution(const int x);
		void set_wisdom(const int x);
		void set_intelligence(const int x);
		void set_charisma(const int x);
		void set_magic(const int x);
		void set_gold(const int x);
};

#endif
