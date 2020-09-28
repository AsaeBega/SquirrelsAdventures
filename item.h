#pragma once
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