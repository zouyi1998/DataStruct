#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode *PtrHT;
struct TreeNode
{
    int weight;
    PtrHT left, right;
};

typedef struct MinHeap *PtrHeap;
struct MinHeap
{
    PtrHT *array;
    int size;
    int capacity;
};

PtrHeap EmptyHeap();
bool IsEmpty(PtrHeap h);
bool IsFull(PtrHeap h);
void Insert(PtrHT ht, PtrHeap h);
PtrHT ReturnMin(PtrHeap h);

//建立霍夫曼树
PtrHeap CreateHuffmanTree()
{
    PtrHT ht;
    PtrHeap heap = EmptyHeap();
    PtrHT p1, p2;
    if (IsEmpty(heap))
        return NULL;
    else if (heap->size == 1)
        return ReturnMin(heap);
    else
    {
        while (heap->size >= 2)
        {
            ht = (PtrHT)malloc(sizeof(struct TreeNode));
            p1 = ReturnMin(heap);
            p2 = ReturnMin(heap);
            ht->left = p1;
            ht->right = p2;
            ht->weight = p1->weight + p2->weight;
            Insert(ht, heap);
        }
        return ht;
    }
}