#include <stdio.h>
#include <stdlib.h>
#define max_size 10
#define radix 10

typedef struct BucketNode *PtrB;
struct BucketNode
{
    int data;
    PtrB next;
};

PtrB OnesPlace[radix];
PtrB TensPlace[radix];

void Radix_Sort(int *A, int N)
{
    int i, num;
    PtrB newNode, p;
    //初始化桶
    for (i = 0; i < radix; i++)
    {
        OnesPlace[i] = (PtrB)malloc(sizeof(struct BucketNode));
        OnesPlace[i]->next = NULL;
        TensPlace[i] = (PtrB)malloc(sizeof(struct BucketNode));
        TensPlace[i]->next = NULL;
    }
    //对个位排序
    for(i=0;i<N;i++)
    {
        num = A[i] % 10;
        newNode = (PtrB)malloc(sizeof(struct BucketNode));
        newNode->data = A[i];
        newNode->next = OnesPlace[num]->next;
        OnesPlace[num]->next = newNode;
    }
    //对十位排序：从个位大的开始访问，插入在十位链表第一位，使相同的十位的数个位从小到大排列
    for(i=radix-1;i>=0;i--)
    {
        p = OnesPlace[i]->next;
        while(p)
        {
            num = p->data/10 % 10; //取十位：将十位挪到个位，取个位
            newNode = (PtrB)malloc(sizeof(struct BucketNode));
            newNode->data = p->data;
            newNode->next = TensPlace[num]->next;
            TensPlace[num]->next = newNode;
            p = p->next;
        }
    }
    //打印出排列好的序列
    for(i = 0;i<radix;i++)
    {
        p = TensPlace[i]->next;
        while(p)
        {
            printf("%d ", p->data);
            p = p->next;
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
    Radix_Sort(p, N);
    return 0;
}