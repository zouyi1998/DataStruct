#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxVertexNum 5
int g[maxVertexNum][maxVertexNum];
bool visit[maxVertexNum];
int queue[maxVertexNum];
int Ne, Nv, front, rear;

//广度优先搜索-邻接矩阵 O(N^2)
void BFS(int s)
{
    int V, i;
    queue[++rear] = s;
    visit[s] = true;
    while (front != rear)
    {
        V = queue[++front];
        for (i = 0; i < Nv; i++)
            if (g[V][i] && !visit[i]) //未被访问的邻接点
            {
                queue[++rear] = i;
                visit[i] = true;
            }
    }
}
int main()
{
    int i, j, v1, v2;
    scanf("%d %d", &Nv, &Ne);
    //初始化图，visit数组
    for (i = 0; i < Nv; i++)
    {
        for (j = 0; j < Nv; j++)
            g[i][j] = 0;
        visit[i] = false;
    }
    //插入边：无向图
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d", &v1, &v2);
        g[v1][v2] = g[v2][v1] = 1;
    }
    //初始化队列
    front = rear = -1;
    BFS(4);
    return 0;
}