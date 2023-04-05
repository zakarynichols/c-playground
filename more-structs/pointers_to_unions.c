#include <stdio.h>

union foo {
    int a, b, c, d, e, f;
    float g, h;
    char i, j, k, l;
};

int main(void) {
    union foo x;

    int *foo_int_p = (int *)&x;
    float *foo_float_p = (float *)&x;

    x.a = 12;
    printf("%d\n", x.a);         // 12
    printf("%d\n", *foo_int_p);  // 12, again

    x.g = 3.141592;
    printf("%f\n", x.g);           // 3.141592
    printf("%f\n", *foo_float_p);  // 3.141592, again

    union foo y;
    int *foo_int_p_y = (int *)&y;             // Pointer to int field
    union foo *p = (union foo *)foo_int_p_y;  // Back to pointer to union

    p->a = 12;  // This line the same as...
    y.a = 12;   // this one.

    printf("%d\n", p->a);
    printf("%d\n", y.a);
}