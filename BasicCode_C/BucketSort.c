#include <stdio.h>
#include <stdlib.h>
#define max_size 10
#define data_range 5

typedef struct BucketNode *PtrB;
struct BucketNode
{
    int data;
    PtrB next;
};

PtrB bucket[data_range + 1]; //数据范围0到5，应有6个桶

//桶排序
void Bucket_Sort(int *A, int N)
{
    int i;
    PtrB p;
    for (i = 0; i <= data_range; i++)
    {
        bucket[i] = (PtrB)malloc(sizeof(struct BucketNode));
        bucket[i]->next = NULL;
    }

    for (i = 0; i < N; i++)
    {
        p = (PtrB)malloc(sizeof(struct BucketNode));
        p->data = A[i];
        p->next = bucket[A[i]]->next;
        bucket[A[i]]->next = p;
    }
    for (i = 0; i <= data_range; i++)
    {
        p = bucket[i]->next;
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
    return;
}

int main()
{
    int a[max_size] = {1, 3, 5, 4, 3, 2, 3, 0, 5, 4};
    int N = 10;
    int *p;
    p = &a[0];
    Bucket_Sort(p, N);
    return 0;
}