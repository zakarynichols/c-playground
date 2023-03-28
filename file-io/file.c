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

    // Binary file I/O
    unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};

    fp = fopen("output.bin", "wb");  // wb mode for "write binary"

    // In the call to fwrite, the arguments are:
    //
    // * Pointer to data to write
    // * Size of each "piece" of data
    // * Count of each "piece" of data
    // * FILE*

    fwrite(bytes, sizeof(char), 6, fp);

    fclose(fp);

    unsigned char cha;

    fp = fopen("output.bin", "rb");  // rb for "read binary"

    while (fread(&cha, sizeof(char), 1, fp) > 0) {
        printf("%d\n", cha);
    }

    // Struct and number caveats
    fp = fopen("output.bin", "wb");  // wb mode for "write binary"

    unsigned short v = 0x1234;  // Two bytes, 0x12 and 0x34

    fwrite(&v, sizeof v, 1, fp);  // 'hd output.bin' results in 34 12 - The output is reversed due to _endianness_ of the architecture

    // To write binary data in a portable way, serialize your binary data when writing it to a stream.
}
