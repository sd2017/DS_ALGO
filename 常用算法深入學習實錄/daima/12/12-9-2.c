
#include <stdio.h>
#define MAX 64 //最多64个圆盘 
int main()
{
    int n, target, source, i, array[(MAX + 1) * 3 + 1], stick[3], height;
    long count = 0; //圆盘移动的次数
    printf("请输入汉诺塔圆盘的数量:");
    scanf("%d", &n); //输入盘子数量
    height = n + 1; // 塔的高度(用来分隔数组)

    for (i = 1; i <= n; i++) { //将盘子放入第1个塔
        array[i] = height - i;    //数字大的表示大盘子
    }

    for (i = 0; i <= 2 * height;
         i += height) {  //将每个塔的底部设置为一个大的数据
        array[i] = 1000;
    }

    if (n % 2 == 0) { //若圆盘序号是偶数
        target = 1; //目标为B塔
        stick[2] = 0;
        stick[1] = 1;
        array[height + 1] = array[n]; //移动第1个圆盘到第2个塔
    } else { //若圆盘序号为奇数
        target = 2; //目标为C塔
        stick[1] = 0;
        stick[2] = 1;
        array[2 * height + 1] = array[n]; //移动第1个圆盘到第3个塔
    }

    printf("第%d次,A塔-->%c塔\n", ++count,
           'a' - 1 + target + 1); //输出移动操作
    stick[0] = n - 1; //A塔中减去一个圆盘

    while (stick[0] + stick[1]) { //第1塔和第2塔不为空,则循环移动
        if (target == 0) { //若目标塔是A
            if (array[height + stick[1]] < array[2 * height +
                                                 stick[2]]) { //比较B、C塔，较小值作为下一个移动塔
                source = 1;
            } else {
                source = 2;
            }
        }

        if (target == 1) { //若目标塔是B
            if (array[stick[0]] < array[2 * height +
                                        stick[2]]) { //比较A、C塔的较小值
                source = 0;
            } else {
                source = 2;
            }
        }

        if (target == 2) { //若目标塔是C
            if (array[stick[0]] < array[height + stick[1]]) { //比较A、B塔的较小值
                source = 0;
            } else {
                source = 1;
            }
        }

        // 将source塔顶部圆盘移到另一较大或为偶数的塔
        if ((array[source * height + stick[source]]) > (array[target * height +
                stick[target]])
            || ((array[target * height + stick[target]] - array[source * height +
                    stick[source]]) % 2 == 0)) {
            target = 3 - source - target;
        }

        printf("第%d次,%c塔-->%c塔\n", ++count, 'a' - 1 + source + 1,
               'a' - 1 + target + 1); //输出移动操作
        stick[source] = stick[source] - 1;
        stick[target] = stick[target] + 1;    //从source塔移动target塔
        array[target * height + stick[target]] = array[source * height + stick[source] +
                1];
    }

    getch();
    return 0;
}

