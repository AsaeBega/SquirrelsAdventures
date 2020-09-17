#include <string>
#include <map>
#include "API/sleepy-discord/include/sleepy_discord/user.h"

using namespace SleepyDiscord;
class player {
private:
	User user;
	size_t level;
	unsigned int exp;
	unsigned int health;
	std::map<int, int> inventory;
	/*here is space for player equipment*/

	/*this constructor is used for loading player data from files*/
	player(User user, size_t level, unsigned int exp, unsigned int health, std::map<int, int> inventory) {
		this->exp = exp;
		this->health = health;
		this->level = level;
		this->inventory = inventory;
	}

	/*this constructor is used for regestering new players*/
	player(User user) {
		this->user = user;
		this->exp = 0;
		this->health = 150;
		this->level = 1;
		this->inventory = NULL;
	}
public:
	player regplayer(User user) {
		return player(user);
	}
	/*here should be some player data file processing*/
	player loadplayer() {
		return player();
	}
};