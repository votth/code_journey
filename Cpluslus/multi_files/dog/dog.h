#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include <string_view>

class Dog {
	private:
		std::string name{};
		std::string breed{};
		int *p_age{nullptr};
	public:
		Dog();
		Dog(std::string_view name_param, std::string_view breed_param, int age_param);
		// Destructor
		~Dog();
		// Getters
		std::string get_name(void);
		// Setters using ptr
		Dog *set_name(std::string_view name);
		Dog *set_breed(std::string_view breed);
		Dog *set_age(int  age);

		// Others
		void print_info();
};

#endif
