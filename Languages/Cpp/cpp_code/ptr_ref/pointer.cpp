#include <iostream>

int main(void) {
  int *int_ptr{};
  /* int *dyn_ptr = new int{23}; */

  int int_number = 68;
  int_ptr = &int_number;

  /* cout << "int *dyn_ptr = new int {23};\n"; */
  /* cout << *dyn_ptr << std::endl << std::endl; */

  // *pointer is called "dereferencing"
  /* cout << "\nint_ptr pointer's address in the memory\n"; */
  /* cout << &int_ptr << std::endl; */

  std::cout << "int_ptr pointer's pointed address and value\n";
  std::cout << int_ptr << std::endl << *int_ptr << std::endl;

  std::cout << "\nint_number's address and value\n";
  std::cout << &int_number << std::endl << int_number << std::endl;

  return 0;
}
