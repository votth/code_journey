#include <iostream>
using namespace std;

int main(void) {
	const char *msg[] = {"Hello World!", "World!"};
	cout << *msg << endl;
	cout << *msg[0] << endl;
	// Command terminated error ?
	// no more when added in "World!"
	cout << *msg[1] << endl;
}
