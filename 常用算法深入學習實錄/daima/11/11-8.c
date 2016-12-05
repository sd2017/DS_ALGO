#define MAX 10
main()
{
    long lMatrix[MAX][MAX], lTemp;
    int i, j, n;

    /*输入矩阵的n*/
    printf("Please input n of Matrix:\n");
    scanf("%d", &n);

    /*输入矩阵的每个元素*/
    printf("\nPlease input elements of Matrix(%d*%d):\n", n, n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%ld", &lTemp);
            lMatrix[i][j] = lTemp;
        }

    /*对调a[i][j]和a[j][i] */
    for (i = 0; i < n; i++)
        for (j = 0; j < i; j++) {
            lTemp = lMatrix[i][j];
            lMatrix[i][j] = lMatrix[j][i];
            lMatrix[j][i] = lTemp;
        }

    /*打印输出结果*/
    printf("\nResult matrix: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%ld ", lMatrix[i][j]);
        }

        printf("\n");
    }

    getch();
}


