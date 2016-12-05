

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAMELENGTH 100

class CBeibao
{
public:
    int m_nNumber;        //物品数量
    int m_nMaxWeight;    //最大载重量

    int* m_pWeight;        //每个物品的重量
    int* m_pValue;        //每个物品的价值

    int* m_pCount;        //每个物品被选中的次数
    int m_nMaxValue;    //最大价值

public:
    CBeibao(const char* filename);
    ~CBeibao();

    int GetMaxValue();
    int GetMaxValue(int n, int m, int* w, int* v, int* c);
    void Display(int nMaxValue);
    void Display(int nMaxValue, const char* filename);
};

//读入数据
CBeibao::CBeibao(const char* filename)
{
    FILE* fp = fopen(filename, "r");

    if (fp == NULL)
        ...{
        printf("can not open file!");
        return;    //exit(0);
    }

    //读入物品数量和最大载重量
    fscanf(fp, "%d%d", &m_nNumber, &m_nMaxWeight);

    m_pWeight = new int[m_nNumber + 1];
    m_pValue = new int[m_nNumber + 1];

    m_pWeight[0] = 0;

    //读入每个物品的重量
    for (int i = 1; i <= m_nNumber; i++) {
        fscanf(fp, "%d", m_pWeight + i);
    }

    m_pValue[0] = 0;

    //读入每个物品的价值
    for (int i = 1; i <= m_nNumber; i++) {
        fscanf(fp, "%d", m_pValue + i);
    }

    //初始化每个物品被选中次数为0
    m_pCount = new int[m_nNumber + 1];

    for (int i = 0; i <= m_nNumber; i++) {
        m_pCount[i] = 0;
    }

    fclose(fp);
}

CBeibao::~CBeibao()
{
    delete[] m_pWeight;
    m_pWeight = NULL;
    delete[] m_pValue;
    m_pValue = NULL;
    delete[] m_pCount;
    m_pCount = NULL;
}

/**//************************************************************************
 * 动态规划求出满足最大载重量的最大价值
 * 参数说明：n:物品个数
 *           m:背包载重量
 *           w:重量数组
 *           v:价值数组
 *           c:是否被选中数组
 * 返回值：最大价值
 ************************************************************************/
int CBeibao::GetMaxValue(int n, int m, int* w, int* v, int* c)
{
    int row = n + 1;
    int col = m + 1;

    int i, j;   //循环变量:前i个物品能够装入载重量为j的背包中

    //value[i][j]表示前i个物品能装入载重量为j的背包中物品的最大价值
    int** value = new int* [row];

    for (i = 0; i < row; i++) {
        value[i] = new int[col];
    }

    //初始化第0行
    for (j = 0; j < col; j++) {
        value[0][j] = 0;
    }

    //初始化第0列
    for (i = 0; i < row; i++) {
        value[i][0] = 0;
    }

    //计算
    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++)
            ...{
            //w[i]>j,第i个物品不装入背包
            value[i][j] = value[i - 1][j];
            //w[i]<=j,且第i个物品装入背包后的价值>value[i-1] [j],则记录当前最大价值
            int temp = value[i - 1][j - w[i]] + v[i];

            if (w[i] <= j && temp > value[i][j])
            {
                value[i][j] = temp;
            }
        }
    }

    //逆推求装入的物品
    j = m;

    for (i = row - 1; i > 0; i--) {
        if (value[i][j] > value[i - 1][j])
            ...{
            c[i] = 1;
            j -= w[i];
        }
    }

    //记录最大价值
    int nMaxVlaue = value[row - 1][col - 1];

    //释放该二维数组
    for (i = 0; i < row; i++) {
        delete [col]value[i];
        value[i] = NULL;
    }

    delete[] value;
    value = NULL;

    return nMaxVlaue;
}

int CBeibao::GetMaxValue()
{
    int nValue = GetMaxValue(m_nNumber, m_nMaxWeight, m_pWeight, m_pValue,
                             m_pCount);
    m_nMaxValue = nValue;
    return nValue;
}

//显示结果
void CBeibao::Display(int nMaxValue)
{
    printf("   %d ", nMaxValue);

    for (int i = 1; i <= m_nNumber; i++)
        ...{
        if (m_pCount[i])
        {
            printf("  %d  %d ", i, m_pCount[i]);
        }
    }
    printf(" ");
}

void CBeibao::Display(int nMaxValue, const char* filename)
{
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("can not write file!");
        return;    //exit(0);
    }

    fprintf(fp, "%d ", nMaxValue);

    for (int i = 1; i <= m_nNumber; i++) {
        if (m_pCount[i]) {
            fprintf(fp, "%d  %d ", i, m_pCount[i]);
        }
    }

    fclose(fp);
}

//显示菜单
void show_menu()
{
    printf("--------------------------------------------- ");
    printf("input command to test the program ");
    printf("   i or I : input filename to test ");
    printf("   q or Q : quit ");
    printf("--------------------------------------------- ");
    printf("$ input command >");
}

void main()
{
    char sinput[10];
    char sfilename[FILENAMELENGTH];

    show_menu();

    scanf("%s", sinput);

    while (stricmp(sinput, "q") != 0) {
        if (stricmp(sinput, "i") == 0)
            ...{
            printf("  please input a filename:");
            scanf("%s", sfilename);

            //获取满足最大载重量的最大价值
            CBeibao beibao(sfilename);
            int nMaxValue = beibao.GetMaxValue();

            if (nMaxValue)
                ...{
                beibao.Display(nMaxValue);
                int nlen = strlen(sfilename);
                strcpy(sfilename + nlen - 4, "_result.txt");
                beibao.Display(nMaxValue, sfilename);
            } else
            { printf("   error! please check the input data! "); }
        }

        //输入命令
        printf("$ input command >");
        scanf("%s", sinput);
    }
}
