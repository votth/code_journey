#include <iostream>

static const int size = 5;

void fill_array(int *myArray);
void print_array(const int (&myArray)[]);

int main(void) {
	// int size = *(&arr + 1) - arr;
	//
	// &arr : pointer to an array of some n-type elements
	// (&arr + 1) : address of n-type memory blocks ahead
	// *(&arr + 1): same address as the above but type of poitner is int *
	// *(&arr + 1) - arr : since *(&arr + 1) points to n-type address ahead, the difference between the two is n
	int myArray[size] {};

	std:: cout << &myArray << std::endl;
	std:: cout << (&myArray + 1) << std::endl;
	std:: cout << *(&myArray + 1) << std::endl;
	std:: cout << *(&myArray + 1) - myArray << std::endl;

	/* std::cout << "Size of my array: " << sizeof(myArray) << std::endl; */
	/* std::cout << "-----\n"; */
	/* fill_array(myArray); */
	/* print_array(myArray); */
	/* std::cout << "-----\n"; */

	return 0;
}

void fill_array(int *myArray) {
	int i = 0;
	while (i < size) {
		myArray[i] = i + 1;
		++i;
	}
	return;
}

void print_array(const int (&myArray)[]) {
	/* int size = sizeof(myArray) / sizeof(*myArray); */
	std::cout <<"[ ";
	for (int i = 0; i < size; ++i) {
		std::cout << myArray[i] << " ";
	}
	std::cout << "]\n";
	return;
}

