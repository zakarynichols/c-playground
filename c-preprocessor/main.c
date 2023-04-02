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
}