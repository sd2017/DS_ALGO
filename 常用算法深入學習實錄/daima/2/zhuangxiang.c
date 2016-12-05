#include <stdio.h>
#include <stdlib.h>

#define N 6
#define V 100

typedef struct box {
    int no;
    int size;
    struct box* next;
} BOX;

void init_list(BOX** H)
{
    *H = (BOX*)malloc(sizeof(BOX));
    (*H)->no = 0;
    (*H)->size = 0;
    (*H)->next = NULL;
}

BOX* find_p(BOX* H, int volume, int v)
{
    BOX* p = H->next;

    while (p != NULL) {
        if (p->size + volume <= v) {
            break;
        }

        p = p->next;
    }

    return p;
}

void add_list_tail(BOX* H, BOX* p)
{
    BOX* tmp = H->next;
    BOX* q = H;

    while (tmp != NULL) {
        q = tmp;
        tmp = tmp->next;
    }

    q->next = p;
}

void print_list(BOX* H)
{
    BOX* p = H->next;

    while (p != NULL) {
        printf("%d:%d\n", p->no, p->size);
        p = p->next;
    }
}

int add_box(int volume[], int v)
{
    int count = 0;
    int i;
    BOX* H = NULL;

    init_list(&H);

    for (i = 0; i < N; i++) {
        BOX* p = find_p(H, volume[i], v);

        if (p == NULL) {
            count++;
            p = (BOX*)malloc(sizeof(BOX));
            p->no = count;
            p->size = volume[i];
            p->next = NULL;
            add_list_tail(H, p);
        } else {
            p->size += volume[i];
        }
    }

    print_list(H);

    return count;
}

int main(int argc, char* argv[])
{
    int ret;
    int volumes[] = {60, 45, 35, 20, 20, 20};

    ret = add_box(volumes, V);

    printf("%d\n", ret);

    system("PAUSE");
    return 0;
}



