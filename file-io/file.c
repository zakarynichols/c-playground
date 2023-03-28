#include <stdio.h>

int main(void) {
    // Reading text files
    FILE* fp;  // File pointer to represent an open file

    fp = fopen("hello_world.txt", "r");  // Open file for reading

    if (fp == NULL) {
        printf("File is NULL\n");
        return 1;
    }

    int c = fgetc(fp);  // Read a single character
    printf("%c\n", c);  // Print char to stdout

    fclose(fp);  // Close the file when done

    // EOF
    int ch;

    fp = fopen("hello_world.txt", "r");

    if (fp == NULL) {
        printf("File (fp) is NULL\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);

    char s[1024];  // Big enough for any line this program will encounter
    int line_count = 0;

    fp = fopen("quote.txt", "r");

    if (fp == NULL) {
        printf("File (fp) is NULL\n");
        return 1;
    }

    printf("\n");

    while (fgets(s, sizeof s, fp) != NULL) {
        printf("%d: %s", ++line_count, s);
    }

    printf("\n");

    fclose(fp);

    // Formatted input
    char name[1024];  // Big enough for any line this program will encounter
    float length;
    int mass;

    fp = fopen("whales.txt", "r");

    // The fscanf() function skips leading whitespace when reading, and returns EOF on end-of-file or error.
    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
        printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

    fclose(fp);

    // Writing text files
    int x = 32;

    fp = fopen("output.txt", "w");
    // fp = stdout; stdout is a file and will output to the console instead of a file

    fputc('B', fp);
    fputc('\n', fp);  // newline
    fprintf(fp, "x = %d\n", x);
    fputs("Hello, world!\n", fp);

    fclose(fp);
}
