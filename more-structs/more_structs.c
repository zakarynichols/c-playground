#include <stdbool.h>
#include <stdio.h>

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

    return 0;
}