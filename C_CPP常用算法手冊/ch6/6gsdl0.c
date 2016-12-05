
#include "stdio.h"
#include "6gsdl.c"
main()
{
    int i;
    double eps;
    double a[4][4] = { {7.0, 2.0, 1.0, -2.0}, {9.0, 15.0, 3.0, -2.0},
        { -2.0, -2.0, 11.0, 5.0}, {1.0, 3.0, 2.0, 13.0}
    };
    double x[5], b[4] = {4.0, 7.0, -1.0, 0.0};
    eps = 0.000001;

    if (gsdl(a, b, 4, x, eps) > 0)
        for (i = 0; i <= 3; i++) {
            printf("x(%d)=%13.6e\n", i, x[i]);
        }
}

