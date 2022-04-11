#include <iostream>
using namespace std;

// custom concept
template <typename T>
concept TinyType = requires (T t) {
	sizeof(T) <= 4;
	// requires sizeof(T) <= 4; | this is needed to return error
};
// function using concept requirement
// the TinyType will constrait both parameters and the actual function returned value
// here function's will have int type, cause of the + operator having overflow-guard
TinyType auto add(TinyType auto a, TinyType auto b) {
	return a + b;
}

int main(void) {
	double x{67};
	double y{456};

	add(x, y); // this will not throw complier-error
}
