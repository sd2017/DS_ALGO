#include<iostream.h>
#include<string.h>
#include<time.h>
#define   size   100
int   board[size];
int   ver[size];
int   ru[size * 2]; //右上
int   rd[size * 2]; //右下
int   n, find;
int   rec[size];
//回溯搜索
void   dfs(int   t)
{
    int   i;

    if (find) {
        return;
    }

    if (t == n) {
        find = 1;

        for (i = 0; i < n; i++) {
            rec[i] = board[i];
        }

        return;
    }

    for (i = 0; i < n; i++) {
        if (ver[i] == 1) {
            continue;
        }

        if (ru[i - t + n] == 1) {
            continue;
        }

        if (rd[i + t] == 1) {
            continue;
        }

        ver[i] = 1;
        ru[i - t + n] = 1;
        rd[i + t] = 1;
        board[t] = i;
        dfs(t + 1);
        rd[i + t] = 0;
        ru[i - t + n] = 0;
        ver[i] = 0;
    }

    return;
}
int   main()
{
    int   i, j, t1, t2;
    cout << "输入棋盘大小";
    cin >> n;
    t1 = clock();
    find = 0;
    memset(ver, 0, sizeof(ver));
    memset(ru, 0, sizeof(ru));
    memset(rd, 0, sizeof(rd));
    dfs(0);
    t2 = clock();

    if (find)
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (rec[i] == j) {
                    cout << 'X';
                } else {
                    cout << '+';
                }
            }

            cout << endl;
        }
    else {
        cout << "Can't   find!n";
    }

    cout << "耗费时间：" << t2 - t1 << "msn";
    return   0;
}




