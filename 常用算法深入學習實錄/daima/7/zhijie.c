#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*将一个数组用插入排序法排序
  入口参数,一个整形数组,一个整形数
  返回值:无*/
void px(int* a, int n)
{
    int i, j, k;

    for (j = 1; j <= n - 1; j++) {
        i = j - 1;
        k = a[j];

        while (i >= 0 && k > a[i]) {
            a[i + 1] = a[i];
            i--;
        }

        a[i + 1] = k;
    }
}
/*输入需要排序的数
  入口参数:整型数组,整型数
  返回值:无*/
void input(int* a, int n)
{
    int i;
    printf("请输入您要排序的内容\n");

    for (i = 0; i < n; i++) {
        scanf(" %d", &a[i]);

    }
}
void output(int* p, int n)
{
    //输出
    int j;

    for (j = 0; j < n; j++) {
        printf("%5d", p[j]);

        if (j % 8 == 7) {
            printf("\n");
        }
    }

    printf("\n");
}
void init(int* p, int m)
{
    //初始化
    int i;
    srand(time(NULL));

    for (i = 0; i < m; i++) {
        *(p + i) = rand() % 100 + 1;
    }
}
void printfbt(void)
{
    int i = 0, j = 0;

    for (i = 0; i < 80; i++) {
        printf("*");
    }

    for (i = 0; i < 10; i++) {
        printf(" ");
    }

    printf("\t\t\t\t功能：演示整数排序\n");
}
main()
{
    int* a = NULL;
    int i, flag = 1;
    char j;
    printfbt();

    while (flag) {
        printf("请输入您要排序的个数:");
        scanf("%d", &i);
        a = (int*)malloc(i * sizeof(int));

        if (a == NULL) {
            printf("对不起,这台电脑的内存有限!\n请问您要不要重新输入(y/n):");
            scanf("%*c%c", &j);

            if ((j == 'y') || (j == 'Y'));
            else {
                flag = 0;
            }
        } else {
            printf("请选择您要做的操作: 1,亲自输入%d个数", i);
            printf("\n                    2,让电脑帮您随机产生");
            printf("\n请输入(1/2):");
            scanf("%*c%c", &j);

            if (j == '1') {
                input(a, i);
            } else {
                init(a, i);
                printf("初始化后的内容是\n");
                output(a, i);
            }

            px(a, i);
            printf("排序后的内容是\n");
            output(a, i);
            free(a);
            printf("请问您是否还想继续使用本程序?(y/n):");
            scanf("%*c%c", &j);

            if ((j == 'y') || (j == 'Y'));
            else {
                flag = 0;
            }
        }
    }

    printf("\n再次感谢您使用本程序！\n制作人：\n");
}
