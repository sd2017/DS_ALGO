#include <stdio.h>

int main()
{
    long i, j, num1, num2;
    int n = 0, num[100000];
    memset(num, 0, 100000);

    for (i = 2; i <= 100000; i++) {
        if (num[i] == 0) {
            for (j = 2; i * j <= 100000; j++) {
                num[i * j] = 1;
            }
        }
    }

    for (i = 2; n <= 15; i++) {
        if (num[i] == 0 && num[i + 2] == 0) {
            printf("%d %d\n", i, i + 2);
            i += 2;
            n++;
        }
    }

    getch();
}

