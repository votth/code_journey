#include <iostream>
using namespace std;
#include "player.h"

int main(void) {

	Player p1("Basketball");
	cout << "Player: " << p1 << endl;

	p1.set_first_name("John");
	p1.set_last_name("Snow");
	cout << p1 << endl;

	return 0;
}
