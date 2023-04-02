#include <stdio.h>

// The C preprocessor includes the file _right here_ just as if we'd typed it ourselves
#include "bar.h"

extern int a;  // Can declare file scope

int main(void) {
    extern int b;  // Can also declare in block scope

    printf("from foo.c = %d\n", a);  // 37, from bar.c
    printa();
    printb();

    a = 99;
    b = 222;

    printf("from foo.c = %d\n", a);  // 99, from bar.c
    printa();
    printb();

    printf("%d\n", add(2, 3));  // 5
}