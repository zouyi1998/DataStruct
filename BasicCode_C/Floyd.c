#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxVertexNum 5
#define inf 0xffff
int g[maxVertexNum][maxVertexNum];
int D[maxVertexNum][maxVertexNum];
int path[maxVertexNum][maxVertexNum];
int Ne, Nv;

//有权图多源最短路-Floyd O(V^3)
void Floyd()
{
    int i, j, k;
    for(k = 0;k<Nv;k++)
        for(i = 0;i<Nv;i++)
            for(j=0;j<Nv;j++)
                if(D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = k;
                }
}
//打印路径
void PrintShortestPath(int src, int des)
{
    int V = path[src][des];
    if(V == -1)
    {
        printf(" %d", des);
    }
    else
    {
        PrintShortestPath(src, V);
        PrintShortestPath(V, des);
    }
    return;
}

int main()
{
    //距离矩阵的初始化分为3步：1.初值inf 2.直接相连的边设置为对应权重 3.对角线设置为零
    int i, j, v1, v2, weight, src, des;
    scanf("%d %d", &Nv, &Ne);
    //初始化图，visit数组
    for (i = 0; i < Nv; i++)
        for (j = 0; j < Nv; j++)
        {
            g[i][j] = 0;
            D[i][j] = inf; //距离矩阵初始值为inf
            path[i][j] = -1;
        }

    //插入边
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d %d", &v1, &v2, &weight);
        g[v1][v2] = weight;
        D[v1][v2] = weight;  //ֱ直接相连的边设为对应权重
    }
    src = 0;
    des = 3;
    for (i = 0; i < Nv; i++)
        D[i][i] = 0; //距离矩阵对角线均为0
    Floyd();
    printf("%d", src);
    PrintShortestPath(src, des);
    return 0;
}