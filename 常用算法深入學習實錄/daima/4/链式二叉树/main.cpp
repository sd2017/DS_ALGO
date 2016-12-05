#include "head.h"
#include "tree.cpp"
void main()
{
    BiTree T;
    int num = 0;
    T = NULL;
    printf("按先序输入元素:\n");
    PreCreate(T);
    printf("\n构造的树为:");
    PreVisit(T);
    printf("\n\n非递归中序遍历:");
    Inorder(T);
    printf("\n\n二叉树深度为:%3d", Deep(T));
    leave(T, num);
    printf("\n\n叶子结点个数为:%3d", num);
    printf("\n\n层次遍历二叉树为:");
    level(T);
    printf("\n");
}