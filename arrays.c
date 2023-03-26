#include <stdio.h>

#define COUNT 5

void times2(int *a, int len);
void times3(int a[], int len);
void times4(int a[5], int len);
void double_array(int *a, int len);
void print_2D_array(int a[2][3]);

int main(void) {
    int i;
    float f[4];  // Declare an array of 4 floats. Must give a fixed size.

    printf("%zu\n", sizeof(float[4]));
    printf("%zu\n", sizeof(float));

    f[0] = 3.14;
    f[1] = 1.41;
    f[2] = 1.61;
    f[3] = 2.72;

    // Print them all out:

    for (i = 0; i < 4; i++) {
        printf("%f\n", f[i]);
    }

    size_t len = sizeof(f) / sizeof(float);

    printf("length of array is %zu\n", len);

    // Initialize an array
    int a;
    int b[5] = {1, 2, 3, 4, 5};

    for (a = 0; a < 5; a++) {
        printf("%d\n", b[a]);
    }

    // Can also initialize array with fewer elements
    int c[5] = {1, 2, 3};  // Other elements initialized as '0'

    // Also common to initialize a large array like so:
    int d[100] = {0};  // Which means make the first element 0, and automatically set the rest to 0

    // Can build an array from a specific index
    int e[10] = {0, 11, 22, [5] = 55, 66, 77};  // 0 11 22 0 0 55 66 77 0 0

    // Can use a const expression as well
    int g[COUNT] = {[COUNT - 3] = 3, 2, 1};  // 0 0 3 2 1

    for (i = 0; i < COUNT; i++) {
        printf("%d\n", g[i]);
    }

    // Let C compute the size of the array
    int h[] = {1, 2, 3};  // Leave out the size

    int j[5] = {22, 37, 3490, 18, 95};

    for (i = 0; i < 10; i++) {
        printf("%d\n", j[i]);  // Printing too many elements. Will result in _undefined behavior_
    }

    // Multidimensional arrays
    int row, col;

    // Initialize a 2D array
    int md[2][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}};

    for (row = 0; row < 2; row++) {
        for (col = 0; col < 5; col++) {
            printf("(%d,%d) = %d\n", row, col, md[row][col]);
        }
    }

    // Make a 3x3 identity matrix manually
    int matrix[3][3] = {[0][0] = 1, [1][1] = 1, [2][2] = 1};
    /*
    Builds a 2D array like this:
        1 0 0
        0 1 0
        0 0 1
    */

    // Get a pointer to the first element in an array
    int k[5] = {11, 22, 33, 44, 55};
    int *p;

    // p = &k[0];  // p points to the array
    // Well, to the first element, actually

    // printf("%d\n", *p);  // Prints "11"

    // This is so common in C that a shorthand is allowed
    p = k;  // Same as above for getting the first element in the array

    printf("%d\n", *p);

    // Passing single-dimension arrays to functions
    int x[5] = {11, 22, 33, 44, 55};

    times2(x, 5);
    times3(x, 5);
    times4(x, 5);

    // Changing arrays in functions
    int y[5] = {1, 2, 3, 4, 5};

    double_array(y, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", y[i]);  // 2, 4, 6, 8, 10!
    }

    // Passing multi-dimension arrays to functions
    int z[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    print_2D_array(z);

    // These two are equivalent
    // void print_2D_array(int a[2][3])
    // void print_2D_array(int a[][3])
}

// Passing as a pointer to the first element
void times2(int *a, int len) {
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 2);
}

// Same thing, but using array notation
void times3(int a[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 3);
}

// Same thing, but using array notation with size
void times4(int a[5], int len) {
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 4);
}

void double_array(int *a, int len) {
    // Multiply each element by 2
    //
    // This doubles the values in y in main() since y and a both point
    // to the same array in memory!

    for (int i = 0; i < len; i++) {
        a[i] *= 2;  // We pass an int*, but can still access as a[i]
    }

    // Changes of the array inside this function are visible to the caller
}

// C needs to know all the dimensions except the first
void print_2D_array(int a[2][3]) {
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}