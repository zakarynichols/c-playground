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
}