#include "head.h"
#include "tree.cpp"
void main()
{
    BiTree T;
    int num = 0;
    T = NULL;
    printf("����������Ԫ��:\n");
    PreCreate(T);
    printf("\n�������Ϊ:");
    PreVisit(T);
    printf("\n\n�ǵݹ��������:");
    Inorder(T);
    printf("\n\n���������Ϊ:%3d", Deep(T));
    leave(T, num);
    printf("\n\nҶ�ӽ�����Ϊ:%3d", num);
    printf("\n\n��α���������Ϊ:");
    level(T);
    printf("\n");
}