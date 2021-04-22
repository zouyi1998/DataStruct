#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *BinTree;
struct TreeNode
{
    int data;
    BinTree left;
    BinTree right;
};

//创建二叉搜索树
BinTree CreateBinSTree()
{
    //A
    BinTree pa;
    pa = (BinTree)malloc(sizeof(struct TreeNode));
    pa->data = 10;
    pa->left = pa->right = NULL;
    //B
    BinTree pb;
    pb = (BinTree)malloc(sizeof(struct TreeNode));
    pb->data = 5;
    pb->left = pb->right = NULL;
    pa->left = pb;
    //C
    BinTree pc;
    pc = (BinTree)malloc(sizeof(struct TreeNode));
    pc->data = 15;
    pc->left = pc->right = NULL;
    pa->right = pc;
    //D
    BinTree pd;
    pd = (BinTree)malloc(sizeof(struct TreeNode));
    pd->data = 1;
    pd->left = pd->right = NULL;
    pb->left = pd;
    //F
    BinTree pf;
    pf = (BinTree)malloc(sizeof(struct TreeNode));
    pf->data = 7;
    pf->left = pf->right = NULL;
    pb->right = pf;
    //E
    BinTree pe;
    pe = (BinTree)malloc(sizeof(struct TreeNode));
    pe->data = 6;
    pe->left = pe->right = NULL;
    pf->left = pe;
    //G
    BinTree pg;
    pg = (BinTree)malloc(sizeof(struct TreeNode));
    pg->data = 12;
    pg->left = pg->right = NULL;
    pc->left = pg;
    //I
    BinTree pi;
    pi = (BinTree)malloc(sizeof(struct TreeNode));
    pi->data = 16;
    pi->left = pi->right = NULL;
    pc->right = pi;
    //H
    BinTree ph;
    ph = (BinTree)malloc(sizeof(struct TreeNode));
    ph->data = 13;
    ph->left = ph->right = NULL;
    pg->right = ph;
    return pa;
}
//查找元素x-递归实现:尾递归效率低，可改成非递归实现
BinTree FindX(int x, BinTree bt)
{
    BinTree t = bt;
    if (bt)
        return NULL;
    if (x > t->data)
        return FindX(x, t->right);
    else if (x < t->data)
        return FindX(x, t->left);
    else
        return t;
}
//查找元素x-非递归实现
BinTree FindX2(int x, BinTree bt)
{
    BinTree t = bt;
    while (t)
    {
        if (x > t->data)
            t = t->right;
        else if (x < t->data)
            t = t->left;
        else
            return t;
    }
    return NULL;
}
//查找最小
BinTree FindMin(BinTree bt)
{
    BinTree t = bt;
    if (t->left)
        return FindMin(t->left);
    else
        return t;
}
//查找最大
BinTree FindMax(BinTree bt)
{
    BinTree t = bt;
    if (t->right)
        return FindMax(t->right);
    else
        return t;
}
//插入：相同元素插在右边
BinTree Insert(int x, BinTree bt)
{
    BinTree t = bt;
    BinTree p;
    if (t)
    {
        if (x < t->data)
            t->left = Insert(x, t->left);
        else if (x > t->data)
            t->right = Insert(x, t->right);
        else //考虑相等的情况
        {
            p = (BinTree)malloc(sizeof(struct TreeNode));
            p->data = x;
            p->right = t->right;
            p->left = NULL;
            t->right = p;
        }
    }
    else
    {
        p = (BinTree)malloc(sizeof(struct TreeNode));
        p->data = x;
        p->left = p->right = NULL;
        t = p;
    }
    return t;
}

//删除：
//1. 找左子树的最大或右子树的最小赋值给被删除结点
//2. 删除左子树最大或右子树最小
//删除左右都有子结点的结点->删除仅有单个子结点的结点
BinTree Delete(int x, BinTree bt)
{
    BinTree t = bt;
    BinTree temp;
    if (t)
    {
        if (x > t->data)
            t->right = Delete(x, t->right);
        else if (x < t->data)
            t->left = Delete(x, t->left);
        else
        {
            temp = t;
            if (!t->left)
            {
                t = t->right;
                free(temp); //注意释放空间！！！
            }
            else if (!t->right)
            {
                t = t->left;
                free(temp);
            }
            else
            {
                temp = FindMax(t->left);
                t->data = temp->data;
                t->left = Delete(temp->data, t->left);
            }
        }
        return t;
    }
    else
        return NULL;
}
//中序遍历：在二叉搜索树中即从小到大输出
void InOrderTraversal_Recursion(BinTree t)
{
    if (!t)
        return;
    InOrderTraversal_Recursion(t->left);
    printf("%d ", t->data);
    InOrderTraversal_Recursion(t->right);
    return;
}

int main()
{
    BinTree bt, p, min, max;
    bt = CreateBinSTree();
    InOrderTraversal_Recursion(bt);
    p = FindX(7, bt);
    min = FindMin(bt);
    max = FindMax(bt);
    Delete(15, bt);
    Delete(5, bt);
    printf("\n");
    InOrderTraversal_Recursion(bt);
    return 0;
}