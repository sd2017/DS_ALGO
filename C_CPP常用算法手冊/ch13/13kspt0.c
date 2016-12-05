
#include "stdio.h"
#include "13kspt.c"
main()
{
    int i;
    double y[9] = {54.0, 145.0, 227.0, 359.0, 401.0,
                   342.0, 259.0, 112.0, 65.0
                  };
    double yy[9];
    kspt(9, y, yy);
    printf("\n");

    for (i = 0; i <= 8; i++) {
        printf("y(%2d)=%13.5e   yy(%2d)=%13.5e\n", i, y[i], i, yy[i]);
    }

    printf("\n");
}

