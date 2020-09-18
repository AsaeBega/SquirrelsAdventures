/*in-game mobs*/
#include "Loot.h"
#include<list>
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
	std::list<loot> lootlist;
protected:
	mob(std::string name, unsigned int atk, unsigned int def, unsigned int health, statuseffect effect, std::list<loot> lootlist) {
		this->name = name;
		this->atk = atk;
		this->def = def;
		this->effect = effect;
		this->health = health;
		this->lootlist = lootlist;
	}
public:
	virtual unsigned int get_atk() {
		return this->atk;
	}
	virtual unsigned int get_def() {
		return this->def;
	}
	virtual statuseffect get_effect() {
		return this->effect;
	}
	virtual std::list<loot> get_list() {
		return this->lootlist;
	}
	virtual loot get_loot(size_t spec) = 0;
	//check get functions
};


// MEADOW LOCKATION MOBS
class ant : public mob {
public:
	ant() : mob("Ant", 20, 10, 100, statuseffect::POISON, {loot("Ant Mandible"), loot("Ant Claw")}) {
	}
	loot get_loot(size_t spec) override {
		switch (spec) {
		case 1:
			return this->get_list().front();
		case 2:
			return this->get_list().back();
		}
	}
};

class beetle : public mob {
public:
	beetle() : mob("Beetle", 20, 10, 100, statuseffect::NONE, { loot("Beetle Wing"), loot("Beetle Carapace") }) {
	}
	loot get_loot(size_t spec) override {
		switch (spec) {
		case 1:
			return this->get_list().front();
		case 2:
			return this->get_list().back();
		}
	}
};

class snail : public mob {
public:
	snail() : snail("Snail", 20, 10, 100, statuseffect::SLOWNESS, { loot("Snail Tentacle"), loot("Snail Shell") }) {
	}
	loot get_loot(size_t spec) override {
		switch (spec) {
		case 1:
			return this->get_list().front();
		case 2:
			return this->get_list().back();
		}
	}
};