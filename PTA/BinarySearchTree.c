#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL)
            printf("%d is not found\n", X);
        else
        {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP)
                printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP)
                printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */

BinTree Insert(BinTree BST, ElementType X)
{
    BinTree p;
    if (BST)
    {
        if (X > BST->Data)
            BST->Right = Insert(BST->Right, X);
        else
            BST->Left = Insert(BST->Left, X);
    }
    else
    {
        p = (BinTree)malloc(sizeof(struct TNode));
        p->Data = X;
        p->Left = p->Right = NULL;
        BST = p;
    }
    return BST;
}

Position Find(BinTree BST, ElementType X)
{
    if (BST)
    {
        if (BST->Data == X)
            return BST;
        else
        {
            if (X > BST->Data)
                return Find(BST->Right, X);
            else
                return Find(BST->Left, X);
        }
    }
    else
        return NULL;
}

Position FindMax(BinTree BST)
{
    BinTree p = BST;
    if (BST)
    {
        while (p->Right)
            p = p->Right;
        return p;
    }
    else
        return NULL;
}

Position FindMin(BinTree BST)
{
    BinTree p = BST;
    if (BST)
    {
        while (p->Left)
            p = p->Left;
        return p;
    }
    else    
        return NULL;
}

//删除结点-非迭代实现
BinTree Delete(BinTree BST, ElementType X)
{
    BinTree p, temp, q, father;
    if (BST)
    {
        p = BST;
        father = p;
        while (p && p->Data != X)
        {
            father = p;
            if (X > p->Data)
                p = p->Right;
            else
                p = p->Left;
        }
        if (!p)
        {
            printf("Not Found\n");
            return BST;
        }
        else
        {
            if (!p->Right && p->Left)
            {
                if (father == p)
                {
                    temp = p->Left;
                    free(p);
                    return temp;
                }
                else
                {
                    temp = p->Left;
                    if (father->Left == p)
                        father->Left = temp;
                    else
                        father->Right = temp;
                    free(p);
                    return BST;
                }
            }
            else if (!p->Left && p->Right)
            {
                if (father == p)
                {
                    temp = p->Right;
                    free(p);
                    return temp;
                }
                else
                {
                    temp = p->Right;
                    if (father->Left == p)
                        father->Left = temp;
                    else
                        father->Right = temp;
                    free(p);
                    return BST;
                }
            }
            else if (!p->Left && !p->Right)
            {
                if (father == p)
                {
                    free(p);
                    return NULL;
                }
                else
                {
                    if (father->Left == p)
                        father->Left = NULL;
                    else
                        father->Right = NULL;
                    free(p);
                    return BST;
                }
            }
            else
            {
                //左子树的最大值
                q = p->Left;
                while (q->Right)
                    q = q->Right;
                p->Data = q->Data;
                Delete(p->Left, q->Data);
                return BST;
            }
        }
    }
    else
    {
        printf("Not Found\n");
        return NULL;
    }
}
