#include <iostream>
using std::string;

class IEmployee {
	virtual void AskForPromotion(){};
};

class Employee:IEmployee {
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
		void AskForPromotion() {
			if (age > 30) {
				std::cout << name << " got promoted!" << std::endl;
			} else {
				std::cout << "Sorry no promotion for you.\n";
			}
		}
};

class Developer:public Employee {
	private:
		string FavProgLang;
	public:
		Developer(string name, string company, int age, string FavProgLang)
			:Employee(name, company, age)
		{
			this->FavProgLang = FavProgLang;
		};
};

int main(void) {
/*
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

	employee1.AskForPromotion();
	employee2.AskForPromotion();
	employee3.AskForPromotion();
*/
	Developer dev1 = Developer("Hieu", "none", 24, "C++");
	dev1.introduce();

	return 0;
}
