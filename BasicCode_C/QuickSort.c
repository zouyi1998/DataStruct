#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_size 10

int Median3(int *A, int left, int right)
{
    int center, temp;
    center = (left + right) / 2;
    if (A[left] > A[center])
    {
        temp = A[left];
        A[left] = A[center];
        A[center] = temp;
    }
    if (A[right] < A[center])
    {
        temp = A[right];
        A[right] = A[center];
        A[center] = temp;
    }
    if (A[left] > A[center])
    {
        temp = A[center];
        A[center] = A[left];
        A[left] = temp;
    }
    temp = A[right-1];
    A[right-1] = A[center];
    A[center] = temp;
    return right-1;
}

void Quick_Sort(int *A, int L, int R)
{
    if (R-L+1 < 2)
        return;
    int pos = Median3(A, L, R);
    int i, j, temp;
    i = L-1;
    j = R-1;
    while (1)
    {
        while(A[++i]<A[pos]) ;
        while(A[--j]>A[pos]) ;
        if(i>j)
            break;
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    temp = A[pos];
    A[pos] = A[i];
    A[i]= temp;
    Quick_Sort(A, L, i-1);
    Quick_Sort(A, i+1, R);
    return;
}

//统一函数接口
void sort(int *A, int N)
{
    Quick_Sort(A, 0, N-1);
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