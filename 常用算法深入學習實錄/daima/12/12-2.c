#include<stdio.h>
void main()
{
    int a, b, c, count = 0;
    printf("There are diffrent methods for XM to distribute books to 3 readers:\n");

    for (a = 1; a <= 5;
         a++)      /*穷举第一个人借5本书中的1本的全部情况*/
        for (b = 1; b <= 5;
             b++)  /*穷举第二个人借5本书中的一本的全部情况*/
            for (c = 1; a != b &&
                 c <= 5; c++)    /*当前两个人借不同的书时，穷举第三个人借5本书
中的1本的全部情况*/
                if (c != a && c != b) { /*判断第三人与前两个人借的书是否不同*/
                    printf(count % 8 ? "%2d:%d,%d,%d  " : "%2d:%d,%d,%d\n  ", ++count, a, b, c);
                }

    /*打印可能的借阅方法*/
    getch();
    return 0;
}

