// File foo.c

#include <stdio.h>

// The C preprocessor includes the file _right here_ just as if we'd typed it ourselves
#include "bar.h"

int main(void) {
    printf("%d\n", add(2, 3));  // 5
}