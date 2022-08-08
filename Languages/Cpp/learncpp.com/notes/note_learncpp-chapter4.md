# 4.1 Introduction to fundamental data types

## Bits, bytes and memory addressing
The smallest unit of memory is a **binary digit** / **bit**, which can hold a value of 0 or 1.  
Memory is organized into sequential units called **memory addresses**

In modern computer architectures, each bit does not get its own unique memory address. Because the number of memory addresses are limited, and the need to access bit-by-bit is rare. Instead, each memory address holds 1 bye of data. A **byte** is a group of bits that are operated on as a unit, each consists of 8 sequential bits. *Some older or non-standard machines may have bytes of dfferent size from 1 to 48 bits.*

## Data types
Because all data on a computer is just sequence of bits, we use **data type** to tell the compiler how to interpret the contents of memory in some meaningful way.  

When you give an obj a value, the compiler and CPU take care of encoding your value into the appropriate sequence of bits for that data type, which are then stored in the memory.  

## Fundamental data types
**basic types, primitive types**, or **built-in types**  
List of fundamental datat types:
- float
- double
- long double
- bool
- char
- wchar_t
- char8_t (C++20)
- char16_t (C++11)
- char32_t (C++11)
- short
- int
- long
- long long (C++11)
- std::nullptr_t (C++11)
- void

C++ also supports a number of other more complex types, called *compound types*. For example: `std::string` in C++ is a compound type while in other languages, it's fundamental.  

`integral` is similar to `integer` but have different meaning. `Integral` means "like an integer". Most often, `integral` is used as part of the term `integral type`, which includes all of the Boolean, characters, and integer types (also enumerated types). These are named as such because they are stored in memory as integers, eventhough their behaviors might vary.

## The *_t* suffix
Many of the types defined in newer versions of C++ use a \_t suffix, means "type", and is a common nomenclature applied to modern types.


# 4.2 Void
Basically means "no type"!  

Can't be assiged to variables.  
Function that do not return a value.  
*Deprecated*: Functions that do not take parameters.  
Void pointers.


# 4.3 Object sizes and the `sizeof` operator

## Object sizes
More bits/bytes means holding more information. The size of an object limits the amount of unique values it can store.

A small portion of a computer's free memory is used for as long as an object is in existence.

## Fundamental data type sizes
```
boolean		bool		1 byte
character	char		1 byte
			wchar_t		1 byte
			char16_t	2 bytes
			char32_t	4 bytes
integer		short		2 bytes
			int			2 bytes
			long		4 bytes
			long long	8 bytes
floating	float		4 bytes
			double		8 bytes
			long double	8 bytes
```
actual size may be different on machines, particularly int, which is more often 4 bytes.

Objects of fundamental data types are generally extremely fast.

## The `sizeof` operator
The `sizeof` operator is a unary operator that takes either a type or a variable, and returns its size in bytes.  
Cannot be used on type *void*.

## Fundamental data type performance
Less memory does not mean faster performance, since CPUs are often optimized to process data of a certain size, like 32bits.


# 4.4 Signed integers
An **integer** is an integral type that can represent positive and negative whole numbers:
```
short		16 bits
int			16 bits		typically 32 bits on modern architectures
long		32 bits
long long	64 bits
```

## Signed integers
The attribute of being positive, negative, or zero is called the number's **sign**. And by default, integers are **signed**, which means the number's sign is stored as part of the number in memory, using a single bit as **sign bit**.

## Defining signed integers
``` cpp
short s;
int i;
long l;
long long ll;
// the keyword signed does exist, but it's redundant to type out
```

## Signed integer ranges
For an 8-bit integer (holding 2^8 = 256 value) can have values between -128 to 127.
```
8 bit signed		-128 to 127
16 bit				-32,768 to 32,767
32 bit				-2,147,483,648 to 2,174,483,647
64 bit				-(2^n-1) to 2^n-1 -1
```

## Integer overflow
Trying to store a value that is outside the range of the type, essentially, the number's requiring more bits to represent than the object has available. Leading to undefined behavior, data lost.

## Integer division
C++ always produces an integer result. Be careful as you will lose any fractional parts of the quotient.


# 4.5 Unsigned integers, and why to avoid them
Integers that can only hold non-negative whole numbers.

## Defining unsigned integers
``` cpp
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;
```

## Unsigned integer range
From 0 to 2^n -1.  
Well-suited for networking and systems with little memory.

## Unsigned integer overflow
Modulo wrapping: divide for the largest posible upper limit, and take the remainder as the actual stored value.

## The controversy over unsigned numbers
First, substraction of two unsigned numbers: 3 - 5; can't be represented as an unsigned number. Priting the result will give gabage value.  

Second, unexpected behavior can result when mixing signed and unsgined integers. In a mathemacial operation in C++ (arithmetic or comparision), if one signed and one unsigned are used, the signed integer will be converted to unsigned, leading to lost of data.

## When should you use unsigned?
- dealing with bit manipulation, when well-defined wrap-around behavior is required. Useful in some algorithms like encryption and random number generator.
- unavoidable in some cases, mainly those having to do with array indexing.
- developing for embedded system (Arduino) or some other processor/memory limited context, for permance reason.


# 4.6 Fixed-width integers and `size_t`
Avoid assumption on if int is 2 or 4 bytes on what system.

## Fixed-width integers
C99 defined a set of fixed-width integers in the `stdint.h` that are guaranteed to be the same size on any architecture.
```
std::int8_t			1 byte signed
std::uint8_t		1 byte unsigned
std::int16_t		2 byte signed
std::uint16_t		2 byte unsigned
std::int32_t		4 byte signed
std::uint32_t		4 byte unsigned
std::int64_t		8 byte signed
std::uint64_t		8 byte unsigned
```
Officially adopted in C++11 and can be accessed by including `<cstdint>` header.

Downsided:
- are not guaranteed to be defined on all architectures: only exist on systems where there are fundamental types matching their widths and following a certain binary representation.
- may be slower than a wider type on some architectures.

## Fast and least integers
To address the above downsided, C++ defines two alternative sets that are guaranteed to be defined:
- `std::int_fast#_t`, `std::uint_fast#_t` provides the fastest signed/unsigned integer type with a width of at least # bits
- `std::int_least#_t`, `std::uint_least#_t` provides the smallest signed/unsigned integer with a width of at least # bits.

These sets own downsides:
- not many programmers use them, and this lack of familiarity can lead to errors.
- fast types can lead to the same kind of memory wastage similar to the 4 byte integers.
- may exhibit different behaviors because of the variness in fast/least integers.

## `std::int8_t` and `std::uint8_t` likely behave like chars instead of integers
Best to avoid using them.

## Integral best practices
Better to be correct than fast, better to fail at compile time than runtime -- avoid the fast/least types.
- prefer `int` when the size of integer doesn't matter.
- prefer `std::int#_t` when storing a quantity that needs a guaranteed range
- prefer `std::uint#_t` when doing bit manipulation or where well-defined wrap-around behavior is required.

Avoid the following when possible:
- Unsigned types for holding quantities
- The 8-bit fixed-width integer types
- The fast/least fixed-width types
- Any compiler-specific fixed-width integers, eg. VS \__int8

## What is `std::size_t`?
It is defined as an unsigned integral type, and is typically used to represent the size or length of objects. Eg: type of `sizeof()`


# 4.7 Introduction to scientific notation
**Scientific notation** is a useful shorthand for writing lengthy numbers in a concise manner. Knowing this will help in understanding how floating point numbers work, and what their limitations are.

Form: *significand* x 10^exponent; eg. 1.2 x 10^4 = 12,000.  
By convention, numbers in scientific notation are written with one digit before the decimal point, and the rest of the digits afterwrad.

Beside making it easier to read, scietific notation also helps to compare the magnitude of two really big or really small numbers simply by comparing the exponent.

In C++, the letter *e* is used to represent the 10^x exponent, eg: 1.2e4. For numbers smaller than 1, exponent can be negative.

## How to convert numbers to scientific notation
- Exponent start at zero.
- Slide the decimal so there is only one non-zero digit to the left of the decimal.
	- Each place you slide the decimal to the left increases the exponent by 1.
	- And to the right decreases it by 1.
- Trim off any leading zeros (on the left of the significand).
- Trim off any trailing zeros (on the right end) only if the original number had no decimal point, that is to retain the number precision.

## Precision and trailing zeros after the decimal
Weighting the same apple and got 87 vs 87.00.  
Range of variability for the former is 86.50-87.49, while the later is only 86.9950-87.0049.

In C++, the two are considered the same and will be stored as such.


# 4.8 Floating point numbers
Integers are great for counting whole numbers, but sometimes we need to store *very* large numbers, or numbers with fractional component. A **floating point** type variable is a variable that can hold real number. The *floating* part of the name referes to the fact that the decimal point can "float"; that is, it can support a variable number of digits before and after the decimal point.

There are three different floating point data types: **float**, **double**, and **long double**. As with integers, C++ does not define the actual size of these types (but it does guarantee minimum sizes).  
On modern architectures, floating point representation almost always follows IEEE 754 binary format: a float is 4 bytes, a double is 8, and a long double can be equivalent to a double (8 bytes), 80-bits (often padded to 12 bytes), or 16 bytes.

Floating point data types are always signed.

``` cpp
float fValue;
double dValue;
long double ldValue;
```

When using floating point literals, always include at least one decimal place (even if the decimal is 0). This helps the compiler understand that the number is a floating point number and not an integer.
``` cpp
int x{5};		// 5 means integer
double y{5.0};	// 5.0 is a floating point literal, no suffix mean double type by default
float z{5.0f};	// 5.0 is a floating point literal, f suffix means float type
```
Note that by default, floating point literals default to type double. An f suffix is used to denote a literal of type float.

!! Always make sure the type of your literals match the type of the variables they're being assigned to or used to initialize. Otherwise an unnecessary conversion will result, possibly with a loss of precision.
!! Make sure you don't use integer literals where floating point should be used. This includes when initializing or assigning values to floating point objects, doing floating point arithmetic, and calling functions that expect floating point values.

## Printing floating point numbers
``` cpp
#include <iostream>

int main() {
	std::cout << 5.0 << "\n";
	std::cout << 6.7f << "\n";
	std::cout << 9876453.21 << "\n";

	return 0;
}

// Output
// 5	std::cout ignores the 0 fractional
// 6.7	std::cout prints as we expected
// 9.87654321e+06	prints in scientific notation
```

## Floating point range
Assuming IEEE 754 representation:
Size		Range							Precision  
4 bytes		+-1.18e-38 to +- 3.4e38		6-9 significant digits, 7  
8 bytes		+-2.23e-308 to +- 1.80e308		15-18, typically 16  
80-bits		+-3.36e-4932 to +- 1.18e4932	18-21 digits  
16 bytes	+-3.36e-4932 to +- 1.18e4932	33-36 digits  

The 80-bit floating point type is a bit of a historical anomaly. On modern processors, it is typically implemented using 12 or 16 bytes, which is more natural size for processors to handle.  
And the 80-bit has the same range as the 16-bytes because they have the same number of bits dedicated to the exponent; however, the 16-byte number can store more significant digits.

## Floating point precision
On a computer, an infinite length number (0.3333...) would require infinite memory to store, and typically we only have 4 or 8 bytes. This limited memory means floating point numbers can only store a certain number of significant digits, and any additional significant digits are lost. The number that is actually stored will be close to the desired number, but not exact.

The **precision** of a floating point number defines how many *significant digits* can represent without information loss.

std::cout has a default precision of 6 and will truncate anything after that.
``` cpp
#include <iostream>

int main() {
	std::cout << 9.87654321f << "\n";
	std::cout << 987.654321f << "\n";
	std::cout << 987654.321f << "\n";
	std::cout << 9876543.21f << "\n";
	std::cout << 0.0000987654321 << "\n";

	return 0;
}

// Output
// 9.87654
// 987.654
// 987654
// 9.87654e+006
// 9.87654e-005
```
The number of digits of precision a floating point variable has depends on both the size and the particular value being stored.

We can override the default precision that std::cout shows by using `output manipulator` (head *<iomanip>*) function named `std::setprecision()`.
``` cpp
// compare these std::cout
std::cout << std::setprecision(16);	// show 16 digits of precision
std::cout << 3.333333333333333333333333333f << "\n";	// float
std::cout << 3.333333333333333333333333333  << "\n";	// double

float f { 123456789.0f };
std::cout << std::setprecision(9);
std::cout << f << "\n";

// Output
// 3.333333253860474
// 3.333333333333334
// 1234567892
```
When precision is lost because a number can't be stored precisely, this is called a **rounding error**.

!! Favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.

## Rounding errors make floating point comparisions tricky
``` cpp
#include <iomanip>
#include <iostream>

int main() {
	double d{0.1};
	std::cout << d << '\n';	//default precision of 6
	std::cout << std::setprecision(17);
	std::cout << d << '\n';

	return 0;
}

// Output
// 0.1
// 0.10000000000000001
```
The double has to truncate the approximation due to its limited memory. The result is a number that is precise to 16 siginificant digits (which type double agrees), but the number is not *exactly* 0.1.
