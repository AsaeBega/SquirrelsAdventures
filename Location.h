#include "Mob.h"
#include <string>
#include <vector>

class location {
private:
	std::string name;
	size_t req_lvl;
	std::vector<mob> moblist;

protected:
	location(std::string name, size_t req_lvl, std::vector<mob> moblist) {
		this->name = name;
		this->req_lvl = req_lvl;
		this->moblist = moblist;
	}
public:
	size_t get_req_lvl(){
		return this->req_lvl;
	}
	std::string get_name() {
		return this->name;
	}
	std::vector<mob> get_moblist() {
		return this->moblist;
	}
	virtual mob get_mob_for_encounter(size_t spec) = 0;
};

class meadow : public location {
public:
	meadow() : location("Meadow", 5, {ant(), beetle(), snail()}) {}
	mob get_mob_for_encounter(size_t spec) override {
		switch (spec)
			case 1:
				return this->get_moblist().at(1);
			case 2:
				return this->get_moblist().at(2);
			case 3:
				return this->get_moblist().at(3);
	}
	
};