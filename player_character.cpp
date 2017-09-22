#include "player_character.h"

using namespace std;

player_character::player_character(){
	name = "";
	char_class = "";
	race = "";
	level = 1;
	current_scene = 0;
	max_hp = 0;
	current_hp = 0;
	attack = 0;
	armor_class = 0;
	strength = 0;
	dexterity = 0;
	constitution = 0;
	wisdom = 0;
	intelligence = 0;
	charisma = 0;
	magic = 0;
	gold = 0;
}
//get functions
string player_character::get_name(){
	return name;
}
string player_character::get_class(){
	return char_class;
}
string player_character::get_race(){
	return race;
}
int player_character::get_level(){
	return level;
}
int player_character::get_scene(){
	return current_scene;
}
int player_character::get_max_hp(){
	return max_hp;
}
int player_character::get_current_hp(){
	return current_hp;
}
int player_character::get_attack(){
	return attack;
}
int player_character::get_armor_class(){
	return armor_class;
}
int player_character::get_strength(){
	return strength;
}
int player_character::get_dexterity(){
	return dexterity;
}
int player_character::get_constitution(){
	return constitution;
}
int player_character::get_wisdom(){
	return wisdom;
}
int player_character::get_intelligence(){
	return intelligence;
}
int player_character::get_charisma(){
	return charisma;
}
int player_character::get_magic(){
	return magic;
}
int player_character::get_gold(){
	return gold;
}

void player_character::set_name(const string n){
	name = n;
}
void player_character::set_class(const string classToSet){
	char_class = classToSet;
}
void player_character::set_race(const string raceToSet){
	race = raceToSet;
}
void player_character::set_level(const int x){
	level = x;
}
void player_character::set_current_scene(const int x){
	current_scene = x;
}
void player_character::set_max_hp(const int x){
	max_hp = x;
}
void player_character::set_current_hp(const int x){
	current_hp = x;
}
void player_character::set_attack(const int x){
	attack = x;
}
void player_character::set_armor_class(const int x){
	armor_class = x;
}
void player_character::set_strength(const int x){
	strength = x;
}
void player_character::set_dexterity(const int x){
 	dexterity = x;
}
void player_character::set_constitution(const int x){
 	constitution = x;
}
void player_character::set_wisdom(const int x){
	wisdom = x;
}
void player_character::set_intelligence(const int x){
 	intelligence = x;
}
void player_character::set_charisma(const int x){
	charisma = x;
}
void player_character::set_magic(const int x){
 	magic = x;
}
void player_character::set_gold(const int x){
 	gold = x;
}
