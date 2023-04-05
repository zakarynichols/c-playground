#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
    printf("%zu\n", sizeof(struct bar));  // 36
    printf("%zu\n", sizeof(union foo));   // 4
    printf("%zu\n", sizeof(char));        // 1
    printf("%zu\n", sizeof(float));       // 4
    printf("%zu\n", sizeof(int));         // 4
    return 0;
}