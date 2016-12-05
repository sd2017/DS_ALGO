
#include "math.h"
#include "stdio.h"
#include "8chir.c"
main()
{
    int i;
    double x[101], y[101], a[7];

    for (i = 0; i <= 100; i++) {
        x[i] = -1.0 + 0.02 * i;
        y[i] = atan(x[i]);
    }

    chir(x, y, 101, a, 6);
    printf("\n");

    for (i = 0; i <= 5; i++) {
        printf("a(%2d)=%13.5e\n", i, a[i]);
    }

    printf("\n");
    printf("MAX(p-f)=%13.5e\n", a[6]);
    printf("\n");
}

