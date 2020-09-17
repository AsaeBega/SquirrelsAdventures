/*in-game mobs*/
#include "Loot.h"
enum class statuseffect {
	NONE,
	POISON,
	SLOWNESS
};

class mob {
private:
	std::string name;
	unsigned int atk;
	unsigned int def;
	unsigned int health;
	statuseffect effect;
protected:
	mob(std::string name, unsigned int atk, unsigned int def, unsigned int health, statuseffect effect) {
		this->name = name;
		this->atk = atk;
		this->def = def;
		this->effect = effect;
		this->health = health;
	}
public:
	unsigned int get_atk() {
		return this->atk;
	}
	unsigned int get_def() {
		return this->def;
	}
	statusffect get_effect() {
		return this->effect;
	}
	//check get functions
};

class ant : public mob {
private:
	loot DropOne;
	loot DropTow;
public:
	ant() : mob("Ant", 20, 10, 100, statuseffect::POISON) {
		this->DropOne = loot("Ant Mandible");
		this->DropTow = loot("Ant Claw");
	}
	//access to drop needed
};