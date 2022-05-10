# 2.1 Introduction to functions
A **funcion** is a reusable sequence of statements designed to do a particular job. This provides us a way to split our programs into small, modular chunks/blocks that are easier to organize, test and use.

The function initiating the function **call**/run is called the **caller**, and the function being called is the **callee/called** function.
```
return-type indentifier()
{
	// code block
}
```

!Nested functions are not supported

Metasyntactic variables / placeholder names: foo & bar, baz, 3-letter words end in "oo".


# 2.2 Function return values (value-returning functions)
return type - return statement  
When the return value is copied from the function back to the caller, it's called **return by value**.  
Make sure your non-void functions have a return statement.

Return value from main is sometimes called **status code / exit code / return code**, as it is used to indicate whether the program ran successfully or not.

For maximum portability, from *<cstdlib>*, only using 0 or EXIT_SUCCESS to indicate a successful terminiation, and EXIT_FAILURE to indicate an unsuccessful termination.

Reusing functions, **Don't Repeat Yourself / DRY** vs **Write Everything Twice / WET**


# 2.3 Void functions (non-value returning functions)
A function that doesn't not require to return a value back to its caller.

Putting an empty return `return;` at the end of void-func is redundant.

Calling a function by itself is calling for the function's behavior, not its value. Be careful of statements that do require a value.

**Early return** when empty return is not the last statement. And will return to its caller immediately, ignoring later statements.


# 2.4 Introduction to function parameters and arguments
Passing information to a function.

A **function parameter** is a variable used in a function, and is always initialized with a value provided by the caller of the function.  
These are defined in a function declaration by placing them in between the parenthesis after the function indentifer, with multiple parameters being separated by commas.

An **argument** is value that is *passed from* the caller to the function when the function call is made.

When a funciton is called, all of the parameters of the funciton are created as variables, and the value of each of the arguments is *copied* into the matching parameters. This process is called **passed by value**.


# 2.5 Introduction to local scope
Function parameters, as well as variables defined inside the function body, are called **local variables**.

## Local variable lifetime
Function parameters are created and initialized when the function is entered, and variabels within the function body are created and initialized at the point of definition.

Local variables are destroyed in the opposite order of creation at the end of the set of curly braces in which it is defined; or for a parameter, at the end of the function.

An obj's **lifetime** is defined to be the time between its creation and destruction. And this value is a runtime property.  
In actuality, the C++ specification gives compilers a lot of flexibility to determine when to create or destroy local variables, created earlier or destroyed later for optimization purposes.

## Local scope
And identifier's **scope** determines where the identifier can be accessed within the source code. When it can be accessed, we say **in scope** and vice versa **out of scope**. This is a compiler-time property.

"out of scope" vs "going out of scope": the former applies to identifer, while the later is applied to object.

## Where to define
should be as close to their first use as reasonable.


# 2.6 Why and how to use function effectively?
## Why?
Organization: As programs grow in complexity, having all the code lives inside the `main` function becomes increasingly complicated. Functions are like mini-programs that we can write separately from the main program, without having to think about the rest of the program while we're writing it.

Reusability: Written functions can be called multiple times from within the program, helps avoid duplicated code and copy/paste errors. Can also be share with other programs.

Testing: reduce code reduncancy, meaning less code to test in the first place. Once tested, it ensures to work from then on.

Extensibility: make change in one place and have it applied every elsewhere used.

Abstraction: in order to use a complex function, we only need to know its name, inputs, outputs and where it lives (what it does), while not needing to know how it's doing the task.

## How?
Groups of statements that appear more than once.

Code that has a well-defined set of inputs and outputs.

Function should only perform one and only one task.

Function being too long, too complicated or hard to understand can be split into multiple sub-functions, this is called **refactoring**.


# 2.7 Forward declarations and definitions
A **forward declaration** tells the compiler about the existence of an identifier before actually defining it.  
A function's forward declaration is called **function protoype**.
- Having return type, name, parameters
- No function body: counting from the curly braces and in between code
- Ends with a semicolon

Prototype is made but function is never called will compiled and ran just fine.  
Prototype is made, function is called but no definition, will compiled but linker will complain that it can't resolve the function call.

## Declaration vs definition:
Definition actually implements (for function or type) or instantiates (for variable) the identifiers.  
A definition is needed to satisfy the *linker*, else will be getting a linker error.

Declaration is a statement that tells the compiler about the existence of an identifer and its type information. Definition can be considered as declaration.  
This is all that needed to satisty the compiler.  
**Pure declaration** is what satisfy the compiler but not the linker.

## The One definition rule (ODR)
Within a given file, a function, variable, type or template can only have one definition.

Within a given program, a variable or normal function can only have one definition.

Types, templates, inline functions, and inline variables are allowed to have identical definitions in different files.

Violating rule 1 will cause compiler error (redefinition), rule 2 will cause linker error, and 3 will cause undefined behavior.


# 2.8 Programs with multiple code files
When compiler multiple files with GCC/G++, you will need to put all the files into the cmd arguments.
```cpp
// main.cpp
#include <iostream>

int add(int x, int y);

int main()
{
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
	return 0;
}

// add.cpp
int add(int x, int y)
{
	return x + y;
}
```

When compiling multiple files, the compiler may does so in any order, and doing them individually without the knowledge of what is in other files.


# 2.9 Naming collisions and an introduction to namespaces
If two identical identifiers are introduced into the same program in a way that the compiler or linker can't tell them apart, the compiler or linker will produce error, and is generally referred to as a **naming collision** or **naming conflict**.

So when two or more definitions for a function/global variable are introduced into:
- separate files that are compiled into the same program, linker will complain.
- same file (often via an #include), compiler will complain.

A **namespace** is a region that allows you to declare names inside of it for the purpose of disambiguation. The namespace provides a scope region (**namespace scope**) to the names declared inside of it, which make name declared inside the namespace won't be mistaken with ones in other scopes.

## The global namespace
In C++, any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly defined namespace called the **global namespace** / **the global scope**.

Only declarations and definition statements can appear in the global namespace. Eg. no stand-alone expressions.

## The std namespace
The C++ standard library namespace.

The *::* symbol is an operator called the **scope resolution operator**. The *left* identifer is the namespace's name, while the *right* is contained within. Empty left is assumed as global namespace.

## Using namespace std; (and why to avoid it)
A **using directive** allows us to access the names in a namespace without using a namespace prefix.

Though we should avoid using it with *std* since it can cause naming conflict with other user-defined objects.


# 2.10 Introduction to the preprocessor

## Translation and the preprocessor
Prior to compilation, the code file goes through a phase known as [translation](https://en.cppreference.com/w/cpp/language/translation_phases), pre-processing to be compile-ready. A code with translation applied is called a **translation unit**.

The most noteworthy of the translation phases involves the **preprocessor**, best thought of as a separate program that manipulates the text in each code file.  
When the preprocessor runs, it scans through the code file (from top to bottom), looing for preprocessor directives.

**Preprocessor directives** are instructions that start with a *#* symbol and end with a newline, NOT semicolon. These telling the preprocessor to perform specific text manipulation tasks. And aren't necessary always understand C++ syntax, they might have their own syntaxing.

### Includes
The preprocessor replaces the *#include* directive with the content of the included file. The included contents are then preprocessed, along with the rest of the file, then compiled.

### Macro defines
The *#define directive* can be used to create a macro, in C++, a **macro** is a rule the defines how input text is converted into replacement output text.

*object-like* and *function-like* macros.
- *Function-like macros* act like functions, and serve a similar purpose. But their use is generally considered dangerous, and almost anything they do can be one by a normal func.
- *Object-like macros* can be defines in one of two ways:
``` cpp
#define identifier
#define identifier substitution_text
```

#### Object-like macros with substitution text
When the preprosser encounters this directive, any further occurence of the identifer is replaced by *substitution_text*.  
The identifier is traditionally typed in all capital letters, with underscores for spaces.
``` cpp
#include <iostream>

#define MY_NAME "Alex"

int main()
{
	std::cout << "My name is: " << MY_NAME;
	return 0;
}
```
These were used as cheaper alternative to constant variables, and should only be seen in legacy code. There are now better way to use accomplish this, using *const* and *constexpr* variables.

#### Object-like macros without substitution text
Any further occurence is removed and replaced by nothing!  
Doesnt' effect other directives or itself.

### Conditional compilation
This directive allows allow you to specify under what conditions something will or won't compile.

#### #ifdef  #ifndef #endif
``` cpp
#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
	std::cout << "Joe\n";	// will be compiled
#endif

#ifdef PRINT_BOB
	std::cout << "Bob\n";	// will be ignored since not defined
#endif

	return 0;
}
```

So essentially, #ifdef is if define then do something. And #ifndef is to check whether an identifer has NOT been #define'd yet.
``` cpp
#include <iostream>

int main()
{
#ifndef PRINT_BOB
	std::cout << "Bob\n";	// will print since no definition
#endif
	return 0;
}
```

Alternatively, `#if defined(PRINT_JOE)` and `#if !defined(PRINT_BOB)` do the same.

#### #if 0
Comment out code blocks: `#if 0` and `#endif`

!After preprocessed, directives will have already been resolved/stripped out of the output before compilation.

### The scope of defines
``` cpp
#include <iostream>

void foor()
{
#define MY_NAME "Alex"
}

int main()
{
	std::cout << "My name is: " << MY_NAME;
	return 0;
}
```
This behaves identically to when #define is outside of foo(), since preprocessor doesn't understand C++'s concepts like functions.

Directives defined in one file don't have impace on other files of the same project.


# 2.11 Header files

## Headers and their purpose
To put all forward declarations in one place and import when needed. This requires the usage of **header file** *.h* extension.

To propagate declaration to code files.

These header files should generally not contain function and variable definitions, so as not to violate the ODR. And exception is for *symbolic constants*.

If a header file is paired with a code file, they should both have the same base name: *add.h* and *add.cpp*.

``` cpp
// add.h
// ommiting header guard for now
int add(int x, int y);

// main.cpp
#include "add."
#include <iostream>
int main()
{
	std::cout << add(3, 4);
	return 0;
}

// add.cpp
#include "add.h"

int add(int x, int y)
{
	return x + y;
}
```
!Code files should have their paired header file *#include* to catch errors at compiler-time instead of linker-time.

## Angled brackets vs double quotes
*<...>* vs *"..."* helps give the compiler a clue as to where it should look for header files.

Angled brackets for head file we didn't write ourselves. The compiler then will only search for the header in the directories specified by the `include directories`, which are configured as part of the project/IDE/compiler settings and are usually defaulted to the compiler and/or OS.

Double-quotes are for user-defined header files. The compiler will search for them in the current directory, then search in the `include directories`.

## \<iostream.h> and \<iostream>
History reason, old C++ have library with *.h* similar to C, but when ANSI comitee wants to move everything to the *std::* but still want to remain support for old programs. New header files without *.h* were created.

## Header files in other directories
Change *include path* or *search directory* settings in the IDE.

For GCC/G++, `g++ -o main -I/source/includes main.cpp`

## Headers within headers within headers
**Transitive includes**, while header has other headers included in them and being added implicitly.

## The #include order of header files
If written properly, this shouldn't matter (?).
- the paired header file
- other headers from your project
- 3rd party library headers
- standard library headers
And should be sort alphabetically.

## Header file best practices
- Always include header guards.
- Do not defines variables and functions in header files, except global constants.
- Give header file same name as its source code.
- Each header should have a specific job and be as independent as possible. *A.h* for functionality of A and *B.h* for B's.
- Be mindful of which headers you need to explicitly include.
- Every header you write should compile on its own (*#include* any dependency needed).
- Only #include what you need.
- Do not #include *.cpp* files.


# 2.12 Header guards

## Duplicate definition problem
Include header "paste" the file's content more than once cause of #include from multiple files.

## Header guards / Include guard
Basically *conditional compilation*
``` cpp
#ifndef SOME_UNIQUE_NAME
#define SOME_UNIQUE_NAME
// your declarations and certain types of definitions
#endif
```

For even more complex programs, you might still run into problem of the headers included from different directories sharing the same guard name.  
So for even more complex/unique guard naming:
```
<PROJECT>_<FILE\>_H
<FILE>_<LARGE RANDOM NUMBER>_H
<FILE>_<CREATION DATE>_H
```

## #pragma once
Short and less error-prone, but not officially C++. Not globally support for all kind of compilers.


# 2.13 How to design your first program

1. Design step 1: Define your goal
- 1-2 sentence description
- user-facing outcome/goal

2. Design step 2: Define requirements
- Solution's constraints: budget, timeline, space, memory, etc.
- Program's capability
- A single problem may yield many requirements, and the solution isn't "done" until it satisfies them all.

3. Design step 3: Define your tools, targets, and backup plan
- Defining what target architecture and/or OS.
- Determining what set of tools will be used.
- Determining whether you will work-alone or in a team.
- Defining your testing/feedback/release strategy.
- Determining how you will back up your code.
As a new programmer: write for yourselves, alone, on your own system, with one IDE.

4. Design step 4: Break hard problems down into easy problems
**Top down** method of problem solving:
- Break task into multiple substasks, each is individually easier to solve.
- Break those subtasks down further if they are still difficult to solve.
**Bottom up** method:
- Start with listing of easy tasks.
- Construct the hierarchy by grouping them.

5. Design step 5: Figure out the sequence of events
After its structure, time to determine how to link all the tasks.

6. Implementation step 1: Outlining your main function
Pseudo coding.

7. Implementation step 2: Implement each function
- Define the prototype
- Write the function
- Test the function
!Don't implement an entire program. Work on it in steps, testing each step along the way before proceeding.

8. Implementation step 3: Final testing
Test the whole program and ensure it works as intended. Else fix it.

## Some words of advice
- Keep your programs simple to start, small goals.
- Add features over time.
- Focus on one area at a time.
- Test each piece of code as you go.
- Don't invest in perfecting early code.
