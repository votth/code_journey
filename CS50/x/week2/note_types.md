# Data types
- bool		1 byte
- char		1 byte
- double	8 bytes
- float		4 bytes
- int		4 bytes
- long		8 bytes
- string	? bytes

- float: %.2f prints out only 2 digits after decimal
    treating division as float: have 1 of the number be converted to float, such as: 3 into 3.0

# Arrays
- store variables with the same types
``` c
int scores[3];

for (int i = 0; i<3; i++)
{
    scores[i] = scanf("%i");
}
```
- string is an array of characters, NUL \0 to end string
    - <string.h>: strlen()
	``` c
	for (int i = 0, n = strlen(s); i < n; i++);
	```
# Command-line arguments
- can't loop it like with within source code
``` c
int main(int argc, string argv[]){}
```
argc: argument count, how many words did the human type?\
argv: argument vector, array of all of the typed words

``` c
#include <stdio.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
	printf("Hello, %s\n", argv[1]);
    }
    else
    {
	printf("Hello, world\n");
    }
}
```
argv[1] because [0] is the program name

# exit status
- status 0 is if things ran successfully, it's automatically ran by c, HOWEVER it is a good practice to add "return 0"

``` c
#include <stdio.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
	printf("Missing command-line argument\n");
	return 1;
    }
    printf("Hello, %s\n", argv[1]);
}
```

# cryptography
- encrypted plaintext, which is called ciphertext
- cipher is used to encrypt
