#include <stddef.h>
#include <stdio.h>

struct foo {
    int a;
    char b;
    int c;
    char d;
};

int main(void) {
    // Can use `offsetof` to get number of padding bytes the compiler will inject:
    printf("%zu\n", offsetof(struct foo, a));  // 0
    printf("%zu\n", offsetof(struct foo, b));  // 4
    printf("%zu\n", offsetof(struct foo, c));  // 8
    printf("%zu\n", offsetof(struct foo, d));  // 12
}