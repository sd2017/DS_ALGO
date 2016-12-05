#include <stdio.h>
#define max 100 //数组大小
void shellsort(int* a, int n)
{
    int delta, i, j;

    for (delta = n / 2; delta > 0; delta /= 2) {
        for (i = delta; i < n; i++) {
            int temp = a[i];

            for (j = i - delta; j >= 0; j -= delta) {
                if (temp < a[j]) {
                    a[j + delta] = a[j];
                } else {
                    break;
                }
            }

            a[j + delta] = temp;
        }
    }
}

////////////////////////////////////
//输出排序之后的数据序列
////////////////////////////////////
void print(int* a, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}

/////////////////////////////////
//主函数
////////////////////////////////
int main()
{
    int a[max];
    int n;//输入的数据个数
    scanf("%d", &n);
    int i;

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    shellsort(a, n);
    print(a, n);
    return 0;
}

