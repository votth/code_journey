#include "person.h"

double add(double a, double b) {
	return a + b;
}

int Person::person_count = 8;

Person::Person(const string &name_param, int age_param)
	: full_name{name_param}, age{age_param} {
		++person_count;
	}
