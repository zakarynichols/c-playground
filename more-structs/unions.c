#include <stdio.h>
#include <stdlib.h>

// Unions

// Size of a union is the largest member sizeof. In this case 4 bytes.
union foo {
    int a, b, c, d, e, f;
    float g, h;
    char i, j, k, l;
};

// Struct equivalent is 36 bytes.
struct bar {
    int a, b, c, d, e, f;
    float g, h;
    char i, j, k, l;
};

union baz {
    float b;
    short a;
};

int main(void) {
    printf("%zu\n", sizeof(struct bar));  // 36
    printf("%zu\n", sizeof(union foo));   // 4
    printf("%zu\n", sizeof(char));        // 1
    printf("%zu\n", sizeof(float));       // 4
    printf("%zu\n", sizeof(int));         // 4

    // Type Punning

    // Since the members of a union share the same memory,
    // writing to one member necessarily affects the others.
    union baz x;
    x.b = 3.14159;
    printf("%f\n", x.b);  // 3.14159
    printf("%d\n", x.a);  // 4048 - Read from what was written to another, you get some weird effects.
    // Under the hood, the object representation for the float 3.14159 was the same
    // as the object representation for the short 4048.
    printf("%f\n", x.a);  // 3.14159
    return 0;
}