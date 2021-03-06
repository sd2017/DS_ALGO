#include <stdio.h>
#define ARRAYLEN 10
int source[] = {55, 94, 6, 65, 11, 38, 91, 29, 67, 82};
typedef struct bst {
    int data;
    struct bst* left;
    struct bst* right;
} ercha;
void Inserter(ercha* t, int key) //在二叉排序树中插入查找关键字key
{
    ercha* p, *parent, *head;

    if (!(p = (ercha*)malloc(sizeof(ercha*)))) { //申请内存空间
        printf("申请内存出错!\n");
        exit(0);
    }

    p->data = key; //保存结点数据
    p->left = p->right = NULL; //左右子树置空
    head = t;

    while (head) { //查找需要添加的父结点
        parent = head;

        if (key < head->data) { //若关键字小于结点的数据
            head = head->left;    //在左子树上查找
        } else {             //若关键字大于结点的数据
            head = head->right;    //在右子树上查找
        }
    }

    //判断添加到左子树还是右子树
    if (key < parent->data) { //小于父结点
        parent->left = p;    //添加到左子树
    } else {       //大于父结点
        parent->right = p;    //添加到右子树
    }
}

void Createer(ercha* t, int data[],
              int n) //n个数据在数组d中，tree为二叉排序树根
{
    int i;
    t->data = data[0];
    t->left = t->right = NULL;

    for (i = 1; i < n; i++) {
        Inserter(t, data[i]);
    }
}
void BST_LDR(ercha* t)  //中序遍历
{
    if (t) { //树不为空，则执行如下操作
        BST_LDR(t->left); //中序遍历左子树
        printf("%d ", t->data); //输出结点数据
        BST_LDR(t->right); //中序遍历右子树/
    }

    return;
}
//删除结点
void Deleteer(ercha* t, int key)
{
    ercha* p, *parent, *l, *l1;
    int child = 0; //0表示左子树，1表示右子树

    if (!t) {
        return;    //二叉排序树为空，则退出
    }

    p = t;
    parent = p;

    while (p) {        //二叉排序树有效
        if (p->data == key) {
            if (!p->left && !p->right) { //叶结点(左右子树都为空)
                if (p == t) { //被删除的是根结点
                    free(p);//释放被删除结点
                } else if (child == 0) { //父结点为左子树
                    parent->left = NULL; //设置父结点左子树为空
                    free(p); //释放结点空间
                } else { //父结点为右子树
                    parent->right = NULL; //设置父结点右子树为空
                    free(p); //释放结点空间
                }
            } else if (!p->left) { //左子树为空，右子树不为空
                if (child == 0) { //是父结点的左子树
                    parent->left = p->right;
                } else { //是父结点的右子树
                    parent->left = p->left;
                }

                free(p); //释放被删除结点
            } else if (!p->right) { //右子树为空，左子树不为空
                if (child == 0) { //是父结点的左子树
                    parent->right = p->right;
                } else { //是父结点的右子树
                    parent->right = p->left;
                }

                free(p); //释放被删除结点
            } else { //左右子树都不为空
                l1 = p; //保存左子树的父结点
                l = p->right; //从当前结点的右子树进行查找

                while (l->left) { //左子树不为空
                    l1 = l;
                    l = l->left; //查找左子树
                }

                p->data = l->data; //将左子树的数据保存到被删除结点
                l1->left = NULL; //设置父结点的左子树指针为空
                free(l1); //释放左子树占的内存空间
            }

            p = NULL;
        } else if (key < p->data) { //需删除记录的关键字小于结点的数据
            child = 0; //标记在当前结点左子树查找
            parent = p; //保存当前结点作父结点
            p = p->left; //查找右子树
        } else { //需删除记录的关键字大于结点的数据
            child = 1; //标记在当前结点右子树查找
            parent = p; //保存当前结点作父结点
            p = p->right; //查找右子树
        }
    }
}
int main()
{
    int i, key;
    ercha bst, *pos; //保存二叉排序树根结点
    printf("原数据:");

    for (i = 0; i < ARRAYLEN; i++) {
        printf("%d ", source[i]);
    }

    printf("\n");
    Createer(&bst, source, ARRAYLEN);
    printf("遍历二叉排序树:");
    BST_LDR(&bst);
    Deleteer(&bst, 37);
    printf("\n删除结点后的结点:");
    BST_LDR(&bst);
    getch();
    return 0;
}
