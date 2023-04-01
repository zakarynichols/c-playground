#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline(FILE *fp);

int main(void) {
    // Allocating and deallocating
    int *p = malloc(sizeof(int));
    int *pa = malloc(sizeof *pa);  // Works as well since the variable is an `int` type.

    *p = 12;

    *pa = 24;

    printf("%d\n", *p);   // 12
    printf("%d\n", *pa);  // 24

    free(pa);

    // Undefined behavior. Using variables after free-ing.
    printf("%d\n", *p);
    printf("%d\n", *pa);

    // Error checking
    int *x;

    x = malloc(sizeof(int) * 10);

    if (x == NULL) {
        printf("Error allocating 10 ints\n");
        // do something here to handle it
    }
    printf("x = %d\n", *x);  // 0

    int *y;
    // Common pattern.
    if ((y = malloc(sizeof(int) * 10)) == NULL) {
        printf("Error allocating 10 ints\n");
        // do something here to handle it
    }
    printf("y= %d\n", *y);  // 0

    // Allocating space for an array
    int *pb = malloc(sizeof(int) * 10);

    for (int i = 0; i < 5; i++) {
        pb[i] = i * 5;
    }

    for (int i = 0; i < 5; i++) {
        printf("pb[i] = %d\n", pb[i]);
    }

    free(p);

    // An alternative: calloc()

    // Allocate space for 10 ints with calloc(), initialized to 0:
    int *pc = calloc(10, sizeof(int));

    // Allocate space for 10 ints with malloc(), initialized to 0:
    int *qa = malloc(10 * sizeof(int));
    memset(qa, 0, 10 * sizeof(int));  // set to 0

    // Changing allocated size with realloc

    // Allocate space for 20 floats
    float *pd = malloc(sizeof *p * 20);  // sizeof *p same as sizeof(float)

    // Assign them fractional values 0.0-1.0:
    for (int i = 0; i < 20; i++) {
        pd[i] = i / 20.0;
    }

    // Now make this an array of 40 elements
    float *new_pd = realloc(pd, sizeof *pd * 40);

    // Check to see if we successfully reallocated
    if (new_pd == NULL) {
        printf("Error reallocing\n");
        return 1;
    }

    // If we did, we can just reassign pd. This pattern is common.
    pd = new_pd;

    // And assign the new elements values in the range 1.0-2.0
    for (int i = 20; i < 40; i++) {
        pd[i] = 1.0 + (i - 20) / 20.0;
    }

    // Print all values 0.0-2.0 in the 40 elements:
    for (int i = 0; i < 40; i++) {
        printf("pd[i] = %f\n", pd[i]);
    }

    // Free the space
    free(pd);

    // Reading in Lines of Arbitrary Length
    // 1. Use of realloc() to grow a buffer as we read in more data.
    // 2. Use of realloc() to shrink the buffer down to the perfect size after we’ve completed the read.

    FILE *fp = fopen("foo.txt", "r");

    char *line;

    while ((line = readline(fp)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    fclose(fp);
    return 0;
}

char *readline(FILE *fp) {
    int offset = 0;   // Index next char goes in the buffer
    int bufsize = 4;  // Preferably power of 2 initial size
    char *buf;        // The buffer
    int c;            // The character we've read in

    buf = malloc(bufsize);  // Allocate initial buffer

    if (buf == NULL)  // Error check
        return NULL;

    // Main loop--read until newline or EOF
    while (c = fgetc(fp), c != '\n' && c != EOF) {
        // Check if we're out of room in the buffer accounting
        // for the extra byte for the NUL terminator
        if (offset == bufsize - 1) {  // -1 for the NUL terminator
            bufsize *= 2;             // 2x the space

            char *new_buf = realloc(buf, bufsize);

            if (new_buf == NULL) {
                free(buf);  // On error, free and bail
                return NULL;
            }

            buf = new_buf;  // Successful realloc
        }

        buf[offset++] = c;  // Add the byte onto the buffer
    }

    // We hit newline or EOF...

    // If at EOF and we read no bytes, free the buffer and
    // return NULL to indicate we're at EOF:
    if (c == EOF && offset == 0) {
        free(buf);
        return NULL;
    }

    // Shrink to fit
    if (offset < bufsize - 1) {                    // If we're short of the end
        char *new_buf = realloc(buf, offset + 1);  // +1 for NUL terminator

        // If successful, point buf to new_buf;
        // otherwise we'll just leave buf where it is
        if (new_buf != NULL)
            buf = new_buf;
    }

    // Add the NUL terminator
    buf[offset] = '\0';

    return buf;
}
