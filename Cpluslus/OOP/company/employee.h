#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class IEmployee {
	virtual void AskForPromotion(){};
};

class Employee:IEmployee {
	protected:
		string name{};
		string company{};
		int age{};
	public:
		// Constructors
		Employee();
		Employee(string name, string company, int age);
		// Destructors
		// ~Employee();
		// Setters
		void setName(string name);
		void setCompany(string company);
		void setAge(int age);
		// Getters
		string getName();
		string getCompany();
		int getAge();
		// Methods
		void introduce();
		void AskForPromotion();
		virtual void Work();
};

/* class Developer:public Employee { */
/* 	private: */
/* 		string FavProgLang; */
/* 	public: */
/* 		Developer(string name, string company, int age, string FavProgLang); */
/* }; */

#endif // EMPLOYEE_H
