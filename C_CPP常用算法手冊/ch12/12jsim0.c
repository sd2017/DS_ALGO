
#include "math.h"
#include "stdio.h"
#include "12jsim.c"
main()
{
    int i;
    double  jsimf(double [], int);
    double d, u, v, eps, x[3], xx[2][3], f[3];
    d = 1.0;
    u = 1.6;
    v = 0.4;
    eps = 1.0e-30;
    i = jsim(2, d, u, v, x, eps, 200, xx, f, jsimf);
    printf("\n");
    printf("i=%3d\n", i);
    printf("\n");

    for (i = 0; i <= 2; i++)
        printf("x(0)=%13.5e  x(1)=%13.5e  f=%13.5e\n",
               xx[0][i], xx[1][i], f[i]);

    printf("\n");

    for (i = 0; i <= 1; i++) {
        printf("x(%2d)=%13.5e\n", i, x[i]);
    }

    printf("J=%13.5e\n", x[2]);
    printf("\n");
}

double jsimf(x, n)
int n;
double x[];
{
    double y;
    n = n;
    y = x[1] - x[0] * x[0];
    y = 100.0 * y * y;
    y = y + (1.0 - x[0]) * (1.0 - x[0]);
    return (y);
}

