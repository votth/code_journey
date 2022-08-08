# Machine code: binary
- human writes code in various languages, such as: C, Python, JavaScript etc.
- some would require a *complier* to translate programming language into machine language, or binary

# Bits / bytes
- 1 data is usually represented with 8bits: 0000 0000
- ASCII is used to interpret letters (lower and uppercase), number, special characters... There are 256 ASCII characters
- UNICODE is used to interpret even more characters, such as ANSI/Europe languages, emojis etc.
- and even bigger encoding, which I forgot its name :'P

# Scratch programming
- high-level block-based visual programming language

# Data types
- Some commonly used ones are int(eger), string, c(har), li (long), f(loat)
- overflow / underflow : too big/small / too many decimal digits

# "Hello world" program
``` c
include <stdio.h>

int main(void)
{
    printf("Hello, world");
}
```

# Operators
- Simple arithmethic: + - / * %
- x++;    x--;    x\*=
- Boolean expressions: && and    || or    ! not
- Relational: > < >= <= == !=
- Assign value: =

# Conditional statements

``` c
if (condition)
{
    <!-- block of code -->
}
else
{
    <!-- if [condition] is false -->
}
```
``` c
switch(x)
{
    case 1:
	<!-- block of code -->
	break;
    case 2:
	<!-- block of code -->
	break;
    case 3:
	<!-- block of code -->
	break;
    case 4:
	<!-- block of code -->
	break;
    default:
	 <!-- in case no case is a match -->
}
```
``` c
<!-- conditional shorthand: if true then 5 else 6 -->
int x = (expr) ? 5 : 6
```

# Loops
- execute code repeatedly

``` c
while (condition)
{
    <!-- block of code -->
}

do
{
    some code
} while (condition)
```
run code until condition is false, do-while will always run the code at least once

``` c
for (int i=0; condition; i++)
```
if you know how many times to loop a set of code

# The *make* command
- It is not a complier, it's a program that knows what complier to use
