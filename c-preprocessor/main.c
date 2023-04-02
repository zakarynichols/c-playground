#include <math.h>
#include <stdio.h>  // Brackets indicate system-wide directory

#include "local.h"  // Quotes indicate local files

int main(void) {
    printf("SQR = %d\n", SQR(12));
    printf("LOCAL expands to: %s\n", LOCAL);
    printf("This function: %s\n", __func__);
    printf("This file: %s\n", __FILE__);
    printf("This line: %d\n", __LINE__);
    printf("Compiled on: %s %s\n", __DATE__, __TIME__);
    printf("C Version: %ld\n", __STDC_VERSION__);

    printf("2*x^2 + 10*x + 5 = 0\n");
    printf("x = %f or x = %f\n", QUAD(2, 10, 5));

    printf("%d %s\n", XSTR(1, 2, "hello", "world", 999));

    PRINT_NUMS_TO_PRODUCT(2, 4);  // Outputs numbers from 0 to 7
}