#include <stdio.h>

int main(void) {
    int i;
    float f[4];  // Declare an array of 4 floats. Must give a fixed size.

    f[0] = 3.14;
    f[1] = 1.41;
    f[2] = 1.61;
    f[3] = 2.72;

    // Print them all out:

    for (i = 0; i < 4; i++) {
        printf("%f\n", f[i]);
    }
}