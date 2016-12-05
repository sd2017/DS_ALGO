#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} LinkNode;
typedef LinkNode* LinkList;
LinkList InitRing(int n,
                  LinkList R)          //尾插入法建立单循环链表函数
{
    LinkNode* p, *q;
    int i;
    R = q = (LinkNode*)malloc(sizeof(LinkNode));

    for (i = 1; i < n; i++) {
        p = (LinkNode*)malloc(sizeof(LinkNode));
        q->data = i;
        q->next = p;
        q = p;
    }

    p->data = n;
    p->next = R;
    R = p;
    return R;
}
LinkList DeleteDeath(int n, int k,
                     LinkList R)          //生者与死者的选择
{
    int i, j;
    LinkNode* p, *q;
    p = R;

    for (i = 1; i < n / 2; i++) { //删除一半结点
        for (j = 1; j < k - 1; j++) { //沿链前进k-1步
            p = p->next;
        }

        q = p->next;
        p->next = q->next;
        printf("%4d", q->data);
        free(q);
    }

    R = p;
    return R;
}
void OutRing(int n, LinkList R)                       //输出所有生者
{
    int i;
    LinkNode* p;
    p = R;

    for (i = 1; i <= n / 2; i++, p = p->next) {
        printf("%4d", p->data);
    }
}

void main()
{
    LinkList R;
    int n, k;
    LinkList InitRing(int n, LinkList R);
    LinkList DeleteDeath(int n, int k, LinkList R);
    void OutRing(int n, LinkList R);
    printf("总人数n. 报数上限k=");
    scanf("%d%d", &n, &k);
    R = InitRing(n, R);
    R = DeleteDeath(n, k, R);
    OutRing(n, R);
    getch();
    return 0;
}


