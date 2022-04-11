#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <string_view>
#include <iostream>
using namespace std;
#include "person.h"

// Inheritance from Person
class Player : public Person {
	friend ostream &operator<<(ostream &out, const Player &player);

	public:
		Player() = default;
		Player(string_view game_param, string first_name_param, string last_name_param);
		// ~Player(); not needed since no ptr yet

	private:
		string m_game{"None"};
};

#endif // PLAYER_H

