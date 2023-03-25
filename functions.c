#include <stdio.h>

int plus_one(int n);
void foo(void);  // adding void to empty prototype turns off all type checking

int main(void) {
    printf("%d\n", plus_one(0));
    foo();
}

int plus_one(int n) {
    return n + 1;
}

void foo(void) {
    printf("Should always have 'void' in empty params list\n");
}