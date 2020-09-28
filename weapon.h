
#include <string>
#include "item.h"
enum class weapontype {
	NONE,
	SWORD,
	BOW,
	WAND
};

class weapon : public item {
private:
	weapontype type;
	int atk;
	int def;
	protected:
	weapon(int atk, int def, weapontype type, std::string name) :item(name) {
		this->atk = atk;
		this->def = def;
		this->type = type;
	}
public:
	weapon() :item("Empty Slot") {
		this->atk = 0;
		this->def = 0;
		this->type = weapontype::NONE;
	}
public:
	int get_atk() {
		return this->atk;
	}
	int get_def()	{
		return this->def;
	}
	weapontype get_type() {
		return this->type;
	}
	/*void put_on_weapon(player user) {

	}*/
};

class meadowbow : public weapon {
public:
	meadowbow() : weapon(15, 0, weapontype::BOW, "Meadow Bow") {}
};

class antlersword : public weapon {
	antlersword() : weapon(10, 5, weapontype::SWORD, "Antler Sword") {}
};

class wandofsnailking : public weapon {
	wandofsnailking() : weapon(10, 0, weapontype::WAND, "Wand of Snail King") {}
};