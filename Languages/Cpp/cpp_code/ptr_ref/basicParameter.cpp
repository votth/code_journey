#include <iostream>

int sum(int a, int b);
void printPointer(int *ptr_a, int *ptr_b);

int main() {
  int numberOne = 1;
  int numberTwo = 2;

  std::cout << &numberOne << " " << &numberTwo << std::endl;
  std::cout << numberOne << " " << numberTwo << std::endl;

  std::cout << std::endl;

  printPointer(&numberOne, &numberTwo);
  std::cout << numberOne << " " << numberTwo << std::endl;

  return 0;
}

int sum(int a, int b) {
  return a + b;
}

void printPointer(int *ptr_a, int *ptr_b) {
  std::cout << ptr_a << " " << ptr_b << std::endl;

  *ptr_a = 3;
  *ptr_b = 4;

  return;
}
