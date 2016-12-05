#include<stdio.h>
int main()
{
    int x, y, z, count = 0;
    printf(" Men Women Children\n");
    printf("………………………………….\n");

    for (x = 0; x <= 10; x++) {
        y = 20 - 2 * x; /*x定值据(3)式求y*/
        z = 30 - x - y; /*由(1)式求z*/

        if (3 * x + 2 * y + z == 50) { /*当前得到的一组解是否满足式(2)*/
            printf(" %2d: %d %d %d\n", ++count, x, y, z);
        }

        getche();
    }
}



