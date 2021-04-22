#include <stdio.h>
#define max_size 10000
#define inf 0xffff

//元素下沉
void PercDown(int *a, int i, int N) //注意：无哨兵情况下，子结点与父结点的下标关系改变
{
    int parent, child, temp;
    temp = a[i];
    for (parent = i; (parent * 2 + 1) <= N - 1; parent = child)
    {
        child = parent * 2 + 1;
        if (child != N - 1 && a[child] < a[child + 1])
            child = child + 1;
        if (temp < a[child])
            a[parent] = a[child];
        else
            break;
    }
    a[parent] = temp;
}

//堆排序:a数组指针，i为根节点，N为数组总长度
void Heap_Sort(int a[], int N)
{
    int i, temp;
    for (i = N - 1;; i = i - 2)
    {
        PercDown(a, (i - 1) / 2, N);
        if ((i - 1) / 2 == 0)
            break;
    }
    for (i = N - 1; i >= 1; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        PercDown(a, 0, i);
    }
}

int main()
{
    int a[max_size] = {1, 3, 5, 10, 12, 13, 15, 6, 11, 19, 20};
    int N = 11;
    int *p;
    p = &a[0];
    Heap_Sort(p, N);
    // printf("%d", sizeof(int));
    return 0;
}