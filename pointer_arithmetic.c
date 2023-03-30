#include <stdio.h>

int main(void) {
    // Adding to pointers
    int a[5] = {11, 22, 33, 44, 55};

    int *pa = &a[0];  // Get a pointer to the first element in the array

    int b[3] = {33, 66, 99};

    int *pb = b;  // Works just as well

    printf("pa = %d, pb = %d\n", *pa, *pb);  // pa = 11, pb = 11

    printf("pa = %d, pb = %d\n", *(pa + 1), *(pb + 2));  // pa = 22, pb = 99

    // Works the same as array notation i.e. a[0] = 11, b[1] = 66

    for (int i = 0; i < 5; i++) {
        printf("pa = %d\n", *(pa + i));
    }

    for (int j = 0; j < 3; j++) {
        printf("pb = %d\n", *(pb + j));
    }

    return 0;
}