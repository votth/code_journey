#include <iostream>
using namespace std;

int main(void) {
	int number1 = 1;
	int number2 = 2;
	int number3 = 3;

	int &ref_number = number1;
	cout << ref_number << endl << endl;

	ref_number = number2;
	cout << ref_number << endl;
	cout << number1 << endl << endl;

	/* complier error
	 * so address of ref can't be changed
	 * ref is like a const ptr
	&ref_number = &number3;
	cout << ref_number << endl;
	cout << number1 << endl;
	cout << number2 << endl;
	*/

	const int &ref_const = number1;
	cout << ref_const << endl;
	number1 = 100;
	cout << ref_const << endl;

	return 0;
}
