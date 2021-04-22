#include <stdio.h>
#include <stdlib.h>
#define max_size 10

void Table_Sort(int *a, int *table, int N)
{
    int i, j, temp ,temp2;
    //初始化Table
    for(i=0;i<N;i++)
        table[i] = i;
    //插入排序
    for(i=1;i<N;i++)
    {
        temp = table[i];
        for(j=i;j>=1 && a[table[j-1]] > a[temp];j--)
            table[j] = table[j-1];
        table[j] = temp;
    }
    //调整原序列
    for(i=0;i<N;i++)
        if(table[i] != i) //第i本书不在对应位置
        {
            temp = a[i]; //取出第i本书
            j = i; 
            while(table[j] != i) //寻找第i本书所在位置
            {
                a[j] = a[table[j]]; 
                temp2 = table[j];
                table[j] = j; //当前书位置正确
                j = temp2; //待检查的下一个位置
            }
            a[j] = temp;
            table[j] = j; //当前位置正确
        }
    return;
}



int main()
{
    int a[max_size] = {1, 3, 5, 10, 12, 13, 15, 6, 11, 19};
    int table[max_size];
    int N = 10;
    int *p, *q;
    p = &a[0];
    q = &table[0];
    Table_Sort(p, q, N);
    return 0;
}