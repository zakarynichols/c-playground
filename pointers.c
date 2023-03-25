#include <stdio.h>

void increment(int *p);

int main(void) {
    int i;
    int *p;  // NOT a dereference--this is a type "int*"

    p = &i;  // p now points to i, p holds address of i

    i = 10;
    *p = 20;  // Using 'indirection operator' to change the value to 20

    printf("i is %d\n", i);
    printf("i is %d\n", *p);

    int a = 10;
    int *b = &a;  // note the address-of operator; turns it into pointer to a

    printf("a is %d\n", a);        // 10
    printf("a is also %d\n", *b);  // 10

    increment(&a);

    printf("a is now %d\n", a);   // 11
    printf("b is now %d\n", *b);  // 11

    int s = 0;
    scanf("%d", &s);  // scanf dereferences the pointer to modify the variable it points to
    printf("s is %d\n", i);
}

void increment(int *p) {
    *p = *p + 1;
}