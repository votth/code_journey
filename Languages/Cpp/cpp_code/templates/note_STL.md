# STL - Standard Template Library

Generic types in C++: Templates

C++ enables generic programming by means of special constructs called **Templates**.
``` cpp
template <typename T>
T area(T& a, T& b) {
	T result = a * b;
	return result;
}

main(int argc, char *argv) {
	int areaX = area<int>(5, 10);
	double areaY = area<double>(5.5, 10);
}
```

Components of STL
- containers
- iterators
- algorithms: `<algorithm>`
- functors - function objects: `<functional>`

---

# Containers
Objects that handle a collection of other objects (elements) implementing a well-defined data structures. E.g. vectors, stacks, queues, maps, pairs

Types of containers:
```
		|
	-----------------
	|		|
    sequence	    associative
			|
		-----------------
		|		|
	ordered			unordered
```

Elements are actually stored in *sequence* and can be accessed by their position/index  
while *associative* holds notion of pairs (key-value):
- vector, stack, queue, list, deck, array
- associative: set, map; multi- set and map (dup. keys allowed)
	- ordered: balanced binary tree
	- unordered: hash table

## Vectors
Dynamic array  
Stored contiguously  
Storage is handled automatically, being expanded and contracted as needed (double the previous space)  
Usually occupy more space than static arrays, allocated memory for future growth

Some important functions:
- size(), capacity(), max\_size(): no. of stored elem., actual space allocated, max possible storage
- =, [], at(): assign, access index, access index and triggers "out of bound" error if happens
- front(), back()
- shrink\_to\_fit(): return unused allocated memory
- empty(): if container is empty (no element)
- begin(), end(), rbegin(), rend(): all of these return an iterator, "r" is "reverse traversal"; begin points to first element, end points to the space after last element
- insert(), end():
	- insert(v.begin(), {value}) or insert(v.begin(), {start iterator}, {end iterator}) (e.g. iterator of another container)
	``` cpp
	// #include <list>
	list<int> ll = {-100, -200, -300};
	v.insert(v.begin(), ll.begin(), ll.end());
	```
	- erase() at a position or arange [it1, it2) - it1 is included while it2 is not
- push\_back(), pop\_back()

## List
Doubly Linked list: std::list<*type*>  
forward\_list<*type*>

Optimized for rapid insert and delete operations  
Elements are stored non-contiguously
Doesnt' support random access
Bidirectional iterators (1 dir for std::forward\_list)

To traversal: it++

clear(): empty the container  
insert(it, value)  
erase() vs remove(): by position vs by value

``` cpp
#include <list>
list<int> n = { 0, 1, 2, 3 };

void print_list(list<int>& ll) {
	for(list<int>::iterator it = ll.begin(); it != ll.end(); ++it)
		std::cout << *it << "\t";
	std::cout << "\n";
}
```

## Deque
Double-ended queue: can push and pop from both ends, not stored continuously in the memory but multiple chunks of data


# Container Adapters - a template tool
Interfaces taht implement speical functionality on top of Sequence Containers: stack, queue, priority queue

Adapters/Functions(?): push() pop()

Priority Queue:
- always dequeues the element with the highest priority
- performed by an array-based DST called *heap*, underly container is usually *vector*
- `priority_queue(vector<int>; int , {condition})`

## Set - ordered\_ and unordered\_
Model of mathematical set: `{x1, x2, x3, x4}`  
Collection of unique elements that serve as keys themselves

## Map
Set of pairs: `{ (k1:v1), (k2:v2), (k3:v3) }`  
