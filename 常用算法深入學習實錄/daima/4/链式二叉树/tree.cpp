Status PreCreate(BiTree& T)
{
    //先序建立二叉树
    ElemType ch;
    //  fflush(stdin);//刷新输入流
    scanf("%c", &ch);

    if (ch == ' ') {
        T = NULL;
    } else {
        T = (BiTNode*)malloc(sizeof(BiTNode));

        if (!T) {
            exit(OVERFLOW);
        }

        T->data = ch;//生成根结点
        PreCreate(T->lchild);//构造左子树
        PreCreate(T->rchild);//构造右子树
    }

    return OK;
}

Status PreVisit(BiTree T)
{
    //先序遍历二叉树
    if (T) {
        printf("%3c", T->data);
        PreVisit(T->lchild);
        PreVisit(T->rchild);
    }

    return OK;
}


/////////////////////非递归遍历算法

Status InitStack(SqStack& S)
{
    //构造空栈
    S.base = (BiTree*) malloc(Max * sizeof(BiTree));

    if (!S.base) {
        exit(OVERFLOW);
    }

    S.top = S.base;
    S.stacksize = Max;
    return OK;
}


Status Push(SqStack& S, BiTree p)
{
    //元素入栈
    if (S.top - S.base >= S.stacksize) {
        S.base = (BiTree*) realloc(S.base,
                                   (S.stacksize + Crement) * sizeof(BiTree));

        if (!S.base) {
            exit(OVERFLOW);
        }

        S.top = S.base + S.stacksize;
        S.stacksize += Crement;
    }

    *S.top = p;
    S.top ++;
    return OK;
}

Status Pop(SqStack& S, BiTree& p)
{
    //元素出栈
    if (S.base == S.top) {
        return ERROR;
    }

    p =  *--S.top;
    return OK;
}

Status Inorder(BiTree T)
{
    //非递归中序遍历
    BiTree p;
    SqStack S;
    InitStack(S);
    p = T;

    while (p || S.base != S.top) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }//根指针进栈，遍历左子树
        else { //根指针退栈，访问根结点，遍历右子树
            Pop(S, p);
            printf("%3c", p->data);
            p = p->rchild;
        }
    }

    return OK;
}



//////////////////////////
Status Deep(BiTree T)
{
    //求二叉树的深度,递归
    int rd, ld;

    if (T) {
        ld = Deep(T->lchild);
        rd = Deep(T->rchild);

        if (ld >= rd) {
            return ld + 1;
        }

        if (ld < rd) {
            return rd + 1;
        }
    }

    return 0;
}

Status leave(BiTree T, int& num)
{
    //求叶子结点的个数，用的递归算法
    if (T) {
        //      printf("%c",T->data);
        leave(T->lchild, num);
        leave(T->rchild, num);

        if (!T->lchild && !T->rchild) {
            num++;
        }
    }

    return 0;
}


///////////////////////////////////
///////////  层次遍历的实现

Status Init(LinkQ& Q)
{
    //构造一个空队列
    Q.front = Q.rear = (QuePtr) malloc(sizeof(QNode));

    if (!Q.front) {
        exit(OVERFLOW);
    }

    Q.front ->next = NULL;
    return OK;
}

Status Insert(LinkQ& Q, BiTree e)
{
    //入队操作
    QuePtr p;
    p = (QuePtr)malloc(sizeof(QNode));

    if (!p) {
        exit(OVERFLOW);
    }

    p->DATA = e;
    p->next = NULL;
    Q.rear ->next = p;
    Q.rear = p;
    return OK;
}

Status Out(LinkQ& Q, BiTree& e)
{
    //出队操作
    QuePtr p;

    if (Q.front == Q.rear) {
        return ERROR;
    }

    p = Q.front->next;
    e = p->DATA;
    Q.front->next = p->next;

    if (Q.rear == p) {
        Q.rear = Q.front;
    }

    free(p);
    return OK;
}

Status level(BiTree T)
{
    //层次遍历二叉树
    BiTree e;
    LinkQ Q;
    Init(Q);//初始化队列
    e = T;
    Insert(Q, e);//入队操作

    while (Q.front != Q.rear) { //队首出队就把其左右孩子依次入队
        Out(Q, e); //出队操作
        printf("%3c", e->data);

        if (e->lchild) {
            Insert(Q, e->lchild);
        }

        if (e->rchild) {
            Insert(Q, e->rchild);
        }
    }

    return OK;
}
