#include <stdio.h>

// Typdef in theory
typedef int antelope;                // Make "antelope" an alias for "int"
typedef int hippo, elephant, tiger;  // Can declare several comma seperated types. All aliases for "int"

// Scoping -  it’s quite common to find typedef at file scope ("global") so that all functions can use the new types at will.

// Typedef in practice

struct animal {
    char *name;
    int leg_count, speed;
};

//  original name      new name
//            |         |
//            v         v
//      |-----------| |----|
typedef struct animal animal;

// Same as above, except more concise.
typedef struct cat {
    char *name;
    int leg_count, speed;
} cat;

struct cat c;  // This works
cat cc;        // This also works because "cat" is an alias

//  Anonymous struct! It has no name!
//         |
//         v
//      |----|
typedef struct {
    char *name;
    int leg_count, speed;
} dog;  // <-- new name

// struct dog d;  // ERROR: this no longer works--no such struct
dog dd;  // This works because "dog" is an alias

typedef struct {
    int x, y;
} point;

point p = {.x = 20, .y = 40};

// typedef and other types
typedef float app_float;

// and

app_float f1, f2, f3;

// Easier to refactor new type with an alias
//      |---------|
typedef long double app_float;

// and no need to change this line:

app_float f1, f2, f3;  // Now these are all long doubles

// typedef and pointers
typedef int *intptr;

int a = 10;
intptr x = &a;  // "intptr" is type "int*"
// it’s better to explicitly show that you’re declaring a pointer type so that other devs
// can clearly see it and don’t mistake x for having a non-pointer type.

// typedef and capitalization
typedef struct {
    int x, y;
} my_point;  // lower snake case

typedef struct {
    int x, y;
} MyPoint;  // CamelCase

typedef struct {
    int x, y;
} Mypoint;  // Leading uppercase

typedef struct {
    int x, y;
} MY_POINT;  // UPPER SNAKE CASE

// Arrays and typedef
// Make type five_ints an array of 5 ints
typedef int five_ints[5];

five_ints x = {11, 22, 33, 44, 55};  // Rare because it hides the array nature of the variable, but it’s possible to do.

int main(void) {
    printf("%d, %d\n", p.x, p.y);  // 20, 40

    return 0;
}