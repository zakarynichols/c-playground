#include <stdio.h>
#include <string.h>

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

    // Array pointer equivalence
    printf("Array pointer equivalence\n");

    int c[] = {11, 22, 33, 44, 55};

    int *pc = c;  // p points to the first element of a, 11

    // Print all elements of the array a variety of ways:

    for (int i = 0; i < 5; i++)
        printf("c[i] = %d\n", c[i]);  // Array notation with c

    for (int i = 0; i < 5; i++)
        printf("pc[i] = %d\n", pc[i]);  // Array notation with pc

    for (int i = 0; i < 5; i++)
        printf("*(c + i) = %d\n", *(c + i));  // Pointer notation with c

    for (int i = 0; i < 5; i++)
        printf("*(pc + i) = %d\n", *(pc + i));  // Pointer notation with pc

    for (int i = 0; i < 5; i++)
        printf("*(pc++) = %d\n", *(pc++));  // Moving pointer pc
    // printf("%d\n", *(a++));    // Moving array variable a results in an error

    // Array/Pointer Equivalence in Function Calls
    char m[] = "Mother nature";
    char *w = "Wombats";

    printf("pass a char[]: %d\n", my_strlen(m));
    printf("pass a pointer %d\n", my_strlen(w));

    // Void pointers
    char g[] = "Goats!";
    char t[100];
    memcpy(t, g, 7);  // Copy 7 bytes including the NUL terminator

    printf("t copied = %s\n", t);

    return 0;
}

// This function can be passed an array or pointer
int my_strlen(char *s) {
    char *p = s;  // Start scanning from beginning of string

    // Scan until we find a NUL character
    while (*p != '\0') {
        p++;
    }

    // Return the difference in pointers
    return p - s;
};