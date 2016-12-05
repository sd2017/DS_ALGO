#include<stdio.h>
void main()
{
    int n, i, x, flag = 1;     /*flag：控制标记*/

    for (n = 6; flag; n++) {   /*采用试探的方法。令试探值n逐步加大*/
        for (x = n, i = 1 && flag; i <= 5; i++)
            if ((x - 1) % 5 == 0) {
                x = 4 * (x - 1) / 5;
            } else {
                flag = 0;    /*若不能分配则置标记falg=0退出分配过程*/
            }

        if (flag) {
            break;    /*若分配过程正常结束则找到结果退出试探的过程*/
        } else {
            flag = 1;    /*否则继续试探下一个数*/
        }
    }

    printf("Total number of fish catched=%d\n", n);    /*输出结果*/
    getch();
}


