# Memory
- finite amount of memories
- 512MB 1GB 2GB 4GB 8GB 16GB etc.
- cs50.ly/art

# RGB

    - black : RGB  0  -  0  -  0  #000000
    - white : RGB 255 - 255 - 255 #FFFFFF
    - red   : RGB 255 -  0  -  0  #FF0000
    - green : #00FF00
    - blue  : #0000FF

# Hexadecimal
    0 1 2 3 4 5 6 7 8 9 A B C D E F
- *base-16*
- from 00 to FF
- maximum number: 16 x 15 + 1 X 15 = 240 + 15 = 255 (same 255 of the RGB)

- translating hexadec into binary
    FF = 1111 1111
    or we can consider that the first digit of hexadec is the first 4 digit of binary
    so in a sense, it still uses the same amount of memory, byte

# Memory addresses
- using hexadecimal 0-F
- not just plain 0 1 2 3 since it might confuses with decimal, therefore we add 0x in front, eg.
    0x0    0x1    0x2    ...    0xA    0xB     ...    0x18    ...
``` c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n", n);
}
```

# Pointers
- is a variable that stores address of some value / location / the specific bytes that value is stored
- !! int\* px, py, pz;
    - will create 1 pointer named px and 2 variables
    - write like this instead to avoid confusion: int \*px, py, pz;
```c
int *p = &n

printf("%p\n", p);  // doesn't need the *
		    // since the "int *" is the syntax for declaring a pointer
		    //the 'p' is still its actual name, not *p

printf("%i\n", *p); // while here so called "dereference operato"
		    // the *p actually printing out the stored value in the pointer 'p'

printf("%p\n", &n); // is also sufficient to print address
		    // the pointer/address will almost always changing
		    // since each time running the program,
		    // it might be ran on a different memory's location
		    // cause it's not the only program/process that's being ran
```
    store address of the n variable to *pointer* p

- pointer to pointer is possible but not very common in C, maybe in Python
- pointers are usually 32- or 64-bit, it's used to be smaller but devices are so advanced with loaded of memory now

- !! it's possible to poke around memory addresses that aren't belong to your program
    - stackoverflow
    - bufferoverflow: using more / going over array's index
    - segmentation fault: going too fall in an array, overall touching memory locaiton that you shouldn't have

## String in memory
    string s = "Hi!";
- s is basically a pointer pointing to the location of "H", the first character of the "string"
- and any characters after "H" just have "H"'s address ++
    char *s = "Hi!";
- \0 at the end
    1. so if you do
    ``` c
    string s = "Hi!";
    string t = "Bye!";

    if (s == t)
    {
	printf("Same\n");
    }
    ```
    - s == t will just compare the memory's location, not the so-called 'string' value
    - since "string s" is just "char \*s"

    2. string t = s
    ``` c
    string s = "hi!";
    string t = s;

    t[0] = toupper(t[0])

    printf("%s\n", s);
    printf("%s\n", s);
    ```
    - will print the same thing, because here t (which is a pointer) = s will point to the same location s is pointing
    essentially changing the value at that address's location

- **name of an array is also a pointer**

``` c
int main(void)
{
    string s = "Hi!";
    char *p = &s[0];

    printf("%p\n", p);
    printf("%p\n", s);
}
```
    this will yield the same result

# Pointer arithmetic
``` c
#include <stdio.h>

int main(void)
{
    char *s = "Hi!";
    
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
```

# Dynamic memory allocaiton
## malloc
- memory allocation: 
    - is a funciton that takes number as input
    - telling the OS to allocation how many bytes of memory
    - return the first bytes of the allocated memory
## free
- hand back the "borrowed" memory through *malloc*
- example for copying string
``` c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1); // +1 for the trailing \0

    // malloc is prone to error, if for example there's no free memory
    if (t == NULL)
    {
	return 1; // to specify there's and error
    }

    // using for like this is better optimized than "i < strlen(s) + 1
    // for (int i = 0, n = strlen(s) + 1; i < n; i++)
    // {
    //	    t[i] = s[i];
    // }

    strcpy(t, s);

    printf("%s\n", t);

    free(t);
}
```
## example
``` c
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 13; // this line is bad
	     // y hasn't been assigned to any memory location yet
	     // causes "segmentation fault"
```

# valgrind command
- return memory-related bugs
    -{number} of bytes in {number} blocks are definitely lost, or memory leak: didn't use free() somewhere
    - invalid write of size {number}: bufferoverflow

# Garbage values
```c
int scores[3];

for (int i = 0; i < 3; i++)
{
    printf("%i\n", scores[i]);
}
```
    will print out garbage values, values that you don't want or doesn't make sense, that might be left from other processes, completely random
    happens because scores[] isn't assigned any value

- **could be a potential security error**: since it might print out a passcode since those "garbages" can be anything

# swap.c
- careful of *local variables* while passing values between functions
``` c
int main(void)
{
    int x = 1, y = 2;
    swap(x, y);

    printf("x: %i, y: %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```
    this will not swap x and y

``` c
int main(void)
{
    int x = 1, y = 2;
    swap(&x, &y); // change here too to be address of variable

    printf("x: %i, y: %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```
    use pointer instead

- sidenotes: the values in a, b and tmp are still there, and become "garbages"

# Stack and Heap
```
		machine code

		global variables

		heap *down arrow*
		
		
		
		stack *up arrow*
```
 using too much stack memory (create variables, functions) or heap memory (calling malloc without free'ing) will lead to them "touching" (since arrows point to each other) causing what is called **stackoverflow**

# scanf();
```c
int x;
scanf("%i", &x);

// "strange" thing with 'string'
char *s;
scanf("%s", s);
printf("%s\n", s); // will print out (null) since *s hasn't been allocated any memory yet

char s[4];	   // even with this, the program runs into the trouble of if s is too long and exceeds the allocated value (4) causing "segmentation fault"
 ```

# File Input / Output 
## fopen()
- open file for either read (r), write (w) or append (a)
    ``` c
    FILE \*ptr = fopen(<filname>, <operation>);
    ```
    > operation: "r", "w", "a"
## fclose()
- close the opened file after finish using
    ``` c
    fclose(<filename>);
    ```
## fgetc()
- reads and returns the next character from the file pointed to
- must be used on a file opened with "r"
    ```c
    // char ch = fgetc(<file pointer>);
    
    char ch;

    while ((ch = fgetc(ptr)) != EOF)
    {
	printf("%c", ch);
    }
    ```
	- similar to "cat" from Linux
	- EOF = end of file
## fputc()
- writes a single character to the opened "w" file
    ``` c
    // fputc(<character>, <file pointer>);

    while ((ch = fgetc(ptr)) != EOF)
    {
	fputc(ch, ptr2);
    }
    ```
	similar to "cp" from Linux
## fread()
- reads \<qty> units of size \<size> from the file pointed to (\<file pointer>) 
- and stores them in memory in a buffer (usually an array) pointed to by \<buffer>
    ``` c
    // fread(<buffer>, <size>, <qty>, <file pointer>);

    int arr[10];
    fread(arr, sizeof(int), 10, ptr);

    double *arr2 = malloc(sizeof(double) * 80);
    fread(arr2, sizeof(double), 80, ptr);
    free(arr2);

    char c;
    fread(&c, sizeof(char), 1, ptr); // pay attention to the ampersand
    ```
## fwrite()
- syntax similar to fread(), but instead of reads, it writes to file
    ``` c
    // fwrite(<buffer>, <size>, <qty>, <file pointer>);
    ```
## Others function from \<stdio.h>
- fgets() and fputs(): working with string
- fprintf() : write a formatted string to file
- fseek()   : rewind or fastforward within a file
- ftell()   : returns the byte value of the file pointer's position
- feof()    : tells whether you've read to the end of a file
- ferror()  : indicates whether an error occurs with the current-working file
- etc.

# File formats
## Images
- grid of dots/*pixels*, each of which can be different color
- colors
    - simplest is 0-1 for black-white
    - more commonly support 24-bit color, meaning uses 24 bits per pixel
	    - 8 bits for red, 8 for green, 8 for blue, the so-called RGB
	    - value for each R G or B ranging from either decimal 0-255 or hexadec 0x00-0xff, the higher the more of that color
	    - if values of R G B are equal, it's the shades of white-gray-black
    - BMP support 1- 4- 8- 16- 24- 32-bit color
### BMP
- bit map
- BMP more technical/in-depth
    1. *metadata* has informaiton like image's height, width etc. which essentially consists of 2 headers:
	    - 14-byte of BITMAPFILEHEADER
	    - 40-byte of BITMAPINFOHEADER
    2. after the metadata is the actual bitmap's pixels
	    - triples of an array of bytes == triples of 8bits, each for a double-digit 00-ff hexadec (since each hexadec digit is 4bits)
	    - reverse to the common RGB, meaning BMP stores them as BGR
	    - sometimes BMPs even store the image's first row at EOF
### JPEG
- image file extension
- every JPEGs start with these 3 bytes: 0xFF 0xD8 0xFF
- 4th bye: 0xe0 0xe1 0xe2 ... 0xee 0xef - or the byte first 4 bits are 1110
    - ofc there're others data that might start with this pattern too
- digital cameras tend to store photographs contiguously on memory cards: start of JPEGs usually demark end of another
- FAT file system has "block" of 512B
    - 1MB (1,048,576) byte photo takes 1 block
    - 1-byte-less 1MB photo also takes 1 block, just not use the whole 512B fully, leaving *slack space*
    - check those "slack space" for remnant of sus. data
	    - for a new card, these "slack space" are *zeroed*: filled with 0s
### Images filtering
#### Grayscale
- Values of R G B have to be equal
- when converting to grayscale
    - calculate the average value of RGB
    - change them to that so the pixel will have a gray-shade color
    - doing so keeps the same-same brightness/darkness
#### Sepia
- old-school look
- converting
    - an example of the algorithm
    ```
    sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    ```
    - round to nearest integer floor()
    - cap at 255
#### Reflection
- swap pixels around, pixels on left go to right and vice versa
- their original values should be retain

#### Blur
- There are a number of ways to create the effect of *blurring* or *softening* image
- one of the ways is "blur box"
    - taking each pixel and for each color value
    - give it a new value
    - which is, the average value of all pixels that are within 1 row and column of the original pixel (forming a 3x3 box) **including the original pixel**

## Audio
### WAV
- common file format for representing audio
- store audio as a sequence of “samples”: numbers that represent the value of some audio signal at a particular point in time

- WAV files begin with a 44-byte “header” that contains information about the file itself, including the size of the file, the number of samples per second, and the size of each sample
- After the header is a sequence of samples, each a single 2-byte (16-bit) integer representing the audio signal at a particular point in time.

- !! scaling each sample with a factor has the effect of changing the value, for example 2.0 would double the volumn while 0.5 would cut it in half
``` c
#include <stdint.h> // allow us to declare precisely the size of a type
		    // in bits and sign (signed or unsigned = negative or positive)

int main(void)
{
    uint8_t header_byte;
    int16_t sample_size;
}
```
