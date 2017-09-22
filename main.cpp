#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "player_character.h"

using namespace std;
string getFileContents(ifstream&);
void configtela();
int start_game();
string validate_string();
int validate_int();
void save_char();
void show_char_stats();
void start_scene();
bool load_game();
player_character character;

int main(){
	configtela();
	cout << "Loading..." << endl;
	string input;
	int count = 0;
	while(count < 2){
		cout << "\\" << "\r";
		Sleep(250);
		cout << "|" << "\r";
		Sleep(250);
		cout << "/" << "\r";
		Sleep(250);
		cout << '-' << "\r";
		Sleep(250);
		count++;
		cout << "";
	}
	cout << "DONE!" << endl;
	ifstream Reader("art/game_loaded.txt");
	string Art = getFileContents(Reader);
	Reader.close();
	cout << Art << endl;
	start_game();
	return 0;
}

void set_class(string char_class){
	if(char_class == "Fighter"){
		character.set_class("Fighter");
		character.set_max_hp(12);
		character.set_current_hp(12);
	}
	if(char_class == "Cleric"){
		character.set_class("Cleric");
		character.set_max_hp(10);
		character.set_current_hp(10);
	}
	if(char_class == "Thief"){
		character.set_class("Thief");
		character.set_max_hp(8);
		character.set_current_hp(10);
	}
	if(char_class == "Wizard"){
		character.set_class("Wizard");
		character.set_max_hp(6);
		character.set_current_hp(6);
	}
}

void set_race(string char_race){
	if(char_race == "Human"){
		character.set_race("Human");
	}
	if(char_race == "Elf"){
		character.set_race("Elf");
	}
	if(char_race == "Halfling"){
		character.set_race("Halfling");
	}
	if(char_race == "Dwarf"){
		character.set_race("Dwarf");
	}
}


string getFileContents(ifstream& File){
	string Lines = "";
	if (File){
		while(File.good()){
			string TempLine;
			getline(File, TempLine);
			TempLine += "\n";
			Lines = Lines + TempLine;
		}
		return Lines;
	}
	else{
		return "Error File does not exist";
	}
}

void configtela(){
	HWND hwnd = GetConsoleWindow();
	if( hwnd != NULL ){ 
		MoveWindow(hwnd, 150, 150, 1200, 680, TRUE); 
	}
}

string validate_string(string options[], int length, string msg){
	string response;
	bool cont = TRUE;
	while(cont){
		cout << msg << endl;
		cin >> response;
		if(response == "SAVE"){
			save_char();
		}
		if(response == "STATS"){
			show_char_stats();
		}
		for(int x=0; x < length; x++){
			if(response == options[x]){
				cont=FALSE;
			}
		}
		if(cont && response != "SAVE" && response != "STATS"){
			cout << "\nThat is not an appropriate response, please try again!" << endl;
		}
	}
	return response;
}

int validate_int(){
	string response;
	bool cont = TRUE;
	while(cont){
		cout << msg << endl;
		cin >> response;
		if(response == "SAVE"){
			save_char();
		}
		if(response == "STATS"){
			show_char_stats();
		}
		for(int x=0; x < length; x++){
			if(response == options[x]){
				cont=FALSE;
			}
		}
		if(cont && response != "SAVE" && response != "STATS"){
			cout << "\nThat is not an appropriate response, please try again!" << endl;
		}
	}
	return 0;
}

int start_game(){
	string class_options[4] = {"Fighter", "Cleric", "Thief", "Wizard"};
	string race_options[4] = {"Human", "Elf", "Halfling", "Dwarf"};
	string new_or_load[2] = {"NEW_GAME", "LOAD"};
	string msg;
	string response;
	string char_name;
	string char_class;
	string char_race;
	bool loaded = FALSE;

	while(loaded == FALSE){
		msg = "Would you like to start a start a [NEW_GAME] or [LOAD] a saved one? >> ";
		response = validate_string(new_or_load, 2, msg);
		if(response == "NEW_GAME"){
			character = player_character();
			cout << "Welcome to Darkness, a single-player, text-based, adventure game where you get to be the hero! To start, please choose a character name, this is the name by which you will be called from now to the end of the game, so pick your name carefully. >> ";
			cin >> char_name;
			character.set_name(char_name);
			msg = "\n" + char_name + " Hmmm. That's an interesting name! Well " + char_name + " I am the dungeon master, I will be dictating to you what happens in the story from this point on, but before we get started you need to choose a class. You can choose from the following options: [Fighter], [Cleric], [Thief], or [Wizard]. Please type the name of the class you wish to play. Your class determines what kind of abilities and equipment your character has access to, so choose wisely. >> ";
			char_class = validate_string(class_options, 4, msg);
			set_class(char_class);
			msg = "\nA " + char_class + ". How interesting! Alright, last thing. We have a class and a name for your character, but we still need a race. You can choose from the following options for your character: [Human], [Elf], [Halfling], [Dwarf]. Just type the name of the Race you want to play into the console >> ";
			char_race = validate_string(race_options, 4, msg);
			set_race(char_race);
			cout << "\nSo you are playing a " << char_race << " " << char_class << " named " << char_name << " eh? Sounds good! Ok, let's get started! From here on out, if you wish to save your character, simply type [SAVE] and hit enter, likewise if you would like to view the stats for your character, type [STATS] and hit enter. The previous message will be repeated after this propting you to again make a choice. >>";
			loaded = TRUE;
		}
		if(response == "LOAD"){
			loaded = load_game();
		}
	}	

	start_scene();
	return 0;
}
void save_char(){

}
void show_char_stats(){
	cout << "\nNAME: " << character.get_name() << "\nCLASS: " << character.get_class() << "\nRACE: " << character.get_race() 
	<< "\nLevel: " << character.get_level() << "\nHP: " << character.get_current_hp() << "/" << character.get_max_hp() << "\nATTACK: " 
	<< character.get_attack() << "\nMAGIC: " << character.get_magic() << "\nAC: " << character.get_armor_class() << "\nSTR: " << character.get_strength() << "\tDEX: "
	<< character.get_dexterity() << "\nCON: " << character.get_constitution() << "\tINT: " << character.get_intelligence() 
	<< "\nWIS: " << character.get_wisdom() << "\tCHA: " << character.get_charisma()	<< "\nGOLD: " << character.get_gold() << "gp" << endl;
}
bool load_game(){
	ifstream file("char/characters.txt");
	string buffer;
	bool loaded = FALSE;
	int x = 0;
	int save_num = 1;
	while(file.good()){
		getline(file, buffer);
		x = 0;
		cout << "1. "
		while(buffer[x] != ' '){
			cout << buffer[x];
			x++;
		}
		cout << endl;
		save_num++;
	}
 	msg << "Please enter the number corresponding to the saved game you wish to load. >> ";
 	
	return loaded;

}
void start_scene(){
	string response;
	string msg = "";
	string options[2] = {"test", "test1"};
	validate_string(options, 2, msg);
}