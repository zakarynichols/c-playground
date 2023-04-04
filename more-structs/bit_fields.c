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

    // Non-adjacent bit fields

    // A gotcha : C will only combine adjacent bit - fields.
    // If they’re interrupted by non - bit - fields, you get no savings:
    struct baz {             // sizeof(struct foo) == 16 (for me)
        unsigned int a : 1;  // since a is not adjacent to c.
        unsigned int b;
        unsigned int c : 1;
        unsigned int d;
    };

    printf("baz = %zu\n", sizeof(struct baz));  // 16

    // Put all your bitfields together to get the compiler to combine them.
}