#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define max_size 11
//多文件遍历
//1. gcc file1.c file2.c 
//2. 命令行执行exe

//二叉树-链式存储
typedef struct TreeNode *BinTree; //BinTree 二叉树
struct TreeNode{
    char data;
    BinTree left;
    BinTree right;
    int flag; //记录进栈次数，用于非递归后序遍历
};

typedef struct Stack *PtrS;

//栈-链式存储
struct Stack
{
    BinTree data;
    PtrS next;
};

typedef struct Stack *PtrS; 

PtrS EmptyStack();
bool IsEmpty(PtrS s);
void Push(BinTree x, PtrS s);
BinTree Pop(PtrS s);

//队列
BinTree queue[max_size];
int front = -1;
int rear = -1;


//创建二叉树
BinTree CreateBinTree()
{   
    BinTree root;
    //A
    BinTree pa;
    pa = (BinTree)malloc( sizeof(struct TreeNode));
    pa->data = 'A';
    pa->flag = 0;
    pa->left = pa->right = NULL;
    //B
    BinTree pb;
    pb = (BinTree)malloc(sizeof(struct TreeNode));
    pb->data = 'B';
    pa->flag = 0;
    pb->left = pb->right = NULL;
    pa->left = pb;
    //C
    BinTree pc;
    pc = (BinTree)malloc(sizeof(struct TreeNode));
    pc->data = 'C';
    pa->flag = 0;
    pc->left = pc->right = NULL;
    pa->right = pc;
    //D
    BinTree pd;
    pd = (BinTree)malloc(sizeof(struct TreeNode));
    pd->data = 'D';
    pa->flag = 0;
    pd->left = pd->right = NULL;
    pb->left = pd;
    //F
    BinTree pf;
    pf = (BinTree)malloc(sizeof(struct TreeNode));
    pf->data = 'F';
    pa->flag = 0;
    pf->left = pf->right = NULL;
    pb->right = pf;
    //E
    BinTree pe;
    pe = (BinTree)malloc(sizeof(struct TreeNode));
    pe->data = 'E';
    pa->flag = 0;
    pe->left = pe->right = NULL;
    pf->left = pe;
    //G
    BinTree pg;
    pg = (BinTree)malloc(sizeof(struct TreeNode));
    pg->data = 'G';
    pa->flag = 0;
    pg->left = pg->right = NULL;
    pc->left = pg;
    //I
    BinTree pi;
    pi = (BinTree)malloc(sizeof(struct TreeNode));
    pi->data = 'I';
    pa->flag = 0;
    pi->left = pi->right = NULL;
    pc->right = pi;
    //H
    BinTree ph;
    ph = (BinTree)malloc(sizeof(struct TreeNode));
    ph->data = 'H';
    pa->flag = 0;
    ph->left = ph->right = NULL;
    pg->right = ph;
    return pa;
}

//先序遍历-递归实现
void PreOrderTraversal_Recursion(BinTree t){
    if(!t) return;
    printf("%c ", t->data);
    PreOrderTraversal_Recursion(t->left);
    PreOrderTraversal_Recursion(t->right);
    return;
}

//中序遍历-递归实现
void InOrderTraversal_Recursion(BinTree t){
    if(!t) return;
    InOrderTraversal_Recursion(t->left);
    printf("%c ", t->data);
    InOrderTraversal_Recursion(t->right);
    return;
}

//后序遍历-递归实现
void PostOrderTraversal_Recursion(BinTree t){
    if(!t) return;
    PostOrderTraversal_Recursion(t->left);
    PostOrderTraversal_Recursion(t->right);
    printf("%c ", t->data);
    return;
}

//先序遍历-非递归实现
void PreOrderTraversal(BinTree bt){
    PtrS s;
    BinTree t = bt;
    s = EmptyStack();
    while (t || !IsEmpty(s))
    {
        while(t)
        {
            printf("%c ", t->data);
            Push(t,s);
            t = t->left;
        }
        if(!IsEmpty(s))
        {
            t = Pop(s);
            t = t->right;
        }
    }
    
}

//中序遍历-非递归实现
void InOrderTraversal(BinTree bt){
    PtrS s;
    BinTree t = bt;
    s = EmptyStack();
    while (t || !IsEmpty(s)) //t不为空 且 栈不为空
    {
        while(t)
        {
            Push(t,s);
            t = t->left;
        }
        if(!IsEmpty(s))
        {
            t = Pop(s);
            printf("%c ", t->data);
            t = t->right;  //当t的右子树为空时，会直接到if语句
        }
    }
    
}

//后序遍历-费递归实现：flag记录进栈次数
void PostOrderTraversal(BinTree bt){
    BinTree t = bt;
    PtrS s;
    s = EmptyStack();
    while(t || !IsEmpty(s))
    {
        while (t)
        {
            t->flag = t->flag + 1;
            Push(t, s);
            t = t->left;
        }
        if(!IsEmpty(s))
        {
            t = Pop(s);
            if(t->flag == 2)
            {
                printf("%c ", t->data);
                t->flag = 0;
                t = NULL;
            }
            else
            {
                if (t->right)
                {
                    t->flag = t->flag + 1;
                    Push(t, s);
                    t = t->right;
                }
                else{
                    printf("%c ", t->data);
                    t->flag = 0;
                }
            }
        }
    }
}

//层次遍历-非递归实现
void LevelOrderTraversal(BinTree bt){
    BinTree t = bt;
    if(t) //将根节点及其子结点入队
    {
        queue[++rear] = t;
    }
    else return;
    while(front != rear) //当队列不为空时
    {
        t = queue[++front];
        printf("%c ", t->data);
        if(t->left) queue[++rear] = t->left;
        if(t->right) queue[++rear] = t->right;
    }
}

//输出叶子结点
void PrintLeaves(BinTree bt){
    BinTree t = bt;
    if(t)
    {
        if(!t->left && !t->right)
            printf("%c ", t->data);
        PrintLeaves(t->left);
        PrintLeaves(t->right);
     
    }
    else return;
}

//二叉树高度
int GrtHeight(BinTree bt)
{
    BinTree t = bt;
    int hl,hr,h;
    hl = hr = h = 0;
    if(t)
    {
        hl = GrtHeight(t->left);
        hr = GrtHeight(t->right);
        h = hl>hr?hl:hr;
        return h+1;
    }
    return 0;
}

int main()
{
    BinTree T;
    int h;
    T = CreateBinTree();
    printf("FirstOrderTraversal:");
    PreOrderTraversal(T);
    printf("\nInOrderTraversal:");
    InOrderTraversal(T);
    printf("\nPostOrderTraversal:");
    PostOrderTraversal_Recursion(T);
    printf("\nLevelOrderTraversal:");
    LevelOrderTraversal(T);
    printf("\nPrintLeaves:");
    PrintLeaves(T);
    h = GrtHeight(T);
    printf("\nHeight:%d", h);
    return 0;
}




//----栈操作----
//创建空栈
PtrS EmptyStack(){
    PtrS p;
    p = (PtrS)malloc(sizeof(struct Stack));
    p->next = NULL;
    p->data = NULL;
    return p;
}

//判断栈空
bool IsEmpty(PtrS s){
    if(s->next == NULL)
        return true;
    else
        return false;
}

//入栈
void Push(BinTree x, PtrS s){
    PtrS p;
    p = (PtrS)malloc(sizeof(struct Stack));
    p->data = x;
    p->next = s->next;
    s->next = p;
    return;
}

//出栈
BinTree Pop(PtrS s){
    BinTree q;
    PtrS p;
    if(IsEmpty(s))
    {
        return NULL;
    }
    else
    {
        p = s->next;
        s->next = p->next;
        q = p->data;
        free(p);
        return q;
    }
}