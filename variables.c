#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int i = 2;

    float f = 3.14;

    char  *s = "Hello world!";

    printf("%s i = %d and f = %f\n", s, i, f);

    bool x = true;

    if (x) {
        printf("x is true!\n");
    }

    int arithmetic = 0;


    // These shorthands are equivelant to "arithmetic = arithmetic (operator) (value);"
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
}