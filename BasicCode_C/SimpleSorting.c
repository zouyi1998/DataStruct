#include <stdio.h>
#include <stdlib.h>

#define max_size 10
#define inf 0xffff
//冒泡排序
void Bubble_Sort(int *a, int N)
{
    int i, j, temp, flag;
    flag = 0;
    for (j = N - 2; j >= 0; j--) //外循环从 N-2取到0
    {
        for (i = 0; i <= j; i++) //内循环从0取到j
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}
//选择排序
void Insertion_Sort(int *a, int N)
{
    int temp, i, j;
    for (i = 1; i < N; i++)
    {
        temp = a[i];
        for (j = i; j >= 1 && temp < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = temp;
    }
}
//选择排序
void Selection_Sort(int *a, int N)
{
    int i, j, min, temp, pos;
    for (i = 0; i < N - 1; i++)
    {
        min = inf;
        for (j = i; j < N; j++)
            if (a[j] < min)
            {
                min = a[j];
                pos = j;
            }
        temp = a[pos];
        a[pos] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int a[max_size] = {1, 3, 5, 10, 12, 13, 15, 6, 11, 19};
    int N = 10;
    int *p;
    p = &a[0];
    Bubble_Sort(p, N);
    Insertion_Sort(p, N);
    Selection_Sort(p,N);
    return 0;
}