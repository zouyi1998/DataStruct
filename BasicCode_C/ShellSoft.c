#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_size 10

//希尔排序：采用Hibbard增量序列 2^k-1
void Shell_Soft(int *A, int N)
{
    int i, j, k, D, temp;
    for(k = log2(N+1);k>=1;k--)
    {
        D = pow(2,k)-1;
        for(i=D;i<N;i= i+D)
        {
            temp = A[i];
            for(j=i;j>=D && A[j-D] > temp; j= j-D)
                A[j] = A[j-D];
            A[j] = temp;
        }
    }
    return;
}


int main()
{
    int a[max_size] = {1, 3, 5, 10, 12, 13, 15, 6, 11, 19};
    int N = 10;
    int *p;
    p = &a[0];
    Shell_Soft(p, N);
    return 0;
}