# *clang* command
- is a complier
- use for c language
- example
``` 
clang -o hello hello.c
```
    - "-o hello" specify where, what name to save the program as
    - "hello.c"  the source code
    - "-l{libraryName}" if you *include* a custom library
-
    - preprocessing
    - compiling
    - assembling     translate into 01
    - linking        links all the 01 gotten from snippets of code
# Debugging
- syntax errors
- logical errors

- most simple, using "printf" to 'stop' program temporary and fetch useful information, that *might* tells you what's wrong with the source code
- *debug50* command: a debugger, that runs through code step by step
    - breakpoint: determine by you to specify where to stop the program
    - stepin, stepout, stepover
- rubber duck: talk to the duck or inanimated objects

# Functions
Example code
``` c
#include <stdio.h>

int get_int(void);

int main(void)
{
    int i = get_int();
    printf("%i\n", i);
}

int get_int(void)
{
    int n;
    n = scanf("%i");
}
```
The first "int get_int(void)" tells the program to initial/know that there's a function named "get_int"
The second appearance is the function's actual code snippet

- funcitons, procedures, methods, subroutines
- func()
- have clear, obvious-ish name and are well-documented, since most of the time people should be able to tell/guess what a function does just from its name
- usage of functions:
    - organization
    - simplication
    - reusability
- function declarations
``` c
    return-type name(argument list);
```

# Variable scope
- scope
    - characteristic of variables
    - defines from which functions that variable may be accessed
- local and global variable

# Arrays
- block of contiguous space in memory, that has been partitioned into smaller, indentical-sized blocks of space called *elements*
- each element can contain a certain amount of data with the same types as the other elements in the same array, int char etc.
- we can access the memory of those elements by using their *index number*
- !! C is very lenient, it won't prevent "out of bounds"
- declarations
``` c
    type name[size];

    type name[] = {list of elements};
```
- array can be multi dimentional, eg: [10]\[10]
- !! array is not a variable so we can't assign one array to another, must loop through its elements and assign by element
- for function with arguments, with **variables**, functions work with a copy of the variable not with the variable itself, which is called **passed by value**
  while with **array**, functions work with the actual array not its copy, which is called **passed by reference**

