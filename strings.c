#include <stdio.h>
#include <string.h>

int get_strlen(char *s);

int main(void) {
    // String variables
    char *s = "Hello world";  // Pointer to a char. Actually a pointer to the first character.

    printf("%s\n", s);  // Print with the string specifier 's'

    // String variables as arrays
    char fixed[12] = "Hello world";

    char not_fixed[] = "Hello, world!";

    for (int i = 0; i < 12; i++) {
        printf("%c\n", fixed[i]);  // Print with the character specifier 'c'
    }

    char *char_pointer = "Hello world!";

    for (int i = 0; i < 13; i++) {
        printf("%c\n", char_pointer[i]);  // Can use array notation with char pointers
    }

    // String initializers
    char *immutable = "Hello, world!";  // Mutating is undefined behavior for char pointers
    char mutable[] = "Hello, again!";   // This is a mutable copy that can be changed at will

    mutable[0] = 'z';  // Must use single quotes for a single character

    printf("%s\n", mutable);

    // Getting string length
    char *string_length = "Hello, world!";
    printf("The string is %zu bytes long\n", strlen(string_length));

    // String termination
    char *term = "Hello";  // When using double quotes is "Hello\0" behind the scenes
    printf("%d\n", get_strlen(term));

    // Copying a string
    char x[] = "Hello, world!";
    char *y;

    y = x;  // This makes a copy of the pointer, not a copy of the string!

    y[0] = 'z';

    // But printing x shows the modification.
    // Because x and y point to the same string.
    printf("%s\n", x);

    char j[] = "Hello, world!";
    char k[100];

    strcpy(k, j);  // dest if first and src is second argument. Think of it like k = j

    k[0] = 'z';

    printf("j = %s, k = %s\n", j, k);
}

// Basic example of how built-in strlen works
int get_strlen(char *s) {
    int count = 0;

    while (s[count] != '\0') {  // Single quotes for single character
        count++;
    }

    return count;
}