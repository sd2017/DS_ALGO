#include<stdio.h>
void main()
{
    int i, j, n = 0, x;                /*n为标志变量*/

    for (i = 23; n == 0; i += 2) {    /*控制试探的步长和过程*/
        for (j = 1, x = i; j <= 4 && x >= 11; j++) /*完成出售四次的操作*/
            if ((x + 1) % (j + 1) ==
                0) { /*若满足整除条件则进行实际的出售操作*/
                x -= (x + 1) / (j + 1);
            } else {
                x = 0;    /*否则停止计算过程*/
                break;
            }

        if (j == 5 && x == 11) {   /*若第四次余下11条则满足题意*/
            printf("There are %d fishes at first.\n", i);         /*输出结果*/
            n = 1;                                        /*控制退出试探过程*/
        }
    }

    getch();
}


