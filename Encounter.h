#pragma once
#include "Location.h"
#include "player.h"
#include "Mob.h"
#include<vector>

class encounter {
private:
	std::vector<mob> encounter_mobs;
public:
	encounter(location location) {
		int num_mobs = std::rand() % 3 + 1;
		mob foe;
		for (auto i = 0; i < num_mobs; i++) {
			foe = location.get_mob_for_encounter(int(std::rand() % location.get_moblist().size()));
			this->encounter_mobs.push_back(foe);
		}
	}
	void player_atk(player player, mob foe) {
		if (player.get_weapon().get_type() != weapontype::WAND) {
			foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
		}
		else {
			foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
			foe.set_health(foe.get_health() - int(player.get_atk() * 0.2));
		}
	}
	void mob_atk(player player, mob foe) {
		if (foe.get_effect() == statuseffect::NONE) {
			player.set_health(player.get_health() - int(foe.get_atk() * (1 - player.get_def() / 200)));
		}
		else if (foe.get_effect() == statuseffect::POISON) {
			player.set_health(player.get_health() - int(foe.get_atk() * (1 - player.get_def() / 200)));
			player.set_health(player.get_health() - 5);
		}
	}
	void first_turn(player player, mob foe) {
		if (player.get_weapon().get_type() == weapontype::BOW) {
			foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
			foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
			foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
		}
		else {
			this->player_atk();
		}
	}
	void FaceEncounter(player player, location location) {
		bool Fturn = true;
		int starthealth = player.get_health();
		mob foe = this->encounter_mobs.pop_back();
		while (player.get_health() > 0 || !this->encounter_mobs.empty()) {
			if (Fturn) {
				this->first_turn(player, foe);
				Fturn = false;
			}
			if (this->encounter_mobs.empty()) {
				break;
			}
			if (foe.get_health() <= 0) {
				foe = this->encounter_mobs.pop_back();
			}
			if (player.get_health() <= 0) {
				player.set_health(starthealth);
				break;
			}
			this->mob_atk();
			this->player_atk();
		}
		if (this->encounter_mobs.empty() && player.get_health() > 0) {
			player.set_exp(player.get_exp() + /*ACHTUNG*/);
		}
		/*add loot, add exp*/
	}
};