#include <stdio.h>

int my_strlen(char *s);

int main(void) {
    // Adding to pointers
    int a[6] = {11, 22, 33, 44, 55, 999};  // 999 is a sentinal value

    int *pa = &a[0];  // Get a pointer to the first element in the array

    int b[3] = {33, 66, 99};  // 99 is a sentinal value

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

    // Changing pointers

    printf("Begin *pa while loop\n");
    while (*pa != 999) {
        printf("%d\n", *pa);
        pa++;  // Move pa to the next int
    }

    printf("Begin *pb while loop\n");
    while (*pb != 99) {
        printf("%d\n", *pb);
        pb++;  // Move pb to the next int
    }

    // Subtracting pointers
    // You can subtract an address to get an earlier address.
    // Can subtract two pointers to get the difference. i.e. how many `int`s are between `*int*s
    // ^^^ Only works with a single array ^^^ - If they point to anything else its undefined behavior

    printf("strlen = %d\n", my_strlen("Hello, world!"));

    return 0;
}

int my_strlen(char *s) {
    char *p = s;  // Start scanning from beginning of string

    // Scan until we find a NUL character
    while (*p != '\0') {
        p++;
    }

    // Return the difference in pointers
    return p - s;
};