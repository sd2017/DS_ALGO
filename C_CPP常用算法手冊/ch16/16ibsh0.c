
#include "stdio.h"
#include "3rabs.c"
#include "15ishl.c"
#include "16ibsh.c"
main()
{
    int i, j, m0, *m;
    int p[100], r0, *r, a, b;
    r0 = 5;
    r = &r0;
    m = &m0;
    rabs(100, 300, r, p, 100);
    ishl(p, 100);
    printf("\n");

    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            printf("%d  ", p[10 * i + j]);
        }

        printf("\n");
    }

    printf("\n");
    a = 170;
    b = 195;
    i = ibsh(p, 100, a, b, m);
    printf("m=%d\n", m0);
    printf("i=%d\n", i);

    for (j = i; j <= i + m0 - 1; j++) {
        printf("p(%d)=%d\n", j, p[j]);
    }

    printf("\n");
}

