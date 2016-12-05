
#include "stdio.h"
#include "12max1.c"
main()
{
    int js[2];
    void  max1f(double, double []);
    double eps, x[2];
    eps = 1.0e-10;
    x[0] = 1.0;
    max1(x, eps, 10, js, max1f);
    printf("\n");
    printf("js(0)=%3d\n", js[0]);

    if (js[1] < 0) {
        printf("MIN:  ");
    } else {
        printf("MAX:  ");
    }

    printf("x=%13.5e  f(x)=%13.5e  \n", x[0], x[1]);
    printf("\n");
}

void max1f(x, y)
double x, y[2];
{
    y[0] = (x - 1.0) * (10.0 - x);
    y[1] = -2.0 * x + 11.0;
    return;
}

