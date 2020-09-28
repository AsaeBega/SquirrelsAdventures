#pragma once
#include <string>
#include "item.h"


class loot : public item {
public:
	loot() :item("---") {}
	loot(std::string name) :item(name) {}
};
