#include <string>
#include <map>
#include "Loot.h"
#include "API/sleepy-discord/include/sleepy_discord/user.h"

class player {
private:
	SleepyDiscord::User user;
	size_t level;
	 int exp;
	 int health;
	 int atk;
	 int def;
	std::map<item, int> inventory;
	/*here is space for player equipment*/

	/*this constructor is used for loading player data from files*/
	player(SleepyDiscord::User user, size_t level,  int exp,  int health,  int atk,  int atk, std::map<int, int> inventory) {
		this->exp = exp;
		this->health = health;
		this->level = level;
		this->inventory = inventory;
		this->atk = atk;
		this->def = def;
	}

	/*this constructor is used for regestering new players*/
	player(SleepyDiscord::User user) {
		this->user = user;
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
	void add_to_inv(player player, item item) {
		player.inventory.insert(item);
	}
	 int get_health() {
		return this->health;
	}
	 int get_atk() {
		return this->atk;
	}
	 int get_def() {
		return this->def;
	}
	void set_health(int health) {
		this->health = health;
	}
	void set_atk( int atk) {
		this->atk = atk;
	}
	void set_def(ubsigned int def) {
		this->def = def;
	}
};