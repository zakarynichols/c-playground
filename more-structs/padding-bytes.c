#include <stdio.h>

struct foo {
    int a;
    char b;
    int c;
    char d;
};

int main(void) {
    // a + b + c + d does not equal the size of the struct containg them.
    printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));  // 10
    printf("%zu\n", sizeof(struct foo));                                       // 16
    // Compiler adds 16 bytes of padding to be more performant.
    // Can't be sure of padding. Don't assume.
}