#include <stdio.h>

int a = 37;
int b = 111;

int add(int x, int y) {
    return x + y;
}

void printa(void) {
    printf("a = %d, from file bar.c\n", a);
}

void printb(void) {
    printf("b = %d, from bar.c\n", b);
}