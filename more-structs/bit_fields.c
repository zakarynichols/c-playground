#include <stdio.h>

struct foo {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};

struct bar {
    unsigned int a : 5;
    unsigned int b : 5;
    unsigned int c : 3;
    unsigned int d : 3;
};
int main(void) {
    printf("foo: %zu\n", sizeof(struct foo));  // 16
    printf("bar: %zu\n", sizeof(struct bar));  // 4
}