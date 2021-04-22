#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxVertexNum 5

typedef struct GNode *PtrG;
struct GNode
{
    int Nv;
    int Ne;
    int G[maxVertexNum][maxVertexNum];
    int data[maxVertexNum]; //存顶点数据
};

typedef struct ENode *PtrE;
struct ENode
{
    int V1, V2;
    int weight; //边权重
};

//创建空图:根据顶点数建图
PtrG CreateGraph(int VertexNum)
{
    int i, j;
    PtrG g = (PtrG)malloc(sizeof(struct GNode));
    g->Nv = VertexNum;
    g->Ne = 0;
    for (i = 0; i < VertexNum; i++)
        for (j = 0; j < VertexNum; j++)
            g->G[i][j] = 0;
    return g;
}

//插入边
void InsertEdge(PtrE e, PtrG g)
{
    g->G[e->V1][e->V2] = e->weight;
    g->G[e->V2][e->V1] = e->weight; //无向图
    g->Ne++;
}

//建图
PtrG BuildGraph()
{
    PtrG g;
    PtrE e;
    int nv, i;
    bool check1, check2;
    scanf("%d", &nv);
    g = CreateGraph(nv);
    scanf("%d", &g->Ne);
    if (g->Ne != 0)
    {
        e = (PtrE)malloc(sizeof(struct ENode));
        for (i = 0; i < g->Ne; i++)
        {
            scanf("%d %d %d", &e->V1, &e->V2, &e->weight);
            InsertEdge(e, g);
        }
    }
    //如果每个顶点有数据，读入数据
    return g;
}

//打印图
void PrintGraph(PtrG g)
{
    int i, j;
    for (i = 0; i < g->Nv; i++)
        for (j = 0; j < g->Nv; j++)
        {
            printf("%d", g->G[i][j]);
            if (j == g->Nv - 1)
                printf("\n");
            else
                printf(" ");
        }
}

int main()
{
    return 0;
}