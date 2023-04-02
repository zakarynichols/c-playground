#include <stdio.h>
#include <stdlib.h>

// These two signatures are the same
void foo(char *a) {}
void bar(char a[]) {}

extern char **environ;  // MUST be extern and MUST be environ to get system env vars

// Use `getenv` for portability unless you need to iterate over all the env vars

// int main(int argc, char **argv, char **env) <-- env - Possible, but way less portable.

// It’s been convenient to think of argv as an array of strings,
// i.e.an array of char *s, so this made sense:
// int main(int argc, char *argv[])
// But, you can also do this.
// A pointer to a value that points to a `char`.
int main(int argc, char **argv) {
    int total = 0;

    // More common for accessing argv with array notation:
    for (int i = 1; i < argc; i++) {  // Start at 1, the first argument
        int value = atoi(argv[i]);    // Use strtol() for better error handling

        total += value;
    }

    printf("%d\n", total);

    total = 0;

    // Trick to get the compiler to stop warning about the
    // unused variable argc.
    // (void)argc;

    // Not as common:
    for (char **p = argv + 1; *p != NULL; p++) {
        int value = atoi(*p);  // Use strtol() for better error handling

        total += value;
    }

    printf("%d\n", total);

    for (char **p = environ; *p != NULL; p++) {
        printf("%s\n", *p);
    }

    // Or you could do this:
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}