move(int n, int x, int y, int z)
{
    if (n == 1) {
        printf("%c-->%c\n", x, z);
    } else {
        move(n - 1, x, z, y);
        printf("%c-->%c\n", x, z);
        {
            getchar();
        }
        move(n - 1, y, x, z);
    }
}
main()
{
    int h;
    printf("输入盘子个数: ");
    scanf("%d", &h);
    printf("移动%2d 个盘子的步骤如下:\n", h);
    move(h, 'a', 'b', 'c');
    system("pause");
}

