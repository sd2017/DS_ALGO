#include "stdio.h"
#define YEAR 1990
#define DAYS 365

int TotalDays(int year, int month, int day);
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int totalday;
    int year, month, day;
    printf("please input the yaer-month-day:");
    scanf("%d-%d-%d", &year, &month, &day);

    totalday = TotalDays(year, month, day);
    printf("%d-%d-%d 是：", year, month, day);

    if (totalday % 5 == 0 || totalday % 5 == 4) {
        printf("晒网日!\n");
    } else {
        printf("打鱼日!\n");
    }

    getch();
    return 0;

}

//统计当前的天数
int TotalDays(int year, int month, int day)
{
    int i = year - YEAR;
    int i_month = 1;
    int totalday = day;

    if (year % 4 == 0 && year % 100 != 0) {
        a[2] = 29;
    }

    while (i_month < month) {
        totalday += a[i_month ++];
    }

    if (i > 0) {
        totalday += DAYS * i + (i - 1) / 4 + 1;
    }

    return totalday;
}
