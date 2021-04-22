#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_size 10

typedef struct HeapStruct *MaxHeap;
struct HeapStruct
{
    int *array;
    int size;
    int capacity;
};

//下沉:parent结点下沉
void Down(int parent, MaxHeap h)
{
    int child, temp;
    temp = h->array[parent];
    for (; parent * 2 <= h->size; parent = child)
    {
        child = parent * 2;
        if (child != h->size && h->array[child + 1] > h->array[child])
            child = child + 1;
        if (temp >= h->array[child])
            break;
        else
            h->array[parent] = h->array[child];
    }
    h->array[parent] = temp;
}
//上浮:child结点上浮
void Up(int child, MaxHeap h)
{
    int parent, temp;
    temp = h->array[child];
    for(;h->array[child/2] < temp; child = child/2 ) 
        h->array[child] = h->array[child/2];
    h->array[child] = temp;
}
//创建空堆
MaxHeap EmptyMaxHeap()
{
    MaxHeap p = (MaxHeap)malloc(sizeof(struct HeapStruct));
    p->capacity = max_size + 1;
    p->size = 0;
    p->array = (int *)malloc(sizeof(int) * p->capacity);
    p->array[0] = 1000; //设置哨兵
    return p;
}

//最大堆的建立：采用方法2
//方法1：创建空堆，依次插入，复杂度O(NlogN)
//方法2：按输入顺序插入，再调整成最大堆，复杂度O(N)
MaxHeap CreateMaxHeap(int size)
{
    MaxHeap h = EmptyMaxHeap();
    int i, parent, temp, child;
    h->size = size;
    for (i = 1; i <= size; i++)
        scanf("%d", &h->array[i]);
    i = size;
    for (; i / 2 != 0; i = i - 2)
        Down(i/2, h);
    return h;
}

//判断堆满
bool IsFull(MaxHeap h)
{
    if (h->size == h->capacity)
        return true;
    else
        return false;
}

//判断堆空
bool IsEmpty(MaxHeap h)
{
    if (h->size == 0)
        return true;
    else
        return false;
}

//插入：在堆末尾插入上浮
//时间复杂度：O(log(n))
void Insert(int x, MaxHeap h)
{
    int *p = h->array;
    int i;
    if (IsFull(h))
        return;
    else
    {
        p[++h->size] = x;
        Up(h->size,h);
        return;
    }
}
//返回最大元素：返回并删除堆顶元素，将末尾元素移动到顶部，顶部元素下沉
//时间复杂度：O(log(n))
int ReturnMax(MaxHeap h)
{
    int temp, parent, child, maxItem;
    int *p;
    p = h->array;
    if (IsEmpty(h))
        return p[0];
    else
    {
        maxItem = p[1];
        p[1] = p[h->size--];
        Down(1, h);
        return maxItem;
    }
}
int main()
{
    int out;
    MaxHeap h = CreateMaxHeap(8);
    // for (int i = 1; i < 10; i++)
    //     Insert(i, h);
    out = ReturnMax(h);
    out = ReturnMax(h);
    out = ReturnMax(h);
    Insert(15, h);
    Insert(8, h);
    out = ReturnMax(h);
    return 0;
}