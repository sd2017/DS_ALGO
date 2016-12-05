#include <stdio.h>
#include "Create.c"
#define ARRAYLEN 10
void xuanze(int a[], int n)
{
    int i, j, t, k;

    for (i = 0; i < n - 1; i++) {
        k = i;

        for (j = i + 1; j < n; j++)
            if (a[k] > a[j]) {
                k = j;
            }

        t = a[i];
        a[i] = a[k];
        a[k] = t;
    }
}
int main()
{
    int i, a[ARRAYLEN];

    for (i = 0; i < ARRAYLEN; i++) {
        a[i] = 0;
    }

    if (!Create(a, ARRAYLEN, 1, 100)) {
        printf("生成随机数失败!\n");
        getch();
        return 1;
    }

    printf("原数据:");

    for (i = 0; i < ARRAYLEN; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    xuanze(a, ARRAYLEN);
    printf("排序后:");

    for (i = 0; i < ARRAYLEN; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    getch();
    return 0;
}
