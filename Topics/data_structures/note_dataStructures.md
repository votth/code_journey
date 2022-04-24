# Definition
A way to store, organize and manage information/data in a way that allow the dev to easily access and modify the values within them.
- Store information
- Access and Manipulate data

# Overview
- Basic:
	- Arrays
	- ArrayLists
- Intermediate:
	- Stacks / Queues
	- LinkedLists / Doubly-LinkedLists
- Advanced:
	- Dictionaries
	- Hash-tables
- Abstract:
	- Trees / Tries
	- Heaps
	- Graphs

# Efficiency
- Speed and Memory Space
- Big-O complexity/notation:
	- "score" data struct in 4 criterias:
		- accessing
		- searching
		- inserting
		- deleting
	- Time complexity equation: input is the size of the dataset know as *n*, and output the number of operations that need to be conducted by the computer before the function finishes.
	- Only using **worst case** when judging
	- 6 most common ones: from best to worst
		- O(1): best, aim of every algo
		- O(log n): considered as "fast"
		- O(n): last "decent" 
		- O(n log n)
		- O(n^2)
		- O(2^n)

# Arrays
- elements, index
- parralel ararys: same number of elem, corresponding values in same pos
- same type of data
- size is fixed and cannot be changed
## Define
- Populate-first `int arr[] = {1, 2, 3};`
- Populate-last `int arr[] = new int[10];`
## 2-dimentional arr
- arr\[row]\[col]
## BigO
- Access: O(1)
- Insert: O(n)
- Search: O(n) (usually since unsorted), O(log n) (for sorted)
- Delete: O(n), since it requires every elements shifting right
## Pros and Cons
- Pros:
	- good for similar contiguous data
	- O(1) access time
	- base and easy to master
- Cons;
	- size is fixed
	- insert and delete are not efficient
	- wasted space

# ArraLists
- AKA: Vector, List
- lots of similarity with Arrays, but also different
	- growing array, size is dynamic
	- doesn't not support populate-first
	- can only store objs
	- comes with prebuilt functions, since it's a class
	- require more memory
## Define
`ArrayList arrList[];`
## Common methods
- Add, Remove, Get, Set, Clear, toArray
	- add(obj) or add(obj, index)
	- remove(index) or remove(obj)
	- get(index): referencing pos
	- set(index, obj): replace
	- clear()
	- toArray(): convert to Array, obj-oriented
## BigO
- Access: O(1)
- Search: O(n)
- Insert: O(n)
- Delete: O(n)

-----------
Sequential data types:
- data can only be accessed in order, by going through other elements
- elemnt is dependent on others

# Stack
- LIFO: last in first out
## Common methods
- Push and Pop
	- push(obj): put obj on top of the stack
	- pop(): remove the top element
- Peek, Contains
	- peek(): get value of top element without pop'ing it
	- contains(obj): search for obj
## BigO
- Access: O(n)
- Search: O(n)
- Insert: O(1)
- Delete: O(1)
## Usage
- recursion
- undo/redo, page-backing

# Queue
- FIFO: first in first out
- Element add to tail, while being removed from the head.
## Common methods
- Enqueue / Dequeue:
	- enqueue(obj): add to tail
	- dequeue(obj): remove from head
- Peek, Contains
	- peek(): return the value at forefront
	- contains(obj): search
## BigO
- Access: O(n)
- Search: O(n)
- Insert: O(1)
- Delete: O(1)
## Usage
- job scheduling
- printer queueing

# LinkedList
- linear data structure, every element is a sepearte obj called *node*, which has 2 parts:
	- data
	- reference/pointer: which points to next node
``` cpp
struct *Node {
	size_t data;
	struct *node_ptr;
}
```
- !! can never go backward
- ptr shows `null` when it doesn't have the next node
## Manipulation
- add/remove head_node
	- point new_node to curr head_node
	- point curr head_node to null
- add/remove mid_node
	- point new_node to a node in middle, point the node before that to new_node
	- point the before_node of removing to the removing's next_node
- add/remove tail_node
	- tail_node points to new_node
	- before_node of tail points to null
## BigO
- Access: O(n)
- Search: O(n)
- Insert: O(n) or O(1)
- Delete: O(n) or O(1)
## Usage
- Backing other data structures: stack (add/remove tail_node), queue (add/remove head_node), etc.
- song list

# Doubly-LinkedList
- able to go back and fort
- node has 3 parts:
	- pre_ptr
	- data
	- next_ptr
- head_node's pre_ptr and tail_node's next_ptr point to null
## Manipulation
- add/remove head_node
- add/remove mid_node
- add/remove tail_node
## BigO
- Access: O(n)
- Search: O(n)
- Insert: O(n) or O(1)
- Delete: O(n) or O(1)
## Usage
- stack-like

-----------
Abstract data types / ADT

# Dictonaries
- AKA:  Maps, Associative Arrays
- Store data in key/value pairs
	- key can be any kind of primitive data: fruits, index, numbers
	- restrictions:
		- key must be unique
		- 1 key can only have 1 value
	- value can be dup, empty value is *nil*
- Hash table
	- store information/data while trying to cut down on number of nil values
	- easily accessible: O(1)
- Hash function: take all keys for a given dict and strategically map them to certain index locations in an array so that they can eventually be retrieved easily
- !! Dicitonaries are built upon *hash tables*, and the key's in our key/value pairs are stored in memory in these hash tables at indexes which are determined by a *hash function*.
- Hash collision: open/closed addressing
	- open: put key in some nil location
	- closed: use LinkedList to chain together keys that has same hash value
## BigO
- Overall hard to consider every keys to have same size, making it's hard to judge the "worst case"
- But in average: all 4 criterias are between O(1)-O(n)
## Pros and Cons
- Pros:
	- option for non-numberical
	- flexibility when making keys/hash
	- speed
- Cons:
	- using a lot of memory space

-----------
Hierarchical data types

# Trees
- An abtract data struct which contains a serires of linked nodes connected together to form a hierarchical representation of information.
- Like a LinkedList where each node has the option to point towards multiple nodes.
- Terminology:
	- vertices: node
	- edge: connection between vertices
	- root: top-most node of the tree
	- child node: node which contains edge connecting it to a node one-level above
	- parent node: any node which has more than 1 child
	- leaf: node that has no child
	- height (of a tree): number of edges on the longest possible path down towards a leaf
	- depth (of a node): number of edges required to get from that node to the root
## Binary search tree
### Restrictions
- Node can have at most 2 children
- For any given node, left child is less than parent while right child is greater
- Node's value is unique
### BigO
- Search: O(log n)
## Usage
- file structure
- family trees
- corp's structure

# Tries
- Used in specific situations
- *flagging*: marking the end of the word by having it point to a "flag", signifying to the computer that the word has ended.
## Restrictions
- Nodes store letters of an alphabet in form of character: helps with re*trie*ve words in the form of strings by traversing down a path of the trie.
## Usage
- auto-complete
- spell-checker
- storing actual dictionaries

# Heap
- Parent node compares to their children in some specific way, being more or less extreme: 
	- less or greater than
	- determines where the data is stored
	- usually depedent on the parent node's value
- Min-heap:
	- Value of root must be minimum amongst all of its children.
	- This fact must be the same recursively for all parent nodes.
- Max-heap: root must be max
## Building heap
- add node starting from most left_side
- compare recursively up and swap if neccessary
- add node to the next left most, going to right_side
- when all children all filled for the level, repeat at lower level
## Remove root node
- remove the root
- replace with node furthest to the right, in the lowest level
- "heapify" fixing the heap to max or min by swapping
## Usage
- HeapSort: sortin algo, takes in list of elements, build heap and remove root continuosly to make a sorted listk
- Priority Queue: advanced data structure which your computer uses to designate tasks and assign computer power based on how urgent the matter is
	- hospital
	- computer proccess scheduling 

# Graphs
- Nonlinear data structure consisting of nodes and edges
	 - finite set of nodes/vertices
	 - nodes are connected by edges
	 - no root, multiple paths
- Notiationally:
	- {1,2,3,4,5,6} are nodes
	- {(5,6),(1,2),...} are pairs node that has common edge
## Types:
	- undirected: lack of arrow, can travel whichever direction along the edges
	- directed: has arrow
	- cyclic: has path from one node leading back to itself
	- acyclic: no path at all
	- unweighted
	- weighted: edges have numerical value, responding to some information you try to convey
### Undirected cyclical heaps with weighted edges
- Dijkstra's shortest path algorithm: compiles a list of the shortest possible path from a source vertex to all other nodes
- Usage: maps, networking
### Unweighted cyclical grapsh (un)directed
- Social media
