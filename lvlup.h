#include "player.h"
#include <math.h>

void lvl_up(player player) {
	if (player.get_exp() == std::pow(2, player.get_lvl()) * 10) {
		player.set_exp(0);
		player.set_lvl(player.get_lvl() + 1);
	}
}