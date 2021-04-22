#include <stdio.h>
#include <stdlib.h>

#define max_size 10
//按大小合并
void Merge(int *A, int *tempA, int L, int R, int RightEnd)
{
    int LeftEnd, Num, tmp, i;
    LeftEnd = R - 1;
    Num = RightEnd - L + 1;
    tmp = L;
    while (L <= LeftEnd && R <= RightEnd)
    {
        if (A[L] <= A[R])
        {
            tempA[tmp++] = A[L++];
        }
        else
        {
            tempA[tmp++] = A[R++];
        }
    }
    while (L <= LeftEnd)
        tempA[tmp++] = A[L++];
    while (R <= RightEnd)
        tempA[tmp++] = A[R++];
    for (i = 0; i < Num; i++, RightEnd--)
        A[RightEnd] = tempA[RightEnd];
}

//归并排序-递归实现
void MSort(int *A, int *tempA, int L, int R)
{
    int mid;
    if (L < R)
    {
        mid = (L + R) / 2;
        MSort(A, tempA, L, mid);
        MSort(A, tempA, mid + 1, R);
        Merge(A, tempA, L, mid + 1, R);
    }
    return;
}

//统一函数接口
void sort(int *A, int N)
{
    int *tempA;
    tempA = (int*)malloc( sizeof(int)*N );
    MSort(A, tempA, 0, N-1);
    free(tempA);
    return;
}


int main()
{
    int a[max_size] = {1, 3, 5, 10, 12, 13, 15, 6, 11, 19};
    int N = 10;
    int *p;
    p = &a[0];
    sort(p,N);
    return 0;
}