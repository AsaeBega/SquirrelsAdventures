#pragma once
#include <string>
#include <map>
#include "gear.h"
#include "weapon.h"
#include "Loot.h"
#include "API/sleepy-discord/include/sleepy_discord/user.h"

class player {
private:
	std::string username;
	int level;
	 int exp;
	 int health;
	 int atk;
	 int def;
	std::map<std::string, int> inventory;
	/*here is space for player equipment*/
	weapon hands;
	helmet head;
	armor body;
	boots legs;
	//tail class_special;
	

	/*this constructor is used for loading player data from files*/
	player(std::string username, int level,  int exp,  int health,  int atk, int def, std::map<std::string, int> inventory,  weapon weapon, helmet helmet, armor armor, boots boots) {
		this->username = username;
		this->exp = exp;
		this->health = health;
		this->level = level;
		this->hands = weapon;
		this->body = armor;
		this->legs = boots;
		this->head = helmet;
		this->inventory = inventory;
		this->atk = atk;
		this->def = def;
	}

	/*this constructor is used for regestering new players*/
	player(SleepyDiscord::User user) {
		this->username = user.username;
		this->exp = 0;
		this->health = 250;
		this->atk = 20;
		this->def = 20;
		this->level = 1;
		//this->inventory = NULL;
	}
public:
	player regplayer(SleepyDiscord::User user) {
		return player(user);
	}
	/*here should be some player data file processing*/
	/*player loadplayer() {
		return player();
	}*/
	//////////////////////////////////////////////////////////
	void add_to_inv(player player, item item) {
		player.inventory.insert(std::make_pair(item.get_name(), player.inventory.count(item.get_name()) + 1));
	}
	void remove_from_inv(player player, item item){
		player.inventory.erase(item.get_name());
	}
	//////////////////////////////////////////////////////////
	 int get_health() {
		return this->health;
	}
	 int get_atk() {
		return this->atk;
	}
	 int get_def() {
		return this->def;
	}
	 int get_exp() {
		 return this->exp;
	 }
	 int get_lvl() {
		 return this->level;
	 }
	 weapon get_weapon() {
		 return this->hands;
	 }
	 helmet get_helmet() {
		 return this->head;
	 }
	 armor get_armor() {
		 return this->body;
	 }
	 boots get_boots() {
		 return this->legs;
	 }
	 ///////////////////////////////////////////////////////////

	void set_health(int health) {
		this->health = health;
	}
	void set_atk( int atk) {
		this->atk = atk;
	}
	void set_def(int def) {
		this->def = def;
	}
	void set_exp(int exp) {
		this->exp = exp;
	}
	void set_lvl(int lvl) {
		this->level = lvl;
	}
};