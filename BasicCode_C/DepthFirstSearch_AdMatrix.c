#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxVertexNum 5
int g[maxVertexNum][maxVertexNum];
bool visit[maxVertexNum];
int Ne, Nv;

//深度优先搜索-邻接矩阵 O(N^2)
void DFS(int s)
{
    int i;
    visit[s] = true;
    for (i = 0; i < Nv; i++)
        if (g[s][i] && !visit[i])
            DFS(i);
    return;
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
    //插入边
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d", &v1, &v2);
        g[v1][v2] = g[v2][v1] = 1;
    }
    DFS(4);
    return 0;
}