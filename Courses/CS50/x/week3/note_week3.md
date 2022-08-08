# Algorithms
- efficiency
- reusability

## Running time
- big o notation: O
- n    n/2    log2(n)
- *upper bound*: O notation / worst case: O(n^2), O(n.log(n)), O(n), O(log(n)), O(1)
- *lower bound*: big omega / best case
- big theta: if upper = lower bound

# Searching
## Linear search
- searching 1 by 1 from either left/right
```
for i from 0 to n-1
    if something
        return true
return false
```
    O(n) Omega(1)

## Binary search
- used on a sorted list
```
divide by half, search in middle
  if >
    search right half
  else
    search left half
```
    O(log(n)) Omega(1)

- **reminder: string is not a date type in C, so no compare strings with ==, use strcmp() instead**

# Data structures
- defining a new *struct(ures)*, named person
  adding "relation" between data types/variables
- !! is not object-oriented, since this is C, and struct is **not** object/class. Class can also store function in them while in C it is not conventional
- incapulated
``` c
typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "456";

    people[1].name = "David";
    people[1].number = "123";
}
```

# Sorting

## Selection sort
```
loop through the whole array n
    find the smallest/largest first
    swap with the first/last element
repeat with array n-1
```
- worst case: n + (n-1) + (n-2) + ... + 1 = ... = O(n^2)
  best case omega(n^2), so actually theta(n^2)

## Bubble sort
- smallest/largest numbers will slowly *bubble* up to be the last element
```
looping through array n
    compare the 2 neighbouring elements
	if needed, swap them
    if no swap
	quit
repeat with array n-1
```
- worst case: (n-1) * (n-1) = O(n^2)
  best case: omega(n)

# Recursion
- call function inside itself
``` c
void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    if (n <= 0)
    {
	return;
    }

    draw(n-1);

    for(int i = 0; i < n; i++)
    {
	printf("#");
    }
    printf("\n");

}
```

## Merge sort
```
if one number
    quit
else
    sort left half
    sort right half
    merge 2 halves
```
    O(log(n))
