# Vector
- or ListedArray, dynamic Array, expandable Array
- methods:
	- Element access:
		- at / front / back: by position
		- operator[]: specified element
	- Iterators:
		- begin() / rbegin()
		- end() / rend()
	- Capacity:
		- capacity()
		- shrink_to_fit()
		- reserver(): to avoid reallocation
	- Modifiers:
		- insert() / erase()
		- push_back() / pop_back()
		- swap()
- complexity
	- random access: O(1), since iterator is usable
	- insert or remove at the end: O(1)
	- insert or remove random: O(n)

``` cpp
#include <iostream>
#include <vector>
int main() {
	// Create a vector containing integers
	std::vector<int> v = { 7, 5, 16, 8 };
	// Add two more integers to vector
	v.push_back(25);
	v.push_back(13);
	// Print out the vector
	std::cout << "v = { ";
	for (int n : v) {
		std::cout << n << ", ";
	}
	std::cout << "}; \n";
}
```

# List
- supports constant time insertion and removal from anywhere within the container.
- fast random access is not supported
- A doubly-linked list VS singly-linked list (std::forward_list), provide bidirectional iteration at the cost of space efficient.
- Methods:
	- Element access: front / back
	- Iterators: same-same as Vector
	- Capacity:
		- empty: check if empty
		- size / max_size
	- Modifiers:
		- push_front / pop_front
		- emplace: construct element in-place
	- Operations:
		- sort
		- unique: remove dups
		- merge: merge 2 sorted lists
		- remove_if
## std::forward_list
- Methods: mostly same as List, with \_after keyword to specify position

``` cpp
#include <algorithm>
#include <iostream>
#include <list>
int main() {
// Create a list containing integers
	std::list<int> l = { 7, 5, 16, 8 };
	// Add an integer to the front of the list
	l.push_front(25);
	// Add an integer to the back of the list
	l.push_back(13);
	// Insert an integer before 16 by searching
	auto it = std::find(l.begin(), l.end(), 16);
	if (it != l.end()) {
		l.insert(it, 42);
	}
	// Print out the list
	std::cout << "l = { ";
	for (int n : l) {
		std::cout << n << ", ";
	}
	std::cout << "};\n";
}
```

# Map
- a sorted associative container that contains key-value pair with unique keys.
- Keys are sorted by using the comparision functions Compare.
- Complexity: logarithmic O(log n)
- Implemented as *red-black tree*
- Methods:
	- Element access:
		- at: specificed element with bonds checking
		- operator[]: access or insert
	- Iterators: same as List
	- Capacity: same as List
	- Modifiers:
		- insert_or_assign: insert new or change already existed key
		- try_emplace: insert in-place if key does not exist, else does nothing
		- extract / merge: extracts or splices nodes from the/another container
	- Lookup:
		- count / find / contains: with specific key
		- equal_range: range of elements matcing spec.key
		- lower_bound / upper_bound: returns an iterator to the first element *not less/greater* than the given key
	- Observers:
		- key_comp
		- value_comp

``` cpp
#include <iostream>
#include <map>
#include <string>
#include <string_view>
void print_map(std::string_view comment, const std::map<std::string, int>& m) {
	std::cout << comment ;
	// C++11 alternative:
	for (const auto& n : m) {
		std::cout << n.first << " = " << n.second << "; ";
	}
	std::cout << '\n';
}
int main() {
	// Create a map of three (strings, int) pairs
	std::map<std::string, int> m { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
	// Print map
	print_map("1) Initial map: ", m);
	// Modify value
	m["CPU"] = 25;  // update an existing value
	m["SSD"] = 30;  // insert a new value
	print_map("2) Updated map: ", m);
	// using operator[] with non-existent key always performs an insert
	std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
	print_map("4) Updated map: ", m);
	// Erase
	m.erase("GPU");
	print_map("5) After erase: ", m);
	// Erase with condition
	std::erase_if(m, [](const auto& pair){ return pair.second > 25; });
	print_map("6) After erase: ", m);
	std::cout << "7) m.size() = " << m.size() << '\n';
	// Clear map
	m.clear();
	std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << '\n';
}
```

# Queue
- FIFO: first in first out
- put new element to the back, remove from the front
- Methods:
	- Element access: front / back
	- Capacity:
		- empty
		- size
	- Modifiers
		- push / pop
		- emplace
		- swap
