#include "employee.h"

// Cons and Destructor
Employee::Employee(string name, string company, int age) {
	this->name = name;
	this->company = company;
	this->age = age;
}
// Employee::~Employee() {}

// Setters
void Employee::setName(string name) {
	this->name = name;
}
void Employee::setCompany(string company) {
	this->company = company;
}
void Employee::setAge(int age) {
	this->age = age;
}

// Getters
string Employee::getName() {
	return this->name;
}
string Employee::getCompany() {
	return this->company;
}
int Employee::getAge() {
	return this->age;
}

// Methods
void Employee::introduce() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Company: " << company << std::endl;
	std::cout << "Age: " << age << std::endl;
}
void Employee::AskForPromotion() {
	if (age > 30) {
		std::cout << name << " got promoted!" << std::endl;
	} else {
		std::cout << "Sorry no promotion for you.\n";
	}
}
void Employee::Work() {
	std::cout << name << " is working on their works.\n";
}
