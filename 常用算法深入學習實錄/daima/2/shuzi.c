
#include <time.h>
#include <stdio.h>
int main()
{
    int n, m, i = 0;
    srand(time(NULL));
    n = rand() % 100 + 1;

    do {
        printf("输入你猜的数字:");
        scanf("%d", &m);
        i++;

        if (m > n) {
            printf("错误!太大了!\n");
        } else if (m < n) {
            printf("错误!数太小了!\n");
        }
    } while (m != n);

    printf("回答正确!\n");
    printf("共猜测了%d次。\n", i);

    if (i <= 5) {
        printf("你太聪明了，这么快就猜出来了！");
    } else if (i > 5) {
        printf("还需改进方法，以便更快猜出来！");
    }

    getch();
    return 0;
}
