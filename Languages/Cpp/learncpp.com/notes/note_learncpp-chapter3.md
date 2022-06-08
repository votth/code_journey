# 3.1 Syntax and semantic errors
Two categories for errors: syntax and semantic (logic) errors.

A **syntax error** occurs when you write a statement that is not valid according to the grammar of the C++ language. This includes: missing semicolons, using undeclared variables, mismatched parenthesises or braces, etc...  
These will generally be caught by the compiler and generate warnings or errors.

A **semantic error** occurs when a statement is syntactically valid, but does not do what the programmer intended.  
Sometimes this will cause the program to crash, eg. division by zero; more often it will produce wrong value or behavior. The compiler won't catch these.


# 3.2 The debugging process
- Find the root cause of the problem (line of code that's not working)
- Ensure you understand why the issue is occuring
- Determine how you'll fix the issue
- Repair the issue causing the problem
- Retest to ensure the problem has been fixed and no new problems have emerged


# 3.3 A strategy for debugging

## Finding problems via code inspection
Drawbacks of this approach:
- A lot of lines of code to look at: boring, multiple places of errors, complexity
- Code's behavior might not give many clues to the exact position
- Bugs caused by bad assumptions are hard to spot and fix, since it's entirely possible that you will make the same bad assumption

## Finding problems by running the program
Watch the behavior of the program while it runs, and try to diagnose the issue:
- Figure out how to reproduce the problem
- Run the program and gather information to narrow down where the problem is
- Repeat the prior step until you find the problem

### Reproducing the problem
First and most important step, since it's extremely hard to find an issue unless you can observe it occurring.

Sometimes, it can be trivia, like program crashing in the same place every time you run it, while other times, the problem might only occur on certain computers, or in particular circumstances (different user's input). It's advisable to have a reproduction steps list.

The **reproduction steps** are a list of clear and precise steps that can be followed to cause an issue to recur with a high level of predictability. The goal is to be able to cause the issue to reoccur as much as possible for us to find clues of the problem.

### Homing in on issues
Once we have reasonably reproduce the problem, the next step is to figure out where in the code the problem is.
- Encircle a general area where the first symptom occurs
- Making educated guesses, that helps we closing in on the problem


# 3.4 Basic debugging tactics

## Commenting out your code

## Validating your code flow
For example, calling functions too many/few times: placing statement at the top of func to print its name, helps telling when the functions is called, how many times.  
Using of `std::cerr` is better than `std::cout`, because `cerr` is unbuffered, output will happen instantly. It also helps make clear that the information being output is for an error case.  
Added tmp debug statement could be left not-indent, to makes them standout better.

## Printing values
Drawbacks:
- clutter your code
- clutter output of the program
- must be removed after you're done with them, being non-reusable
- adding then removing after might introduce new bugs


# 3.5 More debugging tactics

## conditionalizing your debugging code
Using preprocessor directives:
``` cpp
#include <iostream>

#define ENABLE_DEBUG // comment out to disable debuggign

int getUserInput()
{
#ifdef ENABLE_DEBUG
std::cerr << "getUserInput() called\n";
#endif
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}
int main()
{
#ifdef ENABLE_DEBUG
std::cerr << "main() called\n";
#endif
	int x{ getUserInput() };
	std::cout << "You entered: " << x;
	return 0;
}
```

While this solve the problem of adding and removing debug code constantly, or now have them reusable, unfortunately, this clutters the code even more.

## Using a logger
Alternative approach to conditionalizing debugging via a preprocessor is to send your debugging information to a log file.  
A **log file** is a file that records events that occur in software. The process of writing information to a log file is called **logging**.

Advantages:
- avoid clutter caused by mixture of normal and debug output
- logs can be easily sent to other people for diagnosis

Example of a logger tool [plog](https://github.com/SergiusTheBest/plog)
``` cpp
#include <iostream>
#include <plog/Log.h>	// step 1: include the logger hearders
#include <plog/Initializer/RollingFileInitializer.h>

int getUserInput()
{
	PLOGD << "getUserInput() called";

	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	// replace 'debug' by 'none' to temporarly disable debugging
	plog::init(plog::debug, "LogFile.txt"); // step 2: initialize the logger

	PLOGD << "main() called"; // step 3: output to the log as if you were writing to the console

	int x{ getUserInput() };
	std::cout << "You entered: " << x;

	return 0;
}
```


# 3.6 Using an intergrated debugger: Stepping
Useful for examining each individual line of code, can take a long time.  
Some common steps: in, out, over, back
# 3.7 Using an intergrated debugger: Running and breakpoints
Run to cursor, Continue, Start, breakpoint, Set next statement
# 3.8 Using an intergrated debugger: Watching variables
# 3.9 Using an intergrated debugger: The call stack
A list of all active functions that have been called to get to the current point of execution.


# 3.10 Finding issues before they become problems

## Don't make errors
- Follow best pratices
- Don't program when tired
- Understand where the common pitfalls are in a language
- Keep your program simple
- Don't let your functions get too long
- Prefer using the standard library to writing your own code, when possible
- Comment your code liberally

## Refactoring your code
As you add new capabilities to your programs ("behavioral changes"), your functions grow in length, and they get both more complex and harder to understand.  
One way to address this issue is to break a single long function into multiple shorter ones. The process of changining your code structure without changing its behavior is called **refactoring**.

Functions that are longer than one vertical screen worth are considered as long.

## An introduction to defensive programming
Is a practice whereby the programmer tries to anticipate all the ways the software could be misused, either by end-users or by other developers.

## Finding errors fast
Program a little, bit by bit over time. Then test and make sure it works, then adding in more code

## An introduction to testing functions
Write function that "exercise" your code

## An introduction to constraints
Constraints-based techniques involve the addition of some extra code (that can be compiled out in a non-debug build, if desired) to check that soem set of assumptions or expectations are not violated. Eg: *assert* and *static_assert*

## Shotgunning for general issues
Looking for common mistakes with a **static analysis tools**/*linters*
