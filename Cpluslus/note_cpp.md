# Skeleton
``` cpp
#include <iostream>
using namespace std;
// This is a comment
int main(void) {

	/*	Block comment
		Send signal indicating end of program
		0 means no error
		!! no nested comment
	*/
	return 0;
}
```


# Errors and Warnings
## Compile Time Errors
- Errors that happen in the compile step.
## Runtime Errors
- After compilation, knowns as logical errors.
- The program won't finish running and crashes.
## Warnings
- The compiler won't freak out or crash won't happen in Runtime since it's not serious enough.
- Example: divide by 0


# Statements and Functions

## Statements
- Statements is a basic unit of computation in C++.
- A C++ program is a collect of statements organized in a certain order, executed from top to bottom to achieve a certain task.
- Statements in C++ end with semicolon (;).

## Functions
- Give it inputs and receive outputs.
- Must be defined before used. Reusability
- Example: int sum_int(int a, int b) {}
``` cpp
#include <iostream>
using namespace std;

int sum_int(int a, int b);

int main(void) {
	int a, b;

	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "Sum: %i\n\n" << sum_int(a, b);

	cout << "New a: ";
	cin >> a;
	cout << "New b: ";
	cin >> b;
	cout << "Sum: %i\n\n" << sum_int(a, b);

	return 0;
}

int sum_int(int a, int b)
{
	return a + b;
}
```

# Input and Output
``` cpp
std::cout // meaning console out
std::cin // counsole in
std::cerr // prints error to the terminal/console
std::clog // prints log message to the terminal
std::getline(std::cin, {variable}); // in case user input 'space'
```

## \#include \<string\>
``` cpp
#include <string>

std::string name;
int age;

// std::cin >> name;
// std::cin >> age;

std::cin >> name >> age;
```

# Execution and Memory models

## Memory model:
### Definition
- an abstraction or description detailing how threads interact with computer memory and shared data
- multi-threaded execution requries the computer language to specify a memory model
	- by definition: at any given time, active threads may see different values for the shared data. This is normal, since requires all threads to always be perfectly insync is costly and hindrences performance. Therefore, when writing a multi-threaded program, the developers have to decide when the inconsistency is acceptable and when it is not.
	- without a memory model, programmers, third party threading libraries, complier, and the hardware are at odds with the complier optimization and hardware optimizations
- Memory model ensures that the devs can write code with shared data to be insynced when it's required.
### Components of a Memory Model
- the program that the developer wrote
- the code that the complier generated, which is executed by the hardware
- the memory operation that the CPU performs while it's executing the code
### Reordering
- Eventhough statements are left in a certain order, the complier and computer might decide to which reordering would yield a better result in performance, efficiency.
- The memory model places restrictions on these reorderings, so the devs can reason through the likely behaviours of a multi-threaded program.

- Model must define which reorderings are permitted.
- Provides a minimal guarantee about when the memory is accesed.
- Defines when mulitple threads may access the same memory, or specifies when assignments by one thread can be seen in a concurrently executing thread.

- !! *data race*: when 2 conflicting operations can be executed simultaneously.
### C++ multi-thread model
- C++11 memory model is part of the core language.
- std::thread is part of the standard library.

## C++11
- It is not possible to effevtively utilize additional processor cores without writing a mulit-threaded program.
- C++11 added a memory model, threading, atomics and mutexes.


# C++ core language vs Standard library vs STL
- C++ standard consists of 2 parts: core language and the standard library. The standard library changes on every major implementation of C++ (C++11 C++14, every 3 years)
- The core language:
	- *aggregate types* (vectors, lists, maps, sets, queues, stacks, arrays, tuples)
	- algorithm (find, for_each, binary_search, random_shuffle, etc.)
	- input/output facilities (iostream, for reading from and writing to the console and files)
	- filesystem library localisation support
	- [smart pointers](https://en.wikipedia.org/wiki/Smart_pointers) for automatic memory management
	- [regular expression](https://en.wikipedia.org/wiki/Regular_expression) support
	- [multi-threading](https://en.wikipedia.org/wiki/Multithreading_(software)) library
	- atomics support (allowing a variable to be read or written to by at most one thread at a time without any external synchronisation)
	- time utilites (measurement, getting current time, etc.)
	- a system for converting error reporting that doesn't use C++ [exceptions](https://en.wikipedia.org/wiki/Exception_handling) into C++ exceptions
	- [random number generator](https://en.wikipedia.org/wiki/Random_number_generator)
	- a slightly modified version of the C standard library (to make it comply with the C++ type system)
- The standard library (libc):
	- [macros](https://en.wikipedia.org/wiki/Macro_(computer_science))
	- type definitions
	- functions for tasks such as string handling, mathematical computations, input/output processing, [memory management](https://en.wikipedia.org/wiki/Memory_management)
	- other [OS](https://en.wikipedia.org/wiki/Operating_system) services
- Standard Template Library (STL):
	- [containers](https://en.wikipedia.org/wiki/Container_(data_structure)) as the collections of objects (such as vertors and lists)
	- [iterators](https://en.wikipedia.org/wiki/Iterator) that provide array-like acces to containers
	- algorithms that perform operations such as searching and sorting
- (mutli)maps ([associative arrays](https://en.wikipedia.org/wiki/Associative_array)) and (multi)sets are provided, all of which export compatible interfaces. Therefore, using templates it is possible to write generic algorithms that work with any containers or on any sequence defined by iterators.
``` cpp
// features of the library are accessed by using
#include <directive>
// to include a standard header
```


# Number Systems
- base 2: 0 and 1 - 0010 0111
- base 10: 0 to 9 - 1998
- base 16 (hexadecimal): 0 to 9 and A to F - 0x7FB5
- Octal system (base 8): 0 to 7
- All data is essentially 0 and 1 in memory.
``` cpp
int decimal = 15;
int octal = 017;
int hexa = 0x0F;
int binary = 0b00001111; // !! from C++14
```


# Variables and Data Types
``` cpp
// braces initialization
typename variable_name {initialize_value};
// expression initialization
int sum {a + b};
// functional initialization
// might not be as useful as braces, example
int some_int {2.9};
int some_other_int (2.9);
// the braces will return error or warning
// while the other treat 2.9 as 2 instead

// assignment notation
int varible = 5;
```
- sizeof()
- Naming rules
	- starting with letters
	- words are separated by underscore (\_)
	- case-sensitive

## int (Integers)
- 4 bytes
- Some common data types: int, double, float, char, bool, void, auto...
### short, long
- For using with integer type only
	- int 4 bytes
	- short int 2 bytes
	- long int 4 or 8 bytes
	- long long int 8 byes

## unsigned (Positive) and signed (Negative)

## float, double, long double (Fractional number)
- Bytes and precision
	- float 4 7
	- double 8 15
	- long double 12 >double
- Differ from int: divide by 0
	- floating_point / 0 : infinity +-
	- 0.0 / 0.0 : NaN - not a number
``` cpp
// Fixed notation
float number1 = 1.456845686f; // f to specify it as float
double number2 = 1.456878948;// default is double
long double number3 = 1.45678498L; // to specify as long
// Scientific notation
float number4 = 1.4565e5;
// Infinity and NaN
// float / 0
// 0.0 / 0.0
```

``` cpp
#include <iostream>
#include <iomanip>

std::cout << std::setprecision(20); // control the precision of cout
```

## bool (True or False)
``` cpp
std::cout << std::boolalpha; // forces the output format to true/false
```
- Using bool can be considered as wasteful, especially when memory is limited (eg. embedded system). Since bool takes 1 byte of memory but uses/stores true or false

## char (Characters) or string (Text)
### char
- ASCII table:
	- 0-127 value
	- Common values to know:
		- 32 space
		- 49-57 0-9
		- 65-90 A-Z
		- 97-122 a-z
	- One of the first encodings to represent text in computers. But falls short when it comes to representing language other than English.
	- Unicode is a better encoding.
``` cpp
char value = 65; // ASCII code for 'A'
std::cout << "value: " << value << endl;
std::cout << "value (int): " << static_cast<int>(value) << endl;
```

## auto
- Let the complies deduce the type
``` cpp
auto var1 {12};
auto var2 {13.0};
auto var3 {14.0f};
auto var4 {15.0l};
auto var5 {'e'};
// int modifier suffixes
auto var6 { 123u}; // unsigned
auto var7 { 123ul}; // unsigned long
auto var8 { 123ll}; // long long
```

## Assignments
``` cpp
double var {44.55}; // Declare and Initialize
var2 = 99.88; // Assign new value
```
- !! Be very careful when assigning value to auto declared type since there WON'T be a warnings error.

---------------------------------
**Operations on Data**
- Formatting
- Built-in utilities

# Precedence and Associativity
- which operation to do first and in which direction or order
- [Operator precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)
- You should use parenthesises () to make your code clear and readable.


# Mathematical operators
- !! integers division
	- add, subtract, divide, multiply
	- increment, decrement
	- modulus

## Increment and Decrement
- Pre- and postfix inc/decrement are only for + and - operation.
- It's possible to increment by 5 but not with ++, ++ is only for +1.
- `value += -= *= /= {number};` is basically value = value +-\*/ {number}.
``` cpp
value = 5;
// Postfix increment
std::cout << "With value++" << endl;
std::cout << "The value is incrementing: " << value++ << endl; // 5
std::cout << "The value is now: " << value << endl; // 6
// Prefix increment
std::cout << "With ++value" << endl;
std::cout << "The value is now: " << ++value << endl; // 7
// so the ++value will be executed before the std::cout cmd
// while with postfix, the std::cout will be executed first
```

## Relational operators
- !! Careful when using with << >> since those have higher precedence compare to the below operators. Use ().
- > < >= <= == !=
- std::boolalpha and std::noboolalpha

## Logical operators
- Using with true or false.
- && and, || or, ! not

## \#include \<limits\>
- numeric_limits\<type\>::min()
- numeric_limits\<type\>::max()
- numeric_limits\<type\>::lowest()

## Math Functions
- \#include \<cmath\>
- floor(), ceil(), log() (default as base *e*), sqrt(), round() etc.


# Weird Integral Types
- Integral types less than 4 bytes in size don't support arithmetic operations.
- Bitwise shift operators: >> and <<
``` cpp
// 2 bytes in size
short int var1 {10};
short int var2 {20};
// 1 bytes in size
char var3 {40};
char var4 {50};
// These become 4 bytes in size
auto result1 = var1 + var2;
auto result2 = var3 + var4;
// use sizeof(variable) to check
```


# Output formatting
- \<ios\> and \<iomanip\>
- [Input/ouput manipulators](https://en.cppreference.com/w/cpp/io/manip)
	- std::endl or \n: end line
	- std::flush: causes immediate sending of data to the device connected to the stream / send whatever in the output buffer (storage before the data go out) to the terminal, without going through std::out for example
	- std::setw(): set width, set the pixel
	- std::right: right alignment
	- std::internal: internal justified, sign is on the left while data on the right
	- std::setfill('{char}'): to replace spaces in setw()
	- std::boolalpha and std::noboolalpha: so true as "true" instead of "1"
	- std::showpos and std::noshowpos: to show the positive sign
	- std::dec, std::hex and std:oct: to control which base should the data be shown in
	- std::showbase and std::noshowbase: to add either 0x or 0 before hex or oct respectively
	- std::uppercase: to show text in manuscule
	- std::scientific, std::fixed and to go back to default `std::cout.unsetf(std::ios::scientific | std::ios::fixed);`
	- std::setprecision: to decide how many number will be shown after the comma (,)
	- std::showpoint: to show numbers after the decimal, and wil force-show trailing 0s

**End of "Operations on Data"**
----------------------------------------
**Flow Control: Conditional Programing**

# Summary
- if/else
- switch
- ternary operator


# if and else clauses
``` cpp
if (condition) {
	// code_block to execute if true
} else {
	// code_block to execute if false
}
/*
if ...
else if (sub_condition) {}
*/
```

# ternary
``` cpp
result = (condition) ? true : false ;
```

# switch
- Testing for serveral conditions. Using with integral types and enums only!
- `break;` to stop checking for another condition when already found.
``` cpp
switch (variable) {
	case value1: {
		// code_block
	}
	break;

	case value2: {
		// code_block
	}
	break;

	case value3: {
		// code_block
	}
	break;

	default: {
		// if all the above conditions failed
	}
	break;
}
```

**End of "Flow Control: Conditional Programming"**
--------------------------------------------------
**Loops**

``` cpp
for (int i = start_point; i < end_point; i++) {
	// code_block
}
while (condition) {
	++condition; // for ending
}
// will run the code_block at least once
do {
	// code_block
} while (condition);
```
- size_t: not a type, just a type alias for some unsigned int representation
- !! Hard coded values are bad, eg. use loop_time variable instead of "10"

**End of "Loops"**
------------------
**Arrays**
- Store elements of the same type.

# Declaring and Using
`type variable_name[size]`
- Indexing starts from 0 to 'size-1'
# Size of an array: std::size(arr)
- size is fixed
# Bound of an array
- !! "Out of bounds" error


# Write data from arrays
``` cpp
int arr[] = {1, 2, 3};
// This will print out every elements of the array
for (int value : arr) {
	cout << value << endl;
}
```


# Array of characters - Strings
- Null termination: \0
	- add it in yourselves within the arr's bound
	- or have arr's bound +1 empty space so the complier knows to add itself the \0
	- using with msg[] will also result in gabage values
	``` cpp
	char msg1[] = {'H', 'e', 'l', 'l', 'o'}; // not a C string
	char msg2[] = {"Hello"}; // is a C string

	cout << "Message 1 printing\n";
	for (char c : msg1) {
		cout << c;
	}
	cout << endl;
	// might print gabages
	cout << msg1 << endl;

	cout << "Message 2 printing\n";
	cout << msg2 << endl;
	```

**End of "Arrays"**
-----------------
**Pointers**

# Declaring and Using pointers
- Only store address of the same type variable
``` cpp
int *p_number {nullptr};
int int_var {42};
// pointer points to variable int_var's address
p_number = &int_var;
```


# Pointer to char
``` cpp
char my_char = 'A';
char *p_char {&my_char};

char my_msg = "Hello world!";
// some compliers will stop here
// since it requies pointer to be "const char" to point to string
// just to be safe and prevent from reassign the string
char *p_msg = "Hello world!";
```


# Program memory map
- Real memory (RAM) VS Virtual memory
- Virtual memory: A trick that fools your program into thinking that it is the only program running on the OS, and all the memory resources belong to it.
	- Each program is abstracted into a program process, and each process has access to the memory ranging from 0~(2^N)-1 where N is 32 or 64 depends on the OS bit systems.
	- The entire program is not loaded into the real memory, but only parts of it (processes) that are to be executed will be loaded. Making effective use of RAM.
- Memory map levels: system > stack > heap > data > text
	- stack: stores local variables, function calls etc.
	- heap: additional memory that can be queried at runtime


# Dynamic memory allocation
- !! writing into junk addresses is bad
``` cpp
int *p_number; // was not initialized
*p_number = 55;
int *p_numberOther {}; //initialized but pointing to nothing - nullptr
```
- Heap:
	- Developers are in control.
	- Lifetime is controlled through 'new' and 'delete' operators.
- Stack:
	- Developers are NOT in control.
	- Lifetime is controlled by the scope mechanism.
``` cpp
int *p_number {nullptr};
p_number = new int;	// dynamically allocate space for a single int on the heap
					// other programs can't use this until releaseed
*p_number = 77;		// writing to the allocated memory space
delete p_number;	// release/return the memory
p_number = nullptr;	// reset the pointer
```
- !! Do not called *delete* twice to the same pointer


# Dangling pointers
- Pointers that don't point to valid memory address:
	- uninitialized pointer
	- deleted pointer
	- multiple pointers point to the same location


# When 'new' fails
- very rare case, but always good to know how to interact when it happens
- Checks:
	- exception mechanism
``` cpp
try {
	int *lots_of_ints {new int[10000000000000]};
} catch (std::exception &ex) {
	std::cout << "Exception message: " << ex.what() << std::endl;
}
```
	- std::nothrow setting
``` cpp
int *lots_of_ints {new(std::nothrow) int[1000000000000]};
if (lots_of_ints == nullptr) {
	std::count << "Not enough heap memory\n";
	return 1;
}
```


# nullptr safety
- Making sure you are working with pointers containing valid addresses.
- It's fine to `delete` a nullptr.
``` cpp
int *p {};
p = new int{7};

if (p) {
	cout << "valid\n";
	cout << p << endl;
} else {
	cout << "Invalid\n";
	return 1;
}

delete p;
nullptr;

return 0;
```


# Memory leaks
- Lost access to allocated memory.
- When there's no pointer pointing to a `new`ed memory.


# Dynamic arrays
``` cpp
size_t size{10};
double *p{new double[size]{}};
delete[] p;
p = nullptr;
```
- Pointer arrays don't work with std::size().
- Nor do they work with "range based for loop"


# References

## Declaring and Using
- Changes will happen to both the original and the ref.
- Address is the same as the original.
- The ref's address can't be changed, acts like const ptr
``` cpp
int int_value1 {46};
int &ref_int1 = int_value1;
cout << "Value of the ref: " << ref_int1 << endl;
cout << "Address of the ref: " << &ref_int1 << endl;
```

## Refereces vs Pointers
- Ref:
	- don't use dereferencing for reading and writing
	- can't be changed to reference something else
	- must be initialized at declaration
- Ptr:
	- must use dereferencing *
	- can point to other memory addresses
	- can be declared un-initialized (contain garbages)

## Refs and const
- Avoid modifying the refs: `const int &ref{original};`

**End of "Pointers and References"**
------------------------------------
**Character manipulation and strings**
- Facilities to handle text data in C++

# Character manipulation
- header: \<cctype\>
- some common functions: returns 0 if false and non-0 otherwise
	- isalnum
	- isalpha
	- isdigit
	- isblank
	- isupper / islower
	- toupper / tolower


# C-string manipulation
- header: \<cstring\>
- common functions:
	- strlen
	- strcmp / strncmp: compare the whole string and part of strings
	- strchr: find first occurence / left-right direction
	- strrchr: find last occurence / right-left direction

## Concatenation and Copying
- Join strings and Copying
- strcat / strncat(des, src, pos) and strcpy(des, src) / strncpy

## std::string
- header: \<string\>
``` cpp
#include <string>
using namespace std;

int main(void) {
	string full_name; // empty string
	string planet {"Earth"}; // Initialized with string literal
	string ref_planet {planet}; // Initialized with existing string
	string msg {"Hello world!", 5}; // take first 5 chars of string
	string msg2 {"Hello world!", 6, 5}; // take from pos 6, 5 chars
	string dup (4, 'e'); // "eeee"

	return 0;
}
```

**End of "Character and string manipulation**
---------------------------------------------
**Functions**
- Reusable piece of code
``` cpp
return_type function_name (param 1, param 2, ...) {
	// code_block
	return retur_type;
}
int main(void) {
	// calling a function
	function_name();
	// if it has a return type (not void)
	return_type = function_name();
}
```

- Implicit conversions in functions: double - int
- Argument scopes: copies of param
- Declaration is to be put before `int main(void){}`
``` cpp
// Declaration / Prototype
// "Signature" doesn't include return_type
int larger(int a, int b);

int main(void) {
	int a, b;
	// input a and b
	int larger_int = larger(a, b);
	return 0;
}
// Definition
int larger(int a, int b) {
	return a > b ? a : b;
}
```

# Types of pass by
- by value: function(int age){}
- by ptr: function(int \*age){}
- by ref: funciton(int &age){}
# Input and Output parameters
- Output param should be use with either ptr or ref, so we can write changes to the original.
- Use with `void function_name(){}`
# Returning from functions
- Alternative way of the above.
- Complier optimization: return by ref > return by value, to avoid having copies of variables. Usually happen with *string*, all in all this action by the complier is to reduce memory usage.
- !! Aware of return by ref yourselves


# Function overloading
- 1 function (same name) that have multiple return_type
- Changes depend on the parameters:
	- order
	- number
	- types
``` cpp
int larger(int a, int b);
double larger(double a, double b);
```


# Lambda function
- A mechanism to set up anonymous function (no name).
- Once we have them set up, we can either give them name and call them, or just use them directly even without name.

## Declaring and Using
``` cpp
/* return_type is optional
[capture list](parameters) -> return_type {
	// code_block
};
*/
auto func = []() {
	cout << "Hello world\n";
};
func();
// call lambda directly without name
[](param) {
	// code_block
}(I/O);
```

## Capture list
- Take copies of the outside, already declared variables
- Take by reference &
### Capture all in context
- All by value [=]
- All by ref [&]

**End temporary on "Lambda function"**
--------------------------------------
**Function template**
- Considered as function blueprints, not actual C code but rather the code will be generated when needed by complier.
- To see the complier in action: [C++ Insights](https://cppinsights.io)
- For code repetition: function overloads
``` cpp
// blueprint for the larger() function
/*
	template <typename T>
	T larger(T a, T b){
		return (a > b)? a : b;
	}
*/
template <typename T> T larger(T a, T b);
int main(void) {}
template <typename T> T larger(T a, T b) {
	return (a > b)? a : b;
}
```
- !! All `T` need to be the same type.
- Careful when use with pointers


# Template type parameters by ref
- So far, we were using *param by value*
``` cpp
// params by ref
template <typename T> const T& function_name(const T& params);
```
- Template overload ??? Confuse the complier
``` cpp
// complier can't decide which template to use
template <typename T> T larger(T a, T b);
template <typename T> const T& larger(T& a, T& b);
```

# Template type deduction and explicit arguments
- Deduction: complier will determine which type of T should it use
- Explicit: the dev forces/tells the template beforehand using `larger<type>(params);`

# Template specialization
- Override template when params fit in special cases
``` cpp
template <typename T> T maximum(T a, T b);
// Specialization
// complier will run this when const char * are passed as param
// example use: string pointer to avoid comparision of addresses
template <>
const char *maximum<const char *> (const char *a, const char *b);
```


# Concepts
- [C++20 feature](https://en.cppreference.com/w/cpp/concepts): using concept `#include <concepts>`
- Mechanism to place constraints on your template type params. An alternative to static_assert and type traits
- This is evaluated at complier-time, deevaluated to boolean value. Will return complier error.
``` cpp
template <typename T>
void print_number(T n) {
	static_assert(is_integral<T>::value, "Must pass in an integral argument");
	cout << "n: " << n << endl;
}
```

## Syntax and uses
- There are standard built-in and custom concepts, some core language concepts:
	- same_as
	- derived_from
	- integral
	- etc.

``` cpp
// Using concept
template <typename T>
requires std::integral<T>
T add (T a, T b) {
	return a + b;
}
// Using type trait
template <typename T>
requires std::is_integral_v<T>
T add (T a, T b) {
	return a + b;
}
// Syntax 2
tempalte <std::integral T>
T add (T a, T b) {
	return a + b;
}
// Syntax 3: this is more like a function
auto add (std::integral auto a, std::integral auto b) {
	return a + b;
}
// Syntax 4
template <typename T>
T add (T a, T b) requires std::integral<T> {
	return a + b;
}
```

## Custom concepts
``` cpp
/*
template <typename T>
concept my_concept_name = requires (params) {
	// syntax to satisfy
};
*/
template <typename T>
concept multipliable = requires (T a, T b) {
	a * b; // making sure the syntax is valid
};
template <typename T>
concept incrementable = requires (T a) {
	a += 1;
	a++;
	++a;
};
```
- After defining your cutoms concepts, you can use is similar to the standard ones, eg `template <MyConcept T> T add (T a, T b){}`

## Requires clause
- Four kind of requirements:
	- simple
	- nested
	- compound
	- type
``` cpp
// simple requirement: expression only checks for valid syntax
template <typename T>
concept TinyType = requires (T t) {
	sizeof(T) <= 4;
};
// neseted requirement
template <typename T>
concept TinyType = requires (T t) {
	sizeof(T) <= 4; // simple
	requires sizeof(T) <= 4; // nested: checks if the expression is true
};
// compound requirement
template <typename T>
concept addable = requires (T a, T b) {
	{a + b} noexcept -> std::convertible_to<int>; // compound
	// checkes if a+b is valid syntax, doesn't throw exception (optional), and the result is convertible to int (optional)?
};
```

## Logical combination of concepts
- && and || or
``` cpp
template <typename 0>
concept Tinytype = requires (T t) {
	sizeof(T) <= 4;
	requires sizeof(T) <= 4;
};
template <typename T>
T func(T t) requires std::integral<T> &&
			requires (T t) {
				sizeof(T) <= 4;
				requires sizeof(T) <= 4;
			}
{
	std::cout << "Value: " << t << std::endl;
	return (2*t);
}
template <typename T>
// requires std::integral<T> || requires std::floating_point<T>
requires std::integral<T> && requires (T t) {
	sizeof(T) <= 4;
	requires sizeof(T) <= 4;
}
T add (T a, T b) {
	return a + b;
}
```

## Concepts and auto
- Contraints in template (common uses), declaration (rarely use)

**End of "Function template"**
------------------------------
**Classes**
- "custom types" that are defined by the dev
- Consist of *objects* and *methods*, which are 'private' by default:
	- objects can be ptr but CAN'T be ref
	- functions are called methods, and can access object regardless of them being public or private
	- private members can't be accessed outside of class

# General
- 'public' means member of its can be accessed from outside of its class.
``` cpp
const double pi {3.1415926};

class Clylinder {
// class's objects/variables
public:
	double base_radius{};
	double height{};
// class's funciton
public:
	double volume() {
		return pi * base_radius * base_radius * height;
	}
};

int main(void) {
	Cylinder cylinder1;
	cylinder1.base_radius = 3.0;
	cylinder1.hegiht = 2;
	cout << "The volume of the clynder1: " << cylinder1.volume() << endl;
	return 0;
}
```


# Constructor
- Special method, that is called when an instance of class is created:
	- no return type
	- same name as class
	- can either have parameters or empty
	- usually used to initialize member variables of class
``` cpp
class Cylinder {
	private:
		double base_rad{};
		double height{};
	public:
		// constructor
		Cylinder(double rad_param, double height_param) {
			base_rad = rad_param;
			height = height_param;
		}
		// methods
		double volume() {
			return pi * base_rad * base_rad * height;
		}
};
int main(void) {
	Cylinder cylinder1(10, 4);	// create class cylinder1 with base_rad of 10 and height of 4
	return 0;
}
```

## Default constructor
- `Cylinder cylinder2()` will fail without `Cylinder() = default` which is the default constructor.


# Setter and Gette
- Methods to read or modify member variables of class.
``` cpp
class Cylinder {
	private:
		double base_rad{};
		double height{};
	public:
		// Constructor
		Cylinder() = default;
		// Getters
		double get_base_rad() {
			return base_rad;
		}
		double get_height() {
			return height;
		}
		// Setters
		void set_base_rad(double rad_param) {
			base_rad = rad_param;
		}
		void set_height(double height_param) {
			height = height_param;
		}
		// Some other methods
};
```


# Class across multiple files
- For the cylinder example, file structure can be:
	- main.cpp: using pi and cylinder from other files
	- constants.h: declaration of constant variable, like pi
	- cylinder.h: preview/declaration of the class
	- cylinder.cpp: the actual class's definition
- ./multiFiles/cylinder/
- *include guard*: avoid calling/pasting header multiple times
``` cpp
#ifndef header_name
#define header_name

// code_block

#endif
```


# Managing class objects through pointers
``` cpp
#include <iostream>
#include "constants.h"
#include "cylinder.h"
int main(void) {
	// Stack object: . notation
	Cylinder c1(10, 2);
	std::cout << "Volume c1: " << c1.volume() << std::endl;
	// Heap object: -> notation
	Cylinder *c2 = new Cylinder(10, 3);
	std::cout << "Volume c2: " << (*c2).volume() << std::endl;
	std::cout << "Volume c2: " << c2->volume() << std::endl;
	delete c2;
	return 0;
}
```


# Destructor
- Special method that is called when an object is terminated. They are needed when there's a need to release dyn. memory or some kind fo clean up.
- Destructor is called when:
	- an object is passed by value to a func
	- a local object is returned from a func
	- local stack object goes out of scope
	- heap object is released with *delete*


# Constructor and Destructor call order
- If declared by `Class class_name` then by stack order: last in first out.


# The *this* pointer
- Each class member function contains a hidden pointer, called *this*
- This pointer contains the address of the current object, for which the method is being executed. This applied to cons and des.
``` cpp
// for conflicting name
void set_name(const std::string &dog_name) {
	this->dog_name = dog_name;
}
// so the this->dog_name is a member var of the class, while the dog_name is from the parameter

// chained calls using pointers
Dog *set_name(const std::string &dog_name) {
	this->dog_name = dog_name;
	return this;
}
Dog *set_breed(const std::string &dog_breed) {
	this->dog_breed = dog_breed;
	return this;
}
Dog *set_age(const std::string &dog_age) {
	if(this->dog_age) {
		*(this->dog_age) = dog_age;
	}
	return this;
}
// in main()
Dog *p_dog1 = new Dog();
p_dog1->print_info();

p_dog1->set_name("Mario")->set_breed("Terrier")->set_age(5);
p_dog1->print_info();

delete p_dog1;

// chained calls using ref
Dog &set_name(const std::string &dog_name) {
	this->dog_name = dog_name;
	return *this;
}
Dog &set_breed(const std::string &dog_breed) {
	this->dog_breed = dog_breed;
	return *this;
}
Dog &set_age(const std::string &dog_age) {
	if(this->dog_age) {
		*(this->dog_age) = dog_age;
	}
	return *this;
}
// in main(): notice the . notation here
p_dog1->set_name("Mario").set_breed("Terrier").set_age(5);
```


# Struct
- Members are public by default, otherwise it's same as *class*.
- Common use:
	- struct Point {};
	- struct Node {};


# Size of class objects: total size of member variables
- Though that definition isn't always correct, cause of *boundary alignment*: since memory spaces that store member varibles might have gaps between them, hence size of class might result in taking more memory than plain sum of variables' sizes.
- !! Size of strings is same regardless of how long it is, since technically the complier only care about the pointer pointing to the string's first char.

**End of "Classes"**
--------------------
**Inheritance**
- Build class from other class
	- class Person {};
	- class Engineer : public Person
	- class CivilEng : public Engineer
- A defining feature of Object-oriented Prog in C++
- Build types on top of other types
- Hierarchies set up to your needs
- Code reuse is improved

``` cpp
class Person {
	friend std::ostream &operator<<(std::ostream &out, const Person &person);

	public:
		Person();
		Person(std::string first_name_param, std::string last_name_param);
		~Person();
	private:
		std::string first_name{};
		std::string last_name{};
};

class Player : public Person {
	friend std::ostream &operator<<(std::ostream &out, const Player &player);
	
	public:
		Player() = default;
		Player(std::string game_param);
		~Player();
	private:
		std::string m_game{};
};
```
- With public inheritance (public Person), derived classes can access public member of the base class, but can't directly to the private ones.
- The same is applied to *friends* of the derived class. They have access to private members of derived, but not to the base's.

# Protected members
- Change *private* to *protected*, will grant read and write access to these members from derived classes.

# Base class access specifiers
- `class Player: public Person` is a specifer, where from base to derived:
	- public stays public
	- protected stays protected
	- private stays private
- For `: protected Person`:
	- public turns protected
	- protected and private stay
- For `: private Person`:
	- all turn private
- For whichever specifiers, private from base class can never be accessible from derived.

## Demo: 23:39:00
## Private inheritance
- Public of a derived private will have everything as private too.
- Specifiers won't be able to open up access but only constrait it more and more.

## Resurrecting members back in scope
- `using` keyword: `using Person::m_address`
- !! Not possible to make something private from start to public.
- Can be confusing, since it's more like a backdoor, loophole.

# Default arg constructors with inheritance
- Always provide a default constructor for your classes, esp. when they will be part of an inheritance hierarchy.
- Since for example with: Person -> Engineer -> CivilEng, when calling `CivilEng civileng1` constructor will be called from Person's to Engineer's and lastly the actual CivilEng's constructor.

# Custom constructor with inheritance
- How to forward params from derived to base when an object is created
- Need to do thing this way instead of using `this->member_variable` since there're private members which can't be accessed directly with `this`.
``` cpp
Engineer::Engineer(string_view fullname, int age, string_view address, int contract_count_param) {
	this->m_full_name = fullname;
	...
}
```
- Putting these into the initializer is bad too, since it's not the derived class's job to initialize member of Person's.
``` cpp
Engineer::Engineer(string_view fullname, int age, string_view address, int contract_count_param)
	m_full_name(fullname), m_age(age), m_address(address) {}
```
- The correct way:
``` cpp
Engineer::Engineer(string_view fullname, int age, string_view address, int contract_count_param)
	: Person(fullname, age, addres), contract_count(contract_count_param) {}

// in main()
Engineer e1("John Snow", 35, "Random street", 6);
// John Snow, 35 and Random street will be forward to Person
```

# Copy constructor with inheritance
``` cpp
Engineer e1("name", age, "stree", contract_count);
Engineer e2(e1); // copy constructor

//
Person::Person(const Perons &source)
	: m_full_name{source.m_full_name},
	m_age{source.m_age},
	m_address{source.m_address} {}
Engineer::Engineer(const Engineer &source)
	: Person(source),
	contract_count{source.contract_count} {}
```

# Inheriting base constructor
- `using Person::Person; // Inheriting the base's cons`
- Note:
	- copy cons are not inherited
	- inherited contructors are base's. They have no knowledge of derived class. So any member from derived will be junk value.
	- will also inherit specifier
	- !! this add another of confusion to your code, avoid using

# Inheritance with destructor: LIFO
# Reused symbol in inheritance
``` cpp
class Parent{};
class Child : public Parent {};
// both has same `void print_var(){};`
Child.print_var(); // call Child's method
Child.Parent::print_var(); // call Parent's method
```

**End of "Inheritance"**
------------------------
**Polymorphism**
- Using base's ptr or ref that manage derived's objects
- Managing derived objects in memory through base ptrs or refs and gettings the right method called on the base ptr or ref.
``` cpp
Shape *shape1 = new Circle;
Shape *shape2 = new Oval;
Shape *shape3 = new Rectangle;

Shape &ref1 {&shape1};
Shape &ref2 {&shape2};
Shape &ref3 {&shape3};
```
- Passing to function
``` cpp
void draw_shape(Shape *shape_ptr) {
	shape_ptr->draw();
}
void draw_shape(const Shape &shape_ptr) {
	shape_ptr.draw();
}
```
- Storing base pointers in a collection of array
![](https://cdn.discordapp.com/attachments/888855938675638316/960964873934757988/unknown.png)

## Static binding: complier looks at the pointer type to decide which version of draw() to call
``` cpp
Shape shape1("Shape1");
Oval oval1(2.0, 3.5, "Oval1");
Circle circle1(3.3, "Circle1");

Shape *shape_ptr = &shape1;
shape_ptr->draw();	// call Shape::draw()

shape_ptr = &oval1;
shape_ptr->draw();	// call Oval::draw()

shape_ptr = &circle1;
shape_ptr->draw();	// call Circle::draw()
```

# Why use Polymorphism
- Less function creation on similar class and derived
``` cpp
void draw_circle(const Circle &circle) {
	circle.draw();
}
void draw_oval(const Oval &oval) {
	oval.draw();
}
// but what if there're 100+ shape
void draw_shape(Shape *shape_ptr) {
	shape_ptr->draw();
}
void draw_shape(const Shape &shape_ptr) {
	shape_ptr.draw();
}
```
- Collection of classes
``` cpp
Shape shape1;
Oval oval1;
Circle cirlce1;

Shape *shape_colleciton[] {&shape1, &oval1, &circle1};

for (Shape *s_ptr : shape_collection) {
	s_ptr->draw();
}
```

## Dynamic binding with virtual functions
- `virtual` keyword
- adding it before shape, oval, circle method of draw() in the header files
- A method has to be both accessible with `public` or `protected` and has `virtual` to be accessed directly.

# Size of polymorphic objects and slicing
- `virtual` takes much more memory spaces, +8 bytes (?)
- slicing: assigning object to a smaller-space object
	- !! If you store raw obj data in an array set up to store base class obj, the data is going to be sliced off
``` cpp
Shape shape2 = oval1;
// shape2 will only store the oval's basic shape member variables, fitting its memory space
```

# Polymorphic objects stored in collections
- storing to raw base obj will result in slicing
- can be stored to ptr, NOT to ref
- *smart pointer*: `#include <memory>`
``` cpp
std::shared_ptr<Shape> shape[] {std::make_share<Circle>(12.2, "Circle4"), std::make_share<Oval>(10.0, 20.0, "Oval4")};
for (auto &s : shape) {
	s->draw();
}
```

# Override
- Avoid error in inheritance hierarchy when you use `virtual` function to setup polymorphic behavior for derived objs
``` cpp
class Oval : public Shape {
	// ...
	virtual void draw() const override {}
	// ...
}
```
	- that will replace/override Shape::draw(), this will fail/errored if there's no draw() in base class -> safe behavior, in case of typo or misusage

# Overloading, Overriding and Hiding
- overriding with overload
- When using `override` on one of the overload, every other ones will be hidden and won't be accessible by derived. You will have to override every single overloads
- What if using 'overloads introduced downstream' (eg. putting overloads in Oval)? Won't work either in poly. since technically the overloads in base are already hidden, so complier will throw error.
	- But if we consider Oval as base of Circle, then poly. will work with Circle coming from Oval, since there're overloads present in Oval.

# Inheritance and Polymorphism at different levels
# Inheritance and Polymorphism with *static* members
- static variables/members: members that are not bound to class instances
	- For outside of class:
		- private to a certain class or scope or cpp file, where linker won't be able to "see", or complain if the same variable is declare elsewhere.
		- or without `static`, the same variable can be declared, or more precisely refered to by using `extern`
	- For inside of class:
		- available to that one class's instance, base or derived is consider as 'an instance'

- Example usage: count how many Shape are created? How many Oval are created? Without `static`, the value will just be total of everything, Shape == Oval

# *final* specifier
- Uses:
	- Restrict how you override methods in derived classes
	- Restrict how you can derive from a base class
- Subclasses/Derived can't override the origin's method and have to use its implementation as is, ~ final version of the method.
``` cpp
void run() override final {}
```
- No more derived after this
``` cpp
class Cat final : public Feline {
	// ...
	// This is a useless virtual method
	// Since Cat is `final` so there're no subclasses to specilize Cat's miaw anymore
	virtual void miaw() const {}
};
```
- !! Useless virtual cases:
	- virtual with final class
	- virtual with final in its prototype
	``` cpp
	virtual void fly() const final {}
	```
# Virtual functions with default argo
- Default args are handled at compile time, which makes it choose default arg from Base's.
- v_funcs are called at runtime with poly, while here it choose the method from the derived.
- If you use default args with v_funcs, you might get weird/erronoeous results with poly.
``` cpp
class Base {
	public:
		Base();
		~Base();

		virtual double add(double a = 5, double b = 5) const {
			std::cout << "Base::add() called." << std::endl;
			return (a + b + 1);
		}
};

class Derived : public Base {
	public:
		Derived();
		~Derived();

		virtual double add(double a = 10, double b = 10) const override{
			std::cout << "Derived::add() called." << std::endl;
			return (a + b + 2);
		}
};

int main(void) {
	Base *base_ptr1 = new Derived;
	double result = base_ptr1->add();
	std::cout << "Result of base_ptr: " << result << std::endl; //12

	Derived derived1;
	Base &base_ref1 = derived1;
	result = base_ref1.add();
	std::cout << "Result of base_ref: " << result << std::endl; //12
	// although Derived::add() is called correctly, but a and b value go by Base:add()'s
```
- !! Best to not use this

# Virtual destructor
``` cpp
// hierarchy: Animal > Feline > Dog
Animal *animal = new Dog;
delete animal;
// without virtual ~Animal(); and virtual ~Feline(); and virtual ~Dog(); the delete arg will lead to memory leak
```

# Dynamic_cast<>()
- downstream transformation between polymorphic obj
- Uses:
	- transforming from base class ptr or ref to derived class ptr or ref at runtime
	- makes it possible to call non-polymorphic methods on derived objs
- Is usually use in functions.
- Avoid overusing down-casting
``` cpp
Feline *feline_ptr = dynamic_cast<Feline*>(animal1);
// casting ref like this so it's possible to check nullptr, since there's no equivalent of that with ref
Feline *feline_ptr = dynamic_cast<Feline*>(&animal_ref);
// check for nullptr
if (feline_ptr) {
	feline_ptr->something_not_poly_nor_virt();
} else {
	std::cout << "Can't cast to Feline pointer." << endl;
}
```

**End of "Polymoriphism"**
--------------------------

# One definition rule
- Context:
	- free standing vars
	- functions
	- classes
	- class member functions
	- class static member vars
