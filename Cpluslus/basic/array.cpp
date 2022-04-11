#include <iostream>
using namespace std;

int main(void) {
	/*
	int arrSize = 8;
	int arr[arrSize] = {1, 2, 3};
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << endl;
	}
	*/

	cout << "In case of declare without pre-determined arr's size\n\n";
	cout << "int arr[] = {1, 2, 3};" << endl;
	cout << "for (auto value : arr) {" << endl;
	cout << "	cout << value << endl;" << endl;
	cout << "}" << endl << endl;

	int arr[] = {1, 2, 3};

	for (auto value : arr) {
		cout << value << endl;
	}

	return 0;
}
