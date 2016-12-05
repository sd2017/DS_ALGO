
#include "math.h"
void cexp(x, y, u, v)
double x, y, *u, *v;
{
    double p;
    p = exp(x);
    *u = p * cos(y);
    *v = p * sin(y);
    return;
}

