#include<stdio.h>
#define M 5
int count = 0;

int GetCnt(int n)
{

    count = 0;

    do {
        if (n & 1) {
            count++;
        }
    } while (n >>= 1);

    return count;
}

int main(int argc, char* argv[])
{
    int test[M] = {7, 3, 34, 2, 234};

    for (int i = 0; i < M; ++i) {
        printf("%d\n", GetCnt(test[i]));
    }

    return 0;
}
