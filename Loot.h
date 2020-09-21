#include <string>


class loot : public item {
public:
	loot(std::string name) :item("---") {}
	loot(std::string name) :item(name) {}
};
