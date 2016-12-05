#include<stdio.h>
#include<math.h>
void main()
{
    double a, x0, x1;
    printf("Input a:\n");
    scanf("%lf", &a);

    if (a < 0) {
        printf("Error!\n");
    } else {
        x0 = a / 2;
        x1 = (x0 + a / x0) / 2;

        do {
            x0 = x1;
            x1 = (x0 + a / x0) / 2;
        } while (fabs(x0 - x1) >= 1e-6);
    }

    printf("Result:\n");
    printf("sqrt(%g)=%g\n", a, x1);
    getch();
    return 0;
}
