#include <iostream>
using namespace std;

int sum_int(int a, int b);

int main(void) {
	int a, b;

	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "Sum: " << sum_int(a, b) << endl;

	cout << "New a: ";
	cin >> a;
	cout << "New b: ";
	cin >> b;
	cout << "Sum: " << sum_int(a, b) << endl;

	return 0;
}

int sum_int(int a, int b)
{
	return a + b;
}
