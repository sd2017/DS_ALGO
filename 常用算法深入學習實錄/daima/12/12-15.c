#include<stdio.h>
int main()
{
    int n, a, i;
    printf("The series with equal difference are:\n");

    for (n = 1; n <= 6; n++) /*公差n取值为1~6*/
        for (a = 1; a <= 4; a++) /*首项a取值为1~4*/
            if (4 * n + 6 * a == 26 &&
                n * (n + a) * (n + a + a) * (n + a + a + a) == 880) /*判断结果*/
                for (i = 0; i < 20; i++) {
                    printf("%d ", n + i * a);    /*输出前20项*/
                }

    getch();
    return 0;
}


