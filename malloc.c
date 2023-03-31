#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocating and deallocating
    int *p = malloc(sizeof(int));
    int *pa = malloc(sizeof *pa);  // Works as well since the variable is an `int` type.

    *p = 12;

    *pa = 24;

    printf("%d\n", *p);   // 12
    printf("%d\n", *pa);  // 24

    free(p);
    free(pa);

    // Undefined behavior. Using variables after free-ing.
    printf("%d\n", *p);
    printf("%d\n", *pa);

    return 0;
}