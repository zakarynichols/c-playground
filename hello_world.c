// Pound sign indicates a preprocessor directive and it runs before the compiler.
// There are two steps to compilation, preprocessing and compiling. #include and #define
// are both preprocessor directives. After the preprocessor has run, then the results
// are ready for the compiler to produce assembly or machine code.
#include <stdio.h> // Standard I/O header file. Required to use `printf`.

int main(void) {
    printf("Hello, World!\n");
}

// To create an executable run:
// gcc -o hello_world hello_world.c

// To run the exectuable:
// ./hello_world