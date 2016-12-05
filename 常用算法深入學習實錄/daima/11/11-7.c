#define MAX 10
void MatrixMutiply(int m, int n, int p, long lMatrix1[MAX][MAX],
                   long lMatrix2[MAX][MAX], long lMatrixResult[MAX][MAX])
{
    int i, j, k;
    long lSum;

    /*嵌套循环计算结果矩阵（m*p）的每个元素*/
    for (i = 0; i < m; i++)
        for (j = 0; j < p; j++) {
            /*按照矩阵乘法的规则计算结果矩阵的i*j元素*/
            lSum = 0;

            for (k = 0; k < n; k++) {
                lSum += lMatrix1[i][k] * lMatrix2[k][j];
            }

            lMatrixResult[i][j] = lSum;
        }
}
main()
{
    long lMatrix1[MAX][MAX], lMatrix2[MAX][MAX];
    long lMatrixResult[MAX][MAX], lTemp;
    int i, j, m, n, p;

    /*输入两个矩阵的的行列数m,n,p*/
    printf("\nPlease input m of Matrix1:\n");
    scanf("%d", &m);
    printf("Please input n of Matrix1:\n");
    scanf("%d", &n);
    printf("Please input p of Matrix2:\n");
    scanf("%d", &p);

    /*输入第一个矩阵的每个元素*/
    printf("\nPlease elements of Matrix1(%d*%d):\n", m, n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            scanf("%ld", &lTemp);
            lMatrix1[i][j] = lTemp;
        }

    /*输入第二个矩阵的每个元素*/
    printf("\nPlease elements of Matrix2(%d*%d):\n", n, p);

    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++) {
            scanf("%ld", &lTemp);
            lMatrix2[i][j] = lTemp;
        }

    /*调用函数进行乘法运算，结果放在lMatrixResult 中*/
    MatrixMutiply(m, n, p, lMatrix1, lMatrix2, lMatrixResult);
    /*打印输出结果矩阵*/
    printf("\nResult matrix: \n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            printf("%ld ", lMatrixResult[i][j]);
        }

        printf("\n");
    }

    getch();
    return 0;
}


