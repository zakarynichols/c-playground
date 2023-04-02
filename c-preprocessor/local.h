#ifndef LOCAL_H
#define LOCAL_H

#include <math.h>

#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b)-4 * (a) * (c))) / (2 * (a)))
#define QUADM(a, b, c) ((-(b)-sqrt((b) * (b)-4 * (a) * (c))) / (2 * (a)))
#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)

#define LOCAL "I'm a string from local.h"

// Parenthesis is so common that you should automatically
// do it every time you make a parameterized math macro
#define SQR(x) ((x) * (x))

#define TRIANGLE_AREA(w, h) (0.5 * (w) * (h))

#endif