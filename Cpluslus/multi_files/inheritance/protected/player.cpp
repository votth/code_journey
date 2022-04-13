#include "person.h"
#include "player.h"

Player::Player(string_view game_param, string first_name_param, string last_name_param) {
	// This is now possible thanks to 'protected' keyword
	/* first_name = "Change from player.h"; */
	/* last_name = "this too"; */
	m_game = game_param;
	first_name = first_name_param;
	last_name = last_name_param;
}

ostream &operator<<(ostream &out, const Player &player) {
	out << "Player: [game: " << player.m_game <<
		", name: " << player.get_first_name() <<
		" " << player.get_last_name() << "]";
	return out;
}
