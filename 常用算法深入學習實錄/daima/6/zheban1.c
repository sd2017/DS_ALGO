#include<stdio.h>


int seek(int* pArr, int low, int high, int num);

void main()
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int find, num;
    printf("input a num to be found.\n");
    scanf("%d", &num);
    find = seek(Arr, 0, 9, num);

    if (find == -1) {
        printf("num=%d not found!\n", num);
    } else {
        printf("num has been found!\nArr[%d] = %d\n", find, Arr[find]);
    }

}

int seek(int* pArr, int low, int high, int num)
{
    //pArr 为数组名，该数组必须是排好序了（这是二分法的要求），这里按从小到大排序
    int mid;
    mid = (low + high) / 2;

    if ((low >= high) && (pArr[mid] != num)) {
        return -1;
    } else {
        if (pArr[mid] == num) {
            return mid;
        } else if (pArr[mid] > num) {
            high = mid +
                   1;    //中间数字比要查的数还大，说明可能在中间段以前
        } else {
            low = mid - 1;    //同上，可能在中间段以后
        }

        return seek(pArr, low, high, num); //递归
    }
}
