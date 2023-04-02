#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("%s\n", "The outside environment");

    for (int i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    return 0;
}