#include <iostream>
using namespace std;

int main(void) {
	int *int_ptr {};
	int *dyn_ptr = new int {23};

	int int_number = 68;
	int_ptr = &int_number;

	cout << "int *dyn_ptr = new int {23};\n";
	cout << *dyn_ptr << endl << endl;

	// *pointer is called "dereferencing"
	cout << "int_ptr pointer's pointed address and value\n";
	cout << int_ptr << endl << *int_ptr << endl;
	cout << "\nint_ptr pointer's address in the memory\n";
	cout << &int_ptr << endl;

	cout << "\nint_number's address and value\n";
	cout << &int_number << endl << int_number << endl;
}
