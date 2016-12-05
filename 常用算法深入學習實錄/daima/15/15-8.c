#include <stdio.h>          //预编译命令
int Jump(int, int);         //声明有被调用函数
void main()                 //主函数
{
    //主程序开始
    int S, y, sum;              //整型变量,S为河中石柱数 ,y为荷叶数
    printf("请输入石柱数S=");     //提示信息
    scanf("%d", &S);            //输入正整数S
    printf("请输入荷叶数y=");     //提示信息
    scanf("%d", &y);            //输入正整数y
    sum = Jump(S, y);           //Jump(sS,y)为被调用函数
    printf("Jump(%d,%d)=%d\n", S, y, sum);  //输出结果
    getch();
}                               //主程序结束
//以下函数是被主程序调用的函数
int Jump(int R, int z)          //整型自定义函数,R,z为形参
{
    //自定义函数体开始
    int k;                      //整型变量

    if (R == 0) {               //如果R为0,则为直接可解节点,
        k = z + 1;              //直接可解节点,k值为z+1
    } else {                    //如果不为1,则要调用Jump(R-1,z)
        k = 2 * Jump(R - 1, z); //计算Jump(r-1,z)再乘以2赋给k
    }

    return (k);                 //将k的值返回给Jump(S, y)
}                               //自定义函数体结束
