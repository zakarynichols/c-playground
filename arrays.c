#include <stdio.h>

#define COUNT 5

int main(void) {
    int i;
    float f[4];  // Declare an array of 4 floats. Must give a fixed size.

    printf("%zu\n", sizeof(float[4]));
    printf("%zu\n", sizeof(float));

    f[0] = 3.14;
    f[1] = 1.41;
    f[2] = 1.61;
    f[3] = 2.72;

    // Print them all out:

    for (i = 0; i < 4; i++) {
        printf("%f\n", f[i]);
    }

    size_t len = sizeof(f) / sizeof(float);

    printf("length of array is %zu\n", len);

    // Initialize an array
    int a;
    int b[5] = {1, 2, 3, 4, 5};

    for (a = 0; a < 5; a++) {
        printf("%d\n", b[a]);
    }

    // Can also initialize array with fewer elements
    int c[5] = {1, 2, 3};  // Other elements initialized as '0'

    // Also common to initialize a large array like so:
    int d[100] = {0};  // Which means make the first element 0, and automatically set the rest to 0

    // Can build an array from a specific index
    int e[10] = {0, 11, 22, [5] = 55, 66, 77};  // 0 11 22 0 0 55 66 77 0 0

    // Can use a const expression as well
    int g[COUNT] = {[COUNT - 3] = 3, 2, 1};  // 0 0 3 2 1

    for (i = 0; i < COUNT; i++) {
        printf("%d\n", g[i]);
    }

    // Let C compute the size of the array
    int h[] = {1, 2, 3};  // Leave out the size

    int j[5] = {22, 37, 3490, 18, 95};

    for (i = 0; i < 10; i++) {
        printf("%d\n", j[i]);  // Printing too many elements. Will result in _undefined behavior_
    }
}