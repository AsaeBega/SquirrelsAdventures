/*in-game mobs*/
#include "Loot.h"
#include<vector>
enum class statuseffect {
	NONE,
	POISON,
	SLOWNESS
};

class mob {
private:
	std::string name;
	 int atk;
	 int def;
	 int health;
	statuseffect effect;
	std::vector<loot> lootvector;
protected:
	mob(std::string name,  int atk,  int def,  int health, statuseffect effect, std::vector<loot> lootvector) {
		this->name = name;
		this->atk = atk;
		this->def = def;
		this->effect = effect;
		this->health = health;
		this->lootvector = lootvector;
	}
public:
	virtual  int get_atk() {
		return this->atk;
	}
	virtual  int get_def() {
		return this->def;
	}
	virtual statuseffect get_effect() {
		return this->effect;
	}
	virtual std::vector<loot> get_vector() {
		return this->lootvector;
	}
	virtual  int get_health() {
		return this->health();
	}
	virtual void set_health(int health) {
		this->health = health;
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
			return this->get_vector().front();
		case 2:
			return this->get_vector().back();
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
			return this->get_vector().at(1);
		case 2:
			return this->get_vector().at(2);
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
			return this->get_vector().at(1);
		case 2:
			return this->get_vector().at(2);
		}
	}
};