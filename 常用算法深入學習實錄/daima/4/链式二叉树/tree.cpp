Status PreCreate(BiTree& T)
{
    //������������
    ElemType ch;
    //  fflush(stdin);//ˢ��������
    scanf("%c", &ch);

    if (ch == ' ') {
        T = NULL;
    } else {
        T = (BiTNode*)malloc(sizeof(BiTNode));

        if (!T) {
            exit(OVERFLOW);
        }

        T->data = ch;//���ɸ����
        PreCreate(T->lchild);//����������
        PreCreate(T->rchild);//����������
    }

    return OK;
}

Status PreVisit(BiTree T)
{
    //�������������
    if (T) {
        printf("%3c", T->data);
        PreVisit(T->lchild);
        PreVisit(T->rchild);
    }

    return OK;
}


/////////////////////�ǵݹ�����㷨

Status InitStack(SqStack& S)
{
    //�����ջ
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
    //Ԫ����ջ
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
    //Ԫ�س�ջ
    if (S.base == S.top) {
        return ERROR;
    }

    p =  *--S.top;
    return OK;
}

Status Inorder(BiTree T)
{
    //�ǵݹ��������
    BiTree p;
    SqStack S;
    InitStack(S);
    p = T;

    while (p || S.base != S.top) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }//��ָ���ջ������������
        else { //��ָ����ջ�����ʸ���㣬����������
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
    //������������,�ݹ�
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
    //��Ҷ�ӽ��ĸ������õĵݹ��㷨
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
///////////  ��α�����ʵ��

Status Init(LinkQ& Q)
{
    //����һ���ն���
    Q.front = Q.rear = (QuePtr) malloc(sizeof(QNode));

    if (!Q.front) {
        exit(OVERFLOW);
    }

    Q.front ->next = NULL;
    return OK;
}

Status Insert(LinkQ& Q, BiTree e)
{
    //��Ӳ���
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
    //���Ӳ���
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
    //��α���������
    BiTree e;
    LinkQ Q;
    Init(Q);//��ʼ������
    e = T;
    Insert(Q, e);//��Ӳ���

    while (Q.front != Q.rear) { //���׳��ӾͰ������Һ����������
        Out(Q, e); //���Ӳ���
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
