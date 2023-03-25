#include <stdio.h>

int plus_one(int n);

int main(void) {
    printf("%d\n", plus_one(0));
}

int plus_one(int n) {
    return n + 1;
}