#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *c, float new_price);

int main(void) {
    struct car saturn;

    saturn.name = "Saturn SL/2";
    saturn.price = 15999.99;
    saturn.speed = 175;

    printf("Name:           %s\n", saturn.name);
    printf("Price (USD):    %f\n", saturn.price);
    printf("Top Speed (km): %d\n", saturn.speed);

    // Can define the fields in order.
    struct car chevy = {"Camaro", 19999.99, 200};

    // Safer to explicitly define the struct fields if they do change.
    struct car toyota = {.name = "Corolla LE", .price = 17999.99, .speed = 180};

    printf("%f\n", chevy.price);

    // Passing structs to functions
    set_price(&chevy, 55555.55);

    printf("%f\n", chevy.price);

    // Copying and returning structs
    struct car a, b;
    a.name = "a";
    b.name = "b";

    b = a;  // All fields are copied as-is

    printf("%s\n", b.name);  // a
    // Comparing structs
    // Must compare each field one at a time
}

void set_price(struct car *c, float new_price) {
    // (*c).price = new_price;  // Works, but non-idiomatic
    //
    // The line above is 100% equivalent to the one below:
    c->price = new_price;
}