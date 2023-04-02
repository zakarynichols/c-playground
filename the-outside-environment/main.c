#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    printf("%s\n", "The outside environment");

    for (int i = 0; i < argc; i++) {
        printf("argc = %d\n", i);
        printf("argv = %s\n", argv[i]);
    }

    printf("%s\n", argc[argv] == NULL ? "true" : "false");

    int total = 0;

    for (int i = 1; i < argc; i++) {  // Start at 1, the first argument
        int value = atoi(argv[i]);    // Use strtol() for better error handling

        total += value;
    }

    printf("%d\n", total);
    return 0;
}