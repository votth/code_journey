#include <iostream>
using std::string;

class Employee {
	private:
		string name{};
		string company{};
		int age{};
	public:
		// Constructors
		Employee() = default;
		Employee(string name, string company, int age) {
			this->name = name;
			this->company = company;
			this->age = age;
		}
		// Destructor
		// ~Employee();
		// Setters
		void setName(string name) {
			this->name = name;
		}
		void setCompany(string company) {
			this->company = company;
		}
		void setAge(int age) {
			if (age >= 18) {
				this->age = age;
			} else {
				std::cout << "Please put a valid number\n";
			}
		}
		// Getters
		string getName() {
			return this->name;
		}
		string getCompany() {
			return this->company;
		}
		int getAge() {
			return this->age;
		}
		// Methods
		void introduce() {
			std::cout << "Name: " << name << std::endl;
			std::cout << "Company: " << company << std::endl;
			std::cout << "Age: " << age << std::endl;
		}
};

int main(void) {
	// Using default cons
	Employee employee1;
	employee1.introduce();
	// Using custom cons
	Employee employee2("Another", "Maybe", 1);
	employee2.introduce();
	// Using setters and getters
	Employee employee3;
	employee3.setName("Person 3");
	employee3.setCompany("Company 3");
	employee3.setAge(3);
	std::cout << "Info of the third person:\n- Name: " << employee3.getName() << std::endl;
	std::cout << "- Company: " << employee3.getCompany() << std::endl;
	std::cout << "- Age: " << employee3.getAge() << std::endl;

	return 0;
}
