# Definition
- Represeting real-life objects in code form, using a set of rules, ideas, concepts to solve specific type of IRL problems
- An object contains a set of attributes/characteristics (variables, members), while also stores their behaviors (functions, methods), what the object can do.

# Classes
- serves as a model/blueprint for an object
- private by default
- Access modifiers:
	- private: only the class can access
	- protected: can be access by derived classes
	- public: can be access by outsiders too
- Constructor: special method that aids in initiating new object
	- doesn't have a return type
	- same name as the class

# Encapsulation
- Bundle of data within a class
	- preventing access to members from modify or interact with
	- instead, creat methods that can interact with obj's members
- Putting members into the `private:` modifier

# Abtraction
- Hiding complex things after a precedure that makes those same things look simple. Eg: taking a picture: only interface between users
- 'Don't need to know what actualy behind that complex thing to actually know how to use it'
- *abstract* classes - serve as contracts
	- whichever classes decide to sign the contract, they will need to provid a method's implementation
- pure *virtual function*

# Inheritance
- Base/Super/Parent class
- Derived/Child/Sub classes, inherit *public* and *protected* members from the above

# Polymorphism
- Greek for "many forms"
- In code, ability for an object or a method to have many forms - parent class's reference is used to refer to its child class
- *virtual* keyword: check if there's another implementation of this method in the derived classes, if yes, use them instead
- Usage:
	- scaleable?
	- reusability

# Abstract vs Concrete classes
# Super abstract class
https://www.geeksforgeeks.org/difference-between-abstract-class-and-concrete-class-in-java/

# Liskov substitution principle
https://en.wikipedia.org/wiki/Liskov_substitution_principle

# Design pattern

# Dependency injection
https://en.wikipedia.org/wiki/Dependency_injection
- A technique in which an object receives other objects that it depends on, called dependencies.
- The receiving is called *client* while the passed-in/injected objects are *service*s.

# User diagram
