#include <iostream>
using namespace std;

int main(void) {
	const char *msg[] = "Hello World!";
	cout << *msg << endl;
	cout << *msg[0] << endl;
}
