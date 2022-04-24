#include <iostream>
using namespace std;

int main(void) {
	[]() {
		cout << "Hello from lambda function!\n";
	} ();

	cout << "Print value of lambda directly: " << [](int a, int b) {
		return a + b;
	} (5, 6) << endl;

	// With capture list
	// capture by value
	int a = 5;
	int b = 6;
	// a and b are read-only
	auto func = [a, b]() {
		cout << a + b << endl;
		// b = a + b;
	};
	func();
	cout << b << endl;

	// capture by ref
	auto func2 = [a, &b]() {
		// this is now allowed
		b = a + b;
		cout << a + b << endl;
	};
	func2();
	// and it also changes the original b
	cout << a << " and " << b << endl;

	return 0;
}
