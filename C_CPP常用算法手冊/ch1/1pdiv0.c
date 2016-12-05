
#include "stdio.h"
#include "1pdiv.c"
main()
{
    int i;
    double p[5] = {8.0, -5.0, -3.0, 6.0, 3.0};
    double q[3] = {1.0, -1.0, 2.0};
    double s[3], r[2];
    pdiv(p, 5, q, 3, s, 3, r, 2);
    printf("\n");

    for (i = 0; i <= 2; i++) {
        printf(" s(%d)=%13.6e\n", i, s[i]);
    }

    printf("\n");

    for (i = 0; i <= 1; i++) {
        printf(" r(%d)=%13.6e\n", i, r[i]);
    }

    printf("\n");
}

