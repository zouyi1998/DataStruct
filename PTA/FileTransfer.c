#include <stdio.h>
#include <stdbool.h>
#define max_size 10000

int Net[max_size + 1];
int SetNum;

int Find(int n)
{
    int root;
    root = n;
    for (; Net[root] > 0 ; root = Net[root])
        ;
    return root;
}

void Union(int n1, int n2)
{
    int root1, root2, size1, size2;
    root1 = Find(n1);
    root2 = Find(n2);
    if (root1 == root2)
        return;
    else
    {
        size1 = -Net[root1];
        size2 = -Net[root2];
        if (size1 > size2) //路径压缩
        {
            Net[root2] = root1;
            Net[root1] = -(size1 + size2);
        }
        else
        {
            Net[root1] = root2;
            Net[root2] = -(size1 + size2);
        }
        SetNum--;
        return;
    }
}

bool Check(int n1, int n2)
{
    int root1, root2;
    root1 = Find(n1);
    root2 = Find(n2);
    if (root1 == root2)
        return true;
    else
        return false;
}

int main()
{
    int N, Node1, Node2, i;
    char C;
    scanf("%d", &N);
    //初始化网络
    for (i = 1; i <= N; i++)
        Net[i] = -1;
    SetNum = N; //初始集合数等于结点数
    while (1)
    {
        scanf("%c", &C);
        if (C != 'S')
        {
            scanf("%d %d", &Node1, &Node2);
            if (C == 'I')
                Union(Node1, Node2);
            if (C == 'C')
            {
                if (Check(Node1, Node2))
                    printf("yes\n");
                else
                    printf("no\n");
            }
        }
        else
        {
            if (SetNum == 1)
                printf("The network is connected.");
            else
                printf("There are %d components.", SetNum);
            break;
        }
    }
    return 0;
}