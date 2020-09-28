#pragma once
#include <string>
#include "item.h"

class helmet : public item {
private:
	int atk;
	int def;
	int hp;
protected:
	helmet(int atk, int def, int hp, std::string name) :item(name) {
		this->atk = atk;
		this->def = def;
		this->hp = hp;
	}
public:
	helmet() : item("Empty Slot") {
		this->atk = 0;
		this->def = 0;
		this->hp = 0;
	}
public:
	int get_atk() {
		return this->atk;
	}
	int get_def() {
		return this->def;
	}
	int get_hp() {
		return this->hp;
	}
};

class armor : public item {
private:
	int atk;
	int def;
	int hp;
protected:
	armor(int atk, int def, int hp, std::string name) : item(name) {
		this->atk = atk;
		this->def = def;
		this->hp = hp;
	}
public:
	armor() : item("Empty Slot") {
		this->atk = 0;
		this->def = 0;
		this->hp = 0;
	}
public:
	int get_atk() {
		return this->atk;
	}
	int get_def() {
		return this->def;
	}
	int get_hp() {
		return this->hp;
	}
};

class boots : public item {
private:
	int atk;
	int def;
	int hp;
protected:
	boots(int atk, int def, int hp, std::string name) :item(name) {
		this->atk = atk;
		this->def = def;
		this->hp = hp;
	}
public:
	boots() : item("Empty Slot") {
		this->atk = 0;
		this->def = 0;
		this->hp = 0;
	}
public:
	int get_atk() {
		return this->atk;
	}
	int get_def() {
		return this->def;
	}
	int get_hp() {
		return this->hp;
	}
};
////////////////////////////////////////////
class novicecap : public helmet {
public:
	novicecap() : helmet(0, 10, 20, "Novice Cap") {}
};

class insectplate : public armor {
public:
	insectplate() : armor(0, 10, 20, "Insect Plate") {}
};

class antlerboots : public boots {
public:
	antlerboots() : boots(0, 10, 20, "Antler Boots") {}
};