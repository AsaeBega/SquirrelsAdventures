#include<string>

class UserCommand {
private:
	std::string prefix;
	std::string command;
	std::string parameter;
public:
	UserCommand() {
		this->prefix.clear();
		this->parameter.clear();
		this->command.clear();

	}
	void make_command(std::string msgContent) {
		size_t i = 0;
		while (msgContent[i] != ' ') {
			this->prefix += msgContent[i];
			i++;
		}
		i++;
		while (msgContent[i] != ' ') {
			this->command += msgContent[i];
			i++;
		}
		i++;
		while (i < msgContent.size()) {
			this->parameter += msgContent[i];
			i++;
		}
	}
	
	std::string get_command() {
		return this->command;
	}
	std::string get_parameter() {
		return this->parameter;
	}

	void eraseCommand() {
		this->prefix.clear();
		this->parameter.clear();
		this->command.clear();
	}
};