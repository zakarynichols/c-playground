#include <stdio.h>

int a = 37;
int b = 111;

// - Default starts with 0 so no need to initialize it
// - `static` in file scope is only available inside this file
static int foo;

int add(int x, int y) {
    return x + y;
}

void printa(void) {
    printf("a = %d, from file bar.c\n", a);
}

void printb(void) {
    printf("b = %d, from bar.c\n", b);
}

void counter(void) {
    static int count = 1;  // This is initialized one time

    printf("This has been called %d time(s)\n", count);

    count++;
}

int set_foo(int i) {
    foo = i;
    return foo;
}