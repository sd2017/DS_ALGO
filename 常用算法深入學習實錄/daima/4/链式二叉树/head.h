#include "stdio.h"
#include "stdlib.h"

#define ERROR 0
#define OK 1
#define TRUE 0
#define OVERFLOW -2
#define NULL 0

typedef char ElemType;
typedef int Status ;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, *rchild;
} BiTNode, *BiTree;


#define Max 100
#define Crement 10

typedef struct {
    BiTree* top;
    BiTree* base;
    int stacksize;
} SqStack;

/////////////////////////////////////
//   为层次遍历建立队列
typedef struct QNode {
    BiTree DATA;
    struct QNode* next;
} QNode, *QuePtr;

typedef struct {
    QuePtr front;
    QuePtr rear;
} LinkQ;

