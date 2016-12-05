#include <stdio.h>
#include <malloc.h>
#include <string.h> /*包含一些字符串处理函数的头文件*/
#define N 10
typedef struct node {
    char name[20];
    struct node* link;
} stud;
stud* creat(int n)  /*建立链表的函数*/
{
    stud* p, *h, *s;
    int i;

    if ((h = (stud*)malloc(sizeof(stud))) == NULL) {
        printf("不能分配内存空间!");
        exit(0);
    }

    h->name[0] = '\0';
    h->link = NULL;
    p = h;

    for (i = 0; i < n; i++) {
        if ((s = (stud*) malloc(sizeof(stud))) == NULL) {
            printf("不能分配内存空间!");
            exit(0);
        }

        p->link = s;
        printf("请输入第%d个人的姓名", i + 1);
        scanf("%s", s->name);
        s->link = NULL;
        p = s;
    }

    return (h);
}
stud* search(stud* h, char*
             x) /*查找链表的函数，其中h指针是链表的表头指针，x指针是要查找的人的姓名*/
{
    stud* p; /*当前指针，指向要与所查找的姓名比较的结点*/
    char* y; /*保存结点数据域内姓名的指针*/
    p = h->link;

    while (p != NULL) {
        y = p->name;

        if (strcmp(y, x) ==
            0) { /*把数据域里的姓名与所要查找的姓名比较，若相同则返回0，即条件成立*/
            return (p);    /*返回与所要查找结点的地址*/
        } else {
            p = p->link;
        }
    }

    if (p == NULL) {
        printf("没有查找到该数据!");
    }
}
main()
{
    int number;
    char fullname[20];
    stud* head,
          *searchpoint; /*head是表头指针，searchpoint是保存符合条件的结点地址的指针*/
    number = N;
    head = creat(number);
    printf("请输入你要查找的人的姓名:");
    scanf("%s", fullname);
    searchpoint = search(head,
                         fullname); /*调用查找函数，并把结果赋给searchpoint指针*/
}
