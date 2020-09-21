#include <string>
#include <map>
#include "gear.h"
#include "weapon.h"
#include "Loot.h"
#include "API/sleepy-discord/include/sleepy_discord/user.h"

class player {
private:
	std::string username;
	size_t level;
	 int exp;
	 int health;
	 int atk;
	 int def;
	std::map<item, int> inventory;
	/*here is space for player equipment*/
	weapon hands;
	helmet head;
	armor body;
	boots legs;
	//tail class_special;
	

	/*this constructor is used for loading player data from files*/
	player(std::string username, size_t level,  int exp,  int health,  int atk,  int atk, std::map<int, int> inventory) {
		this->username = username;
		this->exp = exp;
		this->health = health;
		this->level = level;
		this->inventory = inventory;
		this->atk = atk;
		this->def = def;

	}

	/*this constructor is used for regestering new players*/
	player(SleepyDiscord::User user) {
		this->user = user.username;
		this->exp = 0;
		this->health = 250;
		this->atk = 20;
		this->def = 20;
		this->level = 1;
		this->inventory = NULL;
	}
public:
	player regplayer(SleepyDiscord::User user) {
		return player(user);
	}
	/*here should be some player data file processing*/
	player loadplayer() {
		return player();
	}
	//////////////////////////////////////////////////////////
	void add_to_inv(player player, item item) {
		player.inventory.insert(std::make_pair(item, player.inventory.count(item) + 1));
	}
	void remove_from_inv(player player, item item){
		player.inventory.erase(item)
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