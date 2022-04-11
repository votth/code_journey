#include <iostream>
#include "dog.h"

// Constructors
Dog::Dog() {
	name = "None";
	breed = "None";
	p_age = new int;
	*p_age = 0;
}
Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param) {
	name = name_param;
	breed = breed_param;
	p_age = new int;
	*p_age = age_param;

	std::cout << "Dog constructor called for " << name << "at " << this << std::endl;
}

// Destructor
Dog::~Dog() {
	delete p_age;
	std::cout << "Dog destructor called for: " << name << "at " << this << std::endl;
}

// Getters
std::string Dog::get_name(void) {
	return name;
}

// Setters
Dog *Dog::set_name(std::string_view name) {
	this->name = name;
	return this;
}
Dog *Dog::set_breed(std::string_view breed) {
	this->breed = breed;
	return this;
}
Dog *Dog::set_age(int age) {
	*(this->p_age) = age;
	return this;
}

// Others
void Dog::print_info() {
	std::cout << "Dog (" << this << ") : [name: " << name << ", breed: " << breed << ", age: " << *p_age << std::endl;
}
