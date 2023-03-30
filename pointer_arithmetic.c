#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *s);
void *my_memcpy(void *dest, void *src, int byte_count);
int compar(const void *elem1, const void *elem2);

// The type of structure we're going to sort
struct animal {
    char *name;
    int leg_count;
};

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
    // Should use strcopy for strings in practice
    memcpy(t, g, 7 * sizeof(char));  // Copy 7 bytes including the NUL terminator. Strings are 1 byte by default so not necessary to use sizeof.

    printf("t copied = %s\n", t);

    int k[] = {11, 22, 33};
    int l[3];

    memcpy(l, k, 3 * sizeof(int));  // Copy 3 ints of data

    printf("l = %d\n", l[1]);  // 22

    /*
        This is possible, but should not do it. Only for demonstration showing how flexible the `void` type is.

        struct antelope my_antelope;
        struct antelopy my_clone_antelope;
        memcpy(&my_clone_antelope, &my_antelope, sizeof my_antelope);
    */

    char aa = 'X';

    void *poi = &aa;  // poi points to 'X'
    char *q = poi;    // q also points to 'X'

    // printf("%c\n", *p);  // ERROR--cannot dereference void*!
    printf("%c\n", *q);  // X

    // Let's build an array of 4 struct animals with different
    // characteristics. This array is out of order by leg_count, but
    // we'll sort it in a second.
    struct animal animals[4] = {
        {.name = "Dog", .leg_count = 4},
        {.name = "Monkey", .leg_count = 2},
        {.name = "Antelope", .leg_count = 4},
        {.name = "Snake", .leg_count = 0}};

    // Call qsort() to sort the array. qsort() needs to be told exactly
    // what to sort this data by, and we'll do that inside the compar()
    // function.
    //
    // This call is saying: qsort array a, which has 4 elements, and
    // each element is sizeof(struct animal) bytes big, and this is the
    // function that will compare any two elements.
    qsort(animals, 4, sizeof(struct animal), compar);

    // Print them all out
    for (int i = 0; i < 4; i++) {
        printf("%d: %s\n", animals[i].leg_count, animals[i].name);
    }
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

// Sample memcpy for `char` types
void *my_memcpy(void *dest, void *src, int byte_count) {
    // Convert void*s to char*s
    char *s = src, *d = dest;

    // Now that we have char*s, we can dereference and copy them
    while (byte_count--) {
        *d++ = *s++;  // ++ moves to the next byte after assignment
    }

    // Most of these functions return the destination, just in case
    // that's useful to the caller.
    return dest;
}

// This is a comparison function called by qsort() to help it determine
// what exactly to sort by. We'll use it to sort an array of struct
// animals by leg_count.
int compar(const void *elem1, const void *elem2) {
    // We know we're sorting struct animals, so let's make both
    // arguments pointers to struct animals
    const struct animal *animal1 = elem1;
    const struct animal *animal2 = elem2;

    // Return <0 =0 or >0 depending on whatever we want to sort by.

    // Let's sort ascending by leg_count, so we'll return the difference
    // in the leg_counts
    if (animal1->leg_count > animal2->leg_count)
        return 1;

    if (animal1->leg_count < animal2->leg_count)
        return -1;

    return 0;
}