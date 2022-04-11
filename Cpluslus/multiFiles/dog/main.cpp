#include <iostream>
using namespace std;
#include "dog.h"

void some_func(Dog dog);

int main(void) {
	Dog my_dog("Luffy", "Golden Retriver", 5);
	my_dog.print_info();
	/* cout << "Delete my_dog twice\n use valgrin . to check";
	some_func(my_dog); */

	my_dog.set_name("Pumba");
	my_dog.print_info();

	my_dog.set_name("Bubba")->set_breed("German Shephard")->set_age(15);
	my_dog.print_info();


	return 0;
}

void some_func(Dog dog) {}
