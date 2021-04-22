#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max_size 63
#define min_Weight -1
#define ASCII_max 128

typedef struct TreeNode *PtrT;
struct TreeNode
{
    char sym;
    int weight;
    int depth;
    PtrT left, right;
};

typedef struct Code *PtrC;
struct Code
{
    char code[max_size];
    int length;
};

PtrT Sym[max_size]; //最小堆
struct Code InputCode[max_size];
int SymWeight[ASCII_max];
int HeapSize;
int TotalBits;

//下滤
void PrecDown(int parent, int N)
{
    int child;
    PtrT temp = Sym[parent];
    for (; parent * 2 <= N; parent = child)
    {
        child = 2 * parent;
        if (child != N && Sym[child + 1]->weight < Sym[child]->weight)
            child = child + 1;
        if (temp->weight > Sym[child]->weight)
            Sym[parent] = Sym[child];
        else
            break;
    }
    Sym[parent] = temp;
    return;
}

//建堆
void BulidHeap()
{
    int i;
    Sym[0] = (PtrT)malloc(sizeof(struct TreeNode));
    Sym[0]->weight = min_Weight; //设置哨兵
    for (i = 1; i <= HeapSize; i++)
    {
        Sym[i] = (PtrT)malloc(sizeof(struct TreeNode));
        scanf("\n%c %d", &Sym[i]->sym, &Sym[i]->weight);
        Sym[i]->left = Sym[i]->right = NULL;
        Sym[i]->depth = 0;
        SymWeight[(int)Sym[i]->sym] = Sym[i]->weight;
    }

    for (i = HeapSize - 1; i / 2 >= 1; i = i - 2)
        PrecDown(i / 2, HeapSize);
    return;
}

//删除堆元素
PtrT DeleteHeap()
{
    PtrT temp;
    temp = Sym[1];
    Sym[1] = Sym[HeapSize--];
    PrecDown(1, HeapSize);
    return temp;
}

//插入元素
void InsertHeap(PtrT h)
{
    int child;
    Sym[++HeapSize] = h;
    for (child = HeapSize; Sym[child / 2]->weight > h->weight; child = child / 2)
        Sym[child] = Sym[child / 2];
    Sym[child] = h;
    return;
}

//建树
PtrT BuildHuffmanTree()
{
    PtrT temp1, temp2, p;
    while (HeapSize >= 2)
    {
        temp1 = DeleteHeap();
        temp2 = DeleteHeap();
        p = (PtrT)malloc(sizeof(struct TreeNode));
        p->left = temp2;
        p->right = temp1;
        p->weight = temp1->weight + temp2->weight;
        p->depth = 0;
        InsertHeap(p);
    }
    return DeleteHeap();
}

//根节点:给子结点编码，传递给子结点。length为当前结点的编码长度。
void UpdataDepth(PtrT t, int depth)
{
    if (t)
    {
        t->depth = depth;
        if (!t->left && !t->right)
            TotalBits = TotalBits + depth * t->weight;
        UpdataDepth(t->left, depth + 1);
        UpdataDepth(t->right, depth + 1);
    }
    return;
}

int main()
{
    int N, M, i, j, k, m, n, flag;
    char InputC;
    char tempCode[max_size];
    int tempTotalBits;
    PtrT root = NULL;
    scanf("%d", &N);
    //建霍夫曼树
    HeapSize = N;
    BulidHeap();
    root = BuildHuffmanTree();
    //计算总比特数
    TotalBits = 0;
    UpdataDepth(root, 0);
    //检查编码：检查比特数，检查前缀码
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        flag = 1;
        tempTotalBits = 0;
        for (j = 0; j < N; j++)
        {
            scanf("\n%c %s", &InputC, &InputCode[j].code);
            InputCode[j].length = strlen(InputCode[j].code);
            tempTotalBits += SymWeight[(int)InputC] * InputCode[j].length;
        }
        if (tempTotalBits != TotalBits)
            flag = 0;
        else
        {
            for (k = 0; k < N; k++)
            {
                if (!flag)
                    break;
                for (m = k + 1; m < N; m++)
                {
                    if (!flag)
                        break;
                    if (InputCode[m].length >= InputCode[k].length)
                    {
                        for (n = 0; n < InputCode[k].length; n++)
                            tempCode[n] = InputCode[m].code[n];
                        tempCode[n] = '\0';
                        if (strcmp(tempCode, InputCode[k].code) == 0)
                            flag = 0;
                    }
                    else
                    {
                        for (n = 0; n < InputCode[m].length; n++)
                            tempCode[n] = InputCode[k].code[n];
                        tempCode[n] = '\0';
                        if (strcmp(tempCode, InputCode[m].code) == 0)
                            flag = 0;
                    }
                }
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

/*
反思：
1.没必要建堆，优化建树过程，一方面因为输入数据量不大，另一方面检查前缀码的复杂度为O(N^2)
2.建立哈夫曼树只是为了得到最小WPL，因此可以选择更简洁的方法：
    1)单写一个函数寻找权值最小的两个根节点
    2)简化数据结构，不需要记录左右子结点，只记录结点的父节点
    3)在循环过程中计算WPL,每取两个结点就把权值的和加到WPL上
*/