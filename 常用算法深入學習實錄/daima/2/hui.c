#include <stdio.h>

#define N 8

int solution[N], j, k, count, sols;

int place(int row, int col)
{
    for (j = 0; j < row; j++) {
        if (row - j == solution[row] - solution[j] ||
            row + solution[row] == j + solution[j] || solution[j] == solution[row]) {
            return 0;
        }
    }

    return 1;
}

void backtrack(int row)
{
    count++;

    if (N == row) {
        sols++;

        for (k = 0; k < N; k++) {
            printf("%d\t", solution[k]);
        }

        printf("\n\n");
    } else {
        int i;

        for (i = 0; i < N; i++) {
            solution[row] = i;

            if (place(row, i)) {
                backtrack(row + 1);
            }
        }
    }
}

void queens()
{
    backtrack(0);
}

int main(void)
{
    queens();
    printf("总共方案: %d\n", sols);
    getch();
    return 0;
}

