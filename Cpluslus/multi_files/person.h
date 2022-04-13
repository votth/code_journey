// include guard
#ifdef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
	public:
		// constructor
		Person(const string &name_param, int age_param);
		
		void print_info() const {
			cout << "Name: " << full_name << ", age: " << age << endl;
		}

	private:
		string fullname;
		int age;

	public:
		static int person_count;
};

#endif // PERSON_H
