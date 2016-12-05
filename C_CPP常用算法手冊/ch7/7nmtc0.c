
#include "math.h"
#include "stdio.h"
#include "7nmtc.c"
main()
{
    int i, n, m;
    double nmtcf(double [], int);
    double b, eps, x[3] = {0.0, 0.0, 0.0};
    b = 2.0;
    m = 10;
    n = 3;
    eps = 0.000001;
    nmtc(x, n, b, m, eps, nmtcf);
    printf("\n");

    for (i = 0; i <= 2; i++) {
        printf("x(%d)=%13.6e\n", i, x[i]);
    }

    printf("\n");
}

double nmtcf(x, n)
int n;
double x[];
{
    double f, f1, f2, f3;
    n = n;
    f1 = 3.0 * x[0] + x[1] + 2.0 * x[2] * x[2] - 3.0;
    f2 = -3.0 * x[0] + 5.0 * x[1] * x[1] + 2.0 * x[0] * x[2] - 1.0;
    f3 = 25.0 * x[0] * x[1] + 20.0 * x[2] + 12.0;
    f = sqrt(f1 * f1 + f2 * f2 + f3 * f3);
    return (f);
}

