#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocating and deallocating
    int *p = malloc(sizeof(int));
    int *pa = malloc(sizeof *pa);  // Works as well since the variable is an `int` type.

    *p = 12;

    *pa = 24;

    printf("%d\n", *p);   // 12
    printf("%d\n", *pa);  // 24

    free(pa);

    // Undefined behavior. Using variables after free-ing.
    printf("%d\n", *p);
    printf("%d\n", *pa);

    // Error checking
    int *x;

    x = malloc(sizeof(int) * 10);

    if (x == NULL) {
        printf("Error allocating 10 ints\n");
        // do something here to handle it
    }
    printf("x = %d\n", *x);  // 0

    int *y;
    // Common pattern.
    if ((y = malloc(sizeof(int) * 10)) == NULL) {
        printf("Error allocating 10 ints\n");
        // do something here to handle it
    }
    printf("y= %d\n", *y);  // 0

    // Allocating space for an array
    int *pb = malloc(sizeof(int) * 10);

    for (int i = 0; i < 5; i++) {
        pb[i] = i * 5;
    }

    for (int i = 0; i < 5; i++) {
        printf("pb[i] = %d\n", pb[i]);
    }

    free(p);

    // An alternative: calloc()

    // Allocate space for 10 ints with calloc(), initialized to 0:
    int *pc = calloc(10, sizeof(int));

    // Allocate space for 10 ints with malloc(), initialized to 0:
    int *qa = malloc(10 * sizeof(int));
    memset(qa, 0, 10 * sizeof(int));  // set to 0
    return 0;
}
