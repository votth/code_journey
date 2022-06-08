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
https://www.learncpp.com/cpp-tutorial/introduction-to-scientific-notation/

# 4.8 Floating point numbers
