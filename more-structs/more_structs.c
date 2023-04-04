#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list node
struct node {
    int data;
    struct node *next;
};

// Anonymous struct used for later
typedef struct {
    int leg_count;
    char *name;
} organism;

// `struct named_struct named_variable` is usually better. Can see the entire declaration.
typedef struct named_struct {
    char *named_member;
} named_struct;

organism d, e, f;

// Anonymous struct
struct foo {
    int a;
    int b;
};

struct cabin_information {
    int window_count;
    int o2level;
};

struct spaceship {
    char *manufacturer;
    struct cabin_information ci;
};

#define MAX_PASSENGERS 8

struct passenger {
    char *name;
    bool covid_vaccinated;
};

struct spaceship_with_passengers {
    char *manufacturer;
    struct passenger passenger[MAX_PASSENGERS];
};

struct {  // No name
    char *name;
    int leg_count, speed;
} a, b, c;  // 3 variables of this struct type

struct len_string {
    int length;
    char data[8];
};

struct better_len_string {
    int length;
    char data[];  // No size for array. Must be last member in the array to work.
};

struct len_string *len_string_from_c_string(char *s);

int main(void) {
    // Initialize struct members
    struct foo x = {.a = 12, .b = 3.14};

    struct spaceship s = {
        .manufacturer = "General Products",
        .ci.window_count = 8,  // Nested initializer
        .ci.o2level = 21};

    printf("%s: %d seats, %d%% oxygen\n",
           s.manufacturer, s.ci.window_count, s.ci.o2level);

    struct spaceship sp = {
        .manufacturer = "General Products",
        .ci = {
            .window_count = 22,
            .o2level = 20}};

    printf("%s: %d seats, %d%% oxygen\n",
           sp.manufacturer, sp.ci.window_count, sp.ci.o2level);

    struct spaceship_with_passengers spa = {
        .manufacturer = "General Products",
        .passenger = {
            // Initialize a field at a time
            [0].name = "Gridley, Lewis",
            [0].covid_vaccinated = 0,

            // Or all at once
            [7] = {.name = "Brown, Teela", .covid_vaccinated = 1},
        }};

    printf("Passengers for %s ship:\n", s.manufacturer);

    for (int i = 0; i < MAX_PASSENGERS; i++) {
        if (spa.passenger[i].name != NULL)
            printf("    %s (%svaccinated)\n",
                   spa.passenger[i].name,
                   spa.passenger[i].covid_vaccinated ? "" : "not ");
    }

    a.leg_count = 4;
    c.name = "animal";

    d.leg_count = 2;
    d.name = "organism";

    struct node *head;

    // Hackishly set up a linked list (11)->(22)->(33)
    head = malloc(sizeof(struct node));
    head->data = 11;
    head->next = malloc(sizeof(struct node));
    head->next->data = 22;
    head->next->next = malloc(sizeof(struct node));
    head->next->next->data = 33;
    head->next->next->next = NULL;

    // Traverse it
    for (struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d\n", cur->data);
    }

    struct len_string *str = malloc(sizeof *str + 40);

    printf("string length = %d\n", len_string_from_c_string("Hello, world!")->length);
    printf("data = %s\n", len_string_from_c_string("Hello, world!")->data);

    return 0;
}

struct len_string *len_string_from_c_string(char *s) {
    int len = strlen(s);

    // Allocate "len" more bytes than we'd normally need
    struct len_string *ls = malloc(sizeof *ls + len);

    ls->length = len;

    // Copy the string into those extra bytes
    memcpy(ls->data, s, len);

    return ls;
}