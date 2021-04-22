#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_size 10

typedef struct TreeNode *PtrT;
struct TreeNode
{
    int data;
    PtrT left, right;
};

struct TreeNode T[max_size];
int N, front, rear;
int queue[max_size];
PtrT root;

void Read()
{
    int i;
    char l, r;
    bool findroot[max_size];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        findroot[i] = true;
    for (i = 0; i < N; i++)
    {
        scanf("\n%c %c", &l, &r);
        T[i].data = i;
        if (l == '-')
            T[i].left = NULL;

        else
        {
            T[i].left = &T[(int)l - 48];
            findroot[(int)l - 48] = false;
        }
        if (r == '-')
            T[i].right = NULL;

        else
        {
            T[i].right = &T[(int)r - 48];
            findroot[(int)r - 48] = false;
        }
    }
    for (i = 0; i < N; i++)
        if (findroot[i])
            root = &T[i];
}

void PrintLeaves()
{
    int t, flag;
    flag = 1;
    front = rear = -1;
    queue[++rear] = root->data;
    while (front != rear)
    {
        t = queue[++front];
        if (!T[t].left && !T[t].right)
        {
            if (flag)
            {
                printf("%d", t);
                flag = 0;
            }
            else{
                printf(" %d", t);
            }
        }
        if(T[t].left)
            queue[++rear] = T[t].left->data;
        if(T[t].right)
            queue[++rear] = T[t].right->data;
    }
}

int main()
{
    Read();
    PrintLeaves();
    return 0;
}