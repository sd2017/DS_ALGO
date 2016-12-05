/**********************************************/
#include <stdio.h>
#include <stdlib.h>
/***************链表实现的头文件***************/
typedef struct node {
    int zhishu;
    int xishu;
    struct node* next;
} linknode;
typedef linknode* linklist;
/**********************************************/
/*  函数功能：      创建链表
    函数入口参数：  head   空链表的头结点
    函数返回值：    已经建好的链表的头结点
*/
linklist creat_list(linklist head)
{
    linklist x;
    linklist p;
    head = (linklist)malloc(sizeof(linknode)); /*为头结点申请空间*/

    head->next = NULL;
    head->zhishu = 0;
    head->xishu = 0; /*头结点全部信息置空 */
    p = head;    /*指针指向头结点 */

    while (1) {
        x = (linklist)malloc(sizeof(linknode));
        printf("\n Input xi shu and zhi shu:");
        scanf("%d %d", &(x->xishu),
              &(x->zhishu)); /*输入系数与指数，且系数与指数之间一空格键隔开 */

        if (x->xishu == 0) {
            /*系数与指数均可为负数*/
            printf(" ******* First list is ok!*******\n\n");
            break;  /*当系数为0时输入完成，退出循环*/
        }

        x->next = NULL; /*链接数据*/
        p->next = x;
        p = x;
    }



    return head;   /*返回头结点*/
}
/**********************************************/
/*函数功能：    打印出链表各节点的值
  函数入口参数：链表的头结点
  函数返回值：  无
*/
void print_list(linklist head)
{
    linklist p;
    p = head->next;
    printf("                      ");

    while (p != NULL) {
        printf("(%d)X^%d", p->xishu, p->zhishu);

        if (p->next != NULL) {
            printf("+");
        }

        p = p->next;
    }

    printf("\n");
}
/*********************************************/
/*函数功能：       释放函数所占空间
   函数入口参数：   要释放链表的头结点
   函数返回值：     无?
  */
void free_list(linklist head)
{
    linklist p;

    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
}
/**********************************************/
/*函数功能：实现两个多项式的相加
  函数入口参数：待相加的两个多项式所在链表的头结点
  函数返回值:   两多项式之和的链表的头结点
*/
linklist jiafa(linklist head1, linklist head2)
{
    linklist p1, p2, s;
    linklist p3, head3;
    head3 = (linklist)malloc(sizeof(linknode));
    p3 = head3;
    p1 = head1->next;
    p2 = head2->next;

    while (p1 && p2) {
        s = (linklist)malloc(sizeof(linknode));

        if (p1->zhishu > p2->zhishu) {

            s->zhishu = p1->zhishu;
            s->xishu = p1->xishu;
            p1 = p1->next;
        } else if (p1->zhishu == p2->zhishu) {
            s->zhishu = p1->zhishu;
            s->xishu = p1->xishu + p2->xishu;
            p1 = p1->next;
            p2 = p2->next;
        } else {
            s->zhishu = p2->zhishu;
            s->xishu = p2->xishu;
            p2 = p2->next;
        }

        p3->next = s;
        p3 = s;

    }

    p3->next = NULL;      /*处理尾部*/

    if (p1) {
        p3->next = p1;
    }

    if (p2) {
        p3->next = p2;
    }

    return  head3;
}
/*****************************************************/
linklist jianfa(linklist head1, linklist head2)
{
    linklist p2;
    p2 = head2->next;

    while (p2) {
        p2->xishu = (-1) * p2->xishu;
        p2 = p2->next;
    }

    return jiafa(head1, head2);
}
/***********************************************/
void main()
{
    int choose;
    linklist  head1, head2, head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

    /*表头提示*/

    printf("*******************************************\n");
    printf("The xishu and zhishu are integer type!\n"); /*指数和系数都为整数类型*/
    printf("The linklist input end by xishu == 0!\n"); /* 链表输入时，当系数为0时输入结束 */
    printf("The zhishu of polynomial is form high to low!\n"); /*程序输出时指数由高到低排列 */
    printf("*******************************************\n");

    while (1) {
        printf("\n\n*******************************************\n");
        printf("1.jiafa!\n");
        printf("2.jianfa!\n");
        printf("0.Exit the system!\n");
        printf("Please choose:");
        scanf("%d", &choose);

        if (choose != 0 && (choose == 1 || choose == 2)) {
            head1 = creat_list(head1); /*创建链表*/
            head2 = creat_list(head2);

            if (head1 != NULL &&
                head2 != NULL) { /*运行的条件是两链表都不为空*/
                printf("The first polynomial:\n");
                print_list(head1);   /*输出第一个链表*/
                printf("The second polymial:\n");
                print_list(head2);     /*输出第二个链表 */
                printf("The result is:\n");

                switch (choose) {
                case 1:
                    head3 = jiafa(head1, head2);
                    break;

                case 2:
                    head3 = jianfa(head1, head2);
                    break;

                default:
                    break;
                }

                print_list(head3);          /* 输出结果 */
                printf("That is over!\n");

                free_list(head1); /* 释放掉空间 */
                free_list(head2);
                free_list(head3);

            }

            if (head1 == NULL &&
                head2 == NULL) { /*当两个链表为空时，显示为空 */
                printf("The list is empty!!\n");
            }
        }

        if (choose == 0) {
            break;
        }
    }

    getch();
}
