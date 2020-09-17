/*Here u can find all in-game loot*/
#include <string>

class item {
private:
	std::string name;
protected:
	item(std::string name) {
		this->name = name;
	}
public:
	std::string get_name() {
		return this->name;
	}
};

class loot : public item {
public:
	loot(std::string name) :item("---") {}
	loot(std::string name) :item(name) {}
};
