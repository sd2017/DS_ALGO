#include <stdio.h>
#define ARRAYLEN 8
int source[] = {63, 61, 88, 37, 92, 32, 28, 54};

int chazhao(int s[], int n, int key)
{
    int i;

    for (i = 0; i < n && s[i] != key; i++)
        ;

    if (i < n) {
        return i;
    } else {
        return -1;
    }
}

int main()
{
    int key, i, pos;
    printf("输入关键字:");
    scanf("%d", &key);
    pos = chazhao(source, ARRAYLEN, key);
    printf("原数据表:");

    for (i = 0; i < ARRAYLEN; i++) {
        printf("%d ", source[i]);
    }

    printf("\n");

    if (pos >= 0) {
        printf("查找成功，该关键字位于数组的第%d个位置。\n", pos);
    } else {
        printf("查找失败!\n");
    }

    getch();
    return 0;
}
