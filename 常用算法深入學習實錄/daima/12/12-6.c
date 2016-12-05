#include<stdio.h>
int a[3][3], count;
void main()
{
    int i, j, k, m, n, flag;
    printf("It exists possible distribtion plans:\n");

    for (i = 0; i <= 3;
         i++) { /*试探第一个人满筐a[0][0]的值，满筐数不能>3*/
        a[0][0] = i;

        for (j = i; j <= 7 - i &&
             j <= 3; j++) { /*试探第二个人满筐a[1][0]的值，满筐数不能>3*/
            a[1][0] = j;

            if ((a[2][0] = 7 - j - a[0][0]) > 3) {
                continue;    /*第三个人满筐数不能>3*/
            }

            if (a[2][0] < a[1][0]) {
                break;    /*要求后一个人分的满筐数>=前一个人 ，以排除重复情况*/
            }

            for (k = 1; k <= 5; k += 2) { /*试探半筐a[0][1]的值，半筐数为奇数*/
                a[0][1] = k;

                for (m = 1; m < 7 - k;
                     m += 2) { /*试探 半筐a[1][1]的值，半筐数为奇数*/
                    a[1][1] = m;
                    a[2][1] = 7 - k - m;

                    for (flag = 1, n = 0; flag && n < 3; n++)

                        /*判断每个人分到的鱼是 3.5筐，flag为满足题意的标记变量*/
                        if (a[n][0] + a[n][1] < 7 && a[n][0] * 2 + a[n][1] == 7) {
                            a[n][2] = 7 - a[n][0] - a[n][1];    /*计算应得到的空筐数量*/
                        } else {
                            flag = 0;    /*不符合题意则置标记为0*/
                        }

                    if (flag) {
                        printf("No.%d       Full basket Semi--basket Empty\n", ++count);

                        for (n = 0; n < 3; n++)
                            printf("     fisher %c:     %d     %d     %d\n",
                                   'A' + n, a[n][0], a[n][1], a[n][2]);
                    }
                }
            }

            getch();
        }
    }
}
