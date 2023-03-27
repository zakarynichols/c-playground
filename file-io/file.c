#include <stdio.h>

int main(void) {
    // Reading text files
    FILE* f;  // Variable to represent an open file

    f = fopen("hello_world.txt", "r");  // Open file for reading

    if (f == NULL) {
        printf("File is NULL\n");
        return 1;
    }

    int c = fgetc(f);   // Read a single character
    printf("%c\n", c);  // Print char to stdout

    fclose(f);  // Close the file when done

    // EOF
    FILE* fp;

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

    char s[1024];
    int line_count = 0;

    fp = fopen("quote.txt", "r");

    if (fp == NULL) {
        printf("File (fp) is NULL\n");
        return 1;
    }

    while (fgets(s, sizeof s, fp) != NULL) {
        printf("%d: %s", ++line_count, s);
    }

    fclose(fp);
}
