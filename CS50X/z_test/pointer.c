#include <stdio.h>

int main(void)
{
    int s = 255;

    int *p = &s;

    printf("\ns p:\n");
    printf("&s %p\n", &s);
    printf("s %p\n", s);
    /* printf("%p\n", *s); */
    printf("\ns i:\n");
    printf("&s %i\n", &s);
    printf("s %i\n", s);
    /* printf("%i\n", *s); */

    printf("\np p:\n");
    printf("&p %p\n", &p);
    printf("p %p\n", p);
    printf("*p %p\n", *p);
    printf("\np i:\n");
    printf("&p %i\n", &p);
    printf("p %i\n", p);
    printf("*p %i\n", *p);
}
