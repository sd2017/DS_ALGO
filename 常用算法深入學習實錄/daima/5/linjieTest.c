#include <stdio.h>
#include "linjie.c"
int main()
{
    linGraph G; //定义保存邻接表结构的图
    printf("输入生成图的类型(0:无向图,1:有向图):");
    scanf("%d", &G.GraphType); //图的种类
    printf("输入图的顶点数量和边数量:");
    scanf("%d,%d", &G.VextexNum, &G.EdgeNum); //输入图顶点数和边数
    printf("输入构成各边的两个顶点及权值(用逗号分隔):\n");
    Createlin(&G); //生成邻接表结构的图
    printf("输出图的邻接表:\n");
    Outlin(&G);
    getch();
    return 0;
}
