#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int i = 20;

    float f = 3.14;

    char *s = "Hello world!";

    printf("%s i = %d and f = %f\n", s, i, f);

    bool x = true;

    if (x) {
        printf("x is true!\n");
    }

    int arithmetic = 0;

    // These shorthands are equivelant to "arithmetic = arithmetic (operator)
    // (value);"
    arithmetic += 3;
    printf("%d\n", arithmetic);
    arithmetic -= 8;
    printf("%d\n", arithmetic);
    arithmetic *= 9;
    printf("%d\n", arithmetic);
    arithmetic /= 2;
    printf("%d\n", arithmetic);
    arithmetic %= 5;
    printf("%d\n", arithmetic);

    int y = 0;

    y += i > 10 ? 17 : 37;
    printf("%d\n", y);

    // The above can be written as:
    if (x > 10) {
        i += 8;
    } else {
        i += 38;
    }

    printf("The number %d is %s. \n", i, i % 2 == 0 ? "even" : "odd");

    int ii = 10;
    int jj = 5 + ii++;  // Compute 5 + 1, then increment ii

    printf("%d, %d\n", ii, jj);  // 11, 15

    ii = 10;
    jj = 5 + ++ii;  // Increment ii, then compute 5 + ii

    printf("%d, %d\n", ii, jj);  // 11, 16

    int a = 999;

    // %zu is the format specifier for type size_t

    printf("%zu\n", sizeof a);       // Prints 4 on my system
    printf("%zu\n", sizeof(2 + 7));  // Prints 4 on my system
    printf("%zu\n", sizeof 3.14);    // Prints 8 on my system

    // If you need to print out negative size_t values, use %zd
}