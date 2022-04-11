#include <iostream>
using namespace std;
#include <string>

template <typename T> T larger(T a, T b);

int main(void) {
	int a = 5, b = 6;
	double c = 12.56f, d = 5.768f;
	string e = "Hello", f = "world!";

	cout << larger(a, b) << endl;
	cout << larger(c, d) << endl;
	cout << larger(e, f) << endl;

	return 0;
}

template <typename T> T larger(T a, T b) {
	return (a > b) ? a : b;
}
