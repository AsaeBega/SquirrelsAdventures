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
		for (auto i = 0; i < num_mobs; i++) {
			this->encounter_mobs.insert(location.get_mob_for_encounter(std::rand() % location.get_moblist().size()));
		}
	}
	void FaceEncounter(player player, location location) {
		unsigned int starthealth = player.get_health();
		mob foe = this->encounter_mobs.pop_back();
		while (player.get_health() > 0 || !this->encounter_mobs.empty()) {
			if (foe.get_effect() == statuseffect::NONE) {
				do
				{
					if (player.get_health() > 0)
						foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
					if (foe.get_health() > 0)
						player.set_health(player.get_health() - int(foe.get_atk() * (1 - player.get_def() / 200)));
				} while (foe.get_health() > 0 && player.get_health()>0);
			}
			else if (foe.get_effect() == statuseffect::POISON) {
				do
				{
					if (player.get_health() > 0)
						foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
					if (foe.get_health() > 0) {
						player.set_health(player.get_health() - int(foe.get_atk() * (1 - player.get_def() / 200)));
						player.set_health(player.get_health() - 5);
					}
				} while (foe.get_health() > 0 && player.get_health() > 0);
			}
			else if (foe.get_effect() == statuseffect::SLOWNESS){
				do
				{
					if (player.get_health() > 0)
						foe.set_health(foe.get_health() - int(player.get_atk() * (1 - foe.get_def() / 200)));
					for (auto i = 0; i < 2; i++) {
						if (foe.get_health() > 0)
							player.set_health(player.get_health() - int(foe.get_atk() * (1 - player.get_def() / 200)));
					}
				} while (foe.get_health() > 0 && player.get_health() > 0);
			}
		}
	}
};