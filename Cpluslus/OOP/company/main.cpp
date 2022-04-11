#include <iostream>
using namespace std;
#include "employee.h"

class Developer:public Employee {
	private:
		string FavProgLang;
	public:
		Developer(string name, string company, int age, string FavProgLang)
			:Employee(name, company, age)
		{
			this->FavProgLang = FavProgLang;
		};
		// Polymorphism
		void Work() {
			cout << name << " is writng code in " << FavProgLang << endl;
		}
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
	Employee emp1("A", "Comany A", 1);
	emp1.Work();

	Developer dev1 = Developer("Hieu", "none", 24, "C++");
	Employee *p_emp = &dev1;
	p_emp->Work();

	return 0;
}
