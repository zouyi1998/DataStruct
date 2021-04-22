#include <stdio.h>
#include <stdlib.h>

#define max_size 10
//子列归并:相比于递归算法有修改，为减少复制运算，将A数组数据归并后存于tempA中
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
    return;
}

//单次归并
void Merge_Single(int *A, int *tempA, int length, int N)
{
    int i;
    for (i = 0; i < N - 2 * length; i = i + 2 * length)
        Merge(A, tempA, i, i + length, i + 2 * length - 1);
    if (N - i >= length+1) //数组剩余长度大于等于length+1,再进行一次归并
        Merge(A, tempA, i, i + length, N-1);
    else
        for (; i < N; i++) //若数组长度小于length+1, 则将A中元素复制导tempA中
            tempA[i] = A[i];
    return;
}

//归并排序
void MSort(int *A, int *tempA, int N)
{
    int length = 1; //子列长度
    while (length <= N / 2)
    {
        Merge_Single(A, tempA, length, N);
        length *= 2;
        Merge_Single(tempA, A, length, N);
        length *= 2;
    }
    return;
}

//统一函数接口
void sort(int *A, int N)
{
    int *tempA;
    tempA = (int*)malloc(sizeof(int)*N); //申请的数组空间越界不会报错，free时会报错
    MSort(A, tempA, N);
    free((void *)tempA);
    return;
}

int main()
{
    int a[max_size] = {1, 3, 5, 10, 12, 13, 15, 6, 11, 19};
    int N = 10;
    int *p;
    p = &a[0];
    sort(p, N);
    return 0;
}