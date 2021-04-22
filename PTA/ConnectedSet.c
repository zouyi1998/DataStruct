#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxVertexNum 10

int g[maxVertexNum][maxVertexNum];
bool visit[maxVertexNum];
int queue[maxVertexNum];
int front, rear;
int ConncetedSet[maxVertexNum];
int frontC, rearC;
int N, E;

void DFS(int s)
{
    int i;
    visit[s] = true;
    ConncetedSet[++rearC] = s;
    for (i = 0; i < N; i++)
        if (g[s][i] && !visit[i])
            DFS(i);
    return;
}

void PrintSet()
{
    printf("{ ");
    while (frontC != rearC)
        printf("%d ", ConncetedSet[++frontC]);
    printf("}\n");
    //重置队列
    frontC = rearC = -1;
}

void ConncetedSet_DFS()
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            DFS(i);
            PrintSet();
        }
    }
    return;
}

void BFS(int s)
{
    int v, i;
    queue[++rear] = s;
    visit[s] = true; //入队就算访问过
    ConncetedSet[++rearC] = s;
    while (front != rear)
    {
        v = queue[++front];
        for (i = 0; i < N; i++)
            if (g[v][i] && !visit[i])
            {
                queue[++rear] = i;
                visit[i] = true;
                ConncetedSet[++rearC] = i;
            }
    }
    return;
}

void ConncetedSet_BFS()
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            BFS(i);
            PrintSet();
        }
    }
    return;
}

int main()
{
    int i, j, v1, v2;
    scanf("%d %d", &N, &E);
    //初始化图,visit数组
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            g[i][j] = 0;
        }
        visit[i] = false;
    }
    //输入图
    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &v1, &v2);
        g[v1][v2] = g[v2][v1] = 1;
    }
    //初始化队列
    front = rear = -1;
    frontC = rearC = -1;
    //DFS输出连通图
    ConncetedSet_DFS();
    //初始化visit数组
    for (i = 0; i < N; i++)
        visit[i] = false;
    ConncetedSet_BFS();
    return 0;
}
