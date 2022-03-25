# Data structures
## arrays
- problem: adding value to a fully-filled array
    - copy to a new, longer array
    - but slow runtime with big data
    - potentially will meet the same problem again
- using *list* instead?
``` c
    // int list[3];    // got put in 'stack' memory
    // Dynamically assign array of size 3
    int *list = malloc(3 * sizeof(int)); // 'heap' memory
    // by using malloc, you're opened to the possibility of asking for more memory
    if (list == NULL)
    {
	return 1; // not enough memory
    }

    *list = 1;		// same as list[0] = 1
    *(list + 1) = 2;	// not really user-friendly
    *(list + 2) = 3;

    // some other code, time passes bla bla

    // list = malloc(4 * sizeof(int));
    // using this is wrong
    // you lost pointer to the old memory, and it is still 'opened', instead do
    // Create a new array then copy list over to tmp
    int *tmp = malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
	tmp[i] = list[i];
    }
    // add in the new value
    tmp[3] = 4;
    // free the old list's location and point it to the new one
    free(list);
    list = tmp;
    // print out the list
    for (int i = 0; i < 4; i++)
    {
	printf("%i\n", list[i]);
    }
    // need to free "again" since list is now pointing at tmp's memory space, this will also "free" tmp's malloc so either free-ing 'list' or 'tmp' is enough
    free(list);
    return 0;
```
- another/better approach, using realloc
``` c
    int *tmp = realloc(list, 4 * sizeof(int));

    /* what this will replace
    int *tmp = malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
	tmp[i] = list[i];
    }

    free(list);
    */
```
- new-ish syntax
    - struct : create your own structure of data, like a person, has name, bday, age
    - . (dot): access the variable in struct
    - * (star): pointer <> dereference
	    - shorthand of . and *: ->
## linked-list
- link "separated memory spaces"
    - for example with the above problem of array
	- now by using *list*
	- its last element, list[2] can now *point* to another allocated memory to have list[3] (?)
	    - more technical: asking for a +1 malloc in your list, so that 'last element' can now store the address of the separated *link*/list
	    - last element: should have NULL/0x0 as its "next linked address", which is non-exist
``` c
typedef struct
{
    int number;
    node *next;
}
node;
// but that will get us into trouble, since C's complier will freak out when it see "node *next;" "what is this 'node'?!" while it's only declared 2 lines below
// therefore correct syntax is
```
``` c
typedef struct node // typedef helps we define a name for the struct right away
{
    int number;
    struct note *next; // 8-bit, so actually is using more memory, but decreases runtime
}
node;

node *list = NULL; // is a good practice to do, since it won't be considered as a "garbage value"

node *n = malloc(sizeof(node));
if (n != NULL)
{
    (*n).number = 1; // go to the address at n then set its number to 1
    n->number = 1;  // similar purpose to the above
    n->next = NULL; // if there isn't anything after it
}

list = n; // to actually initialize my actual 'list' and 'n' similar to the above section 'tmp'
```

### **recap**
``` c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // list of size
    node *list = NULL;

    // add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
	return 1;
    }
    n->number = 1;
    n->next = NULL;

    // update list to point to new node
    list = n;

    // add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
	free(list);
	return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
	free(list->next); // be very careful of the free-ing order
	free(list);
	return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // print numbers
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
	printf("%i\n", tmp->number);
    }

    // free list, dropping node from start to end
    while (list != NULL)
    {
	// retain the 'next node' of 'head node'
	node *tmp = list -> next;
	// free the now 'head node'
	free(list);
	// 'next node' is now 'head node'
	list = tmp;
    }

    return 0;
}
```
### search, insert
- search:
    - linear: O(n)
    - since we actually only remember the address of *list*, so it requires to go 1-by-1 with list->next
- insert:
    - depends
    - ordered list: O(n)
    - whatever list: O(1), add it directly to the last node

- lost the ability of binary searching

## trees
### binary search trees
- binary tree
    - left child is smaller while right child is bigger than the parent node and this is true recursively
	    - you might create an unbalanced bin.tree with bad code, and will accidentally create a linked-link instead
    - gained back the binary search but using more memory
``` c
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;
```
- search code
``` c
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
	return false;
    }

    if (number > tree->number)
    {
	return search(tree->right, number);
    }
    else if (number < tree->number)
    {
	return search(tree->left, number);
    }
    else // if (number == tree->number)
    {
	return true;
    }
}
```

## hash tables
- "swiss-army knifes"
- hash table structure
    - array of index, storing *bucket*
    - buckets are linked-lists to store data with same indexing 
- hash function: deciding where in the array will a data goes
- eg: name table
    - array: of 0-26 for storing A-Z
    - buckets: people with the same starting alphabet
    - maybe too many people has H starting name, devide it further Ha Hb Hc etc. = increasing the array
	    - will consume a lot more memory and also has unused hash like Hz which is unavoidable if you want the code to be mathimaticallly correct without micro-managing
	    - benefit in runtime
``` c
typedef struct node 
{
    char word[LONGEST_WORD + 1]; // +1 for \0 NUL
    struct node *next;
}
node;

node *hash_table[NUBMER_OF_BUCKETS];
```
- searching: O(n)

## tries
- retrival
- trees but nodes are arrays
- trie (this is correct spelling) is like a roadmap to your wanted *keys*
``` c
typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABETS];
}
node;
```
- search: O(1), while using a lot-lot of memory

## abtract date structure
- queues - FIFO first in first out
    - enqueue: add
    - dequeue: remove
- stacks - LIFO/FILO last in first out / first in last out
    - push
    - pop
- dictionaries ~ hash

# Summary
## Arrays
- Pros
    - loopup is great, random access with constant time O(1) with index
    - relatively easy to sort
    - relatively small size-wise
- Cons
    - stuck with a fixed size, no flexibility
    - insertion is bad: lots of shifting to fit an element in the middle
    - deletion is bad: lost of shifting to move the elements up to refill the removed element
## Linked lists
- Pros
    - insertion is easy: without order, just attach new node to the had
    - deletion is easy: once you found the element, then relink
    - relatively small size-wise: definitely bigger than arrays
- Cons
    - lookup is bad: have to rely on linear search O(n)
    - relatively difficult to sort: unless you're willing to insert in order, by giving up on "just attach to head"
## Hash tables
- Pros
    - insertion: 2-step process, hash through hash function then add
    - deletion is easy: once you found the element
    - lookup is average: better than linked lists, benefit of real-world constant factor (?) - 'n' link lists vs 1 link list of length n
- Cons
    - not ideal if sorting is the goal - just use array
    - can run the gamut of size: consume a lot-lot of size
## Tries
- Pros
    - insertion can be complex (for human): a lot of dynamic memory allocation is involved, but get easier as you go
    - deletion is easy: constant time lookup and just remove node then relink
    - lookup is fast: almost as fast as array
    - already sorted as you build trie
- Cons
    - rapidly becomes HUGE even with small size data
