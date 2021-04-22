#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxVertexNum 5
//无向图-邻接链表
//图结点
typedef struct GNode *PtrG;
struct GNode
{
    int Nv, Ne;
    PtrV G[maxVertexNum];
};

//顶点结点
typedef struct VNode *PtrV;
struct VNode
{
    int data;
    PtrE FirstEdge;
};
//边结点
typedef struct ENode *PtrE;
struct ENode
{
    int AdjV;
    int weight;
    PtrE next;
};

//建立空图
PtrG CreateGraph(int nv)
{
    int i;
    PtrG g = (PtrG)malloc(sizeof(struct GNode));
    g->Nv = nv;
    g->Ne = 0;
    for (i = 0; i < g->Nv; i++)
    {
        g->G[i] = (PtrV)malloc(sizeof(struct VNode));
        g->G[i]->FirstEdge = NULL;
    }

    return g;
}

//插入边
void InsertEdge(int V1, int V2, int weight, PtrG g)
{
    //插入v1,v2
    PtrE newEdge = (PtrE)malloc(sizeof(struct ENode));
    newEdge->AdjV = V2;
    newEdge->weight = weight;
    newEdge->next = g->G[V1]->FirstEdge;
    g->G[V1]->FirstEdge = newEdge;
    //插入v2,v1
    PtrE newEdge = (PtrE)malloc(sizeof(struct ENode));
    newEdge->AdjV = V1;
    newEdge->weight = weight;
    newEdge->next = g->G[V2]->FirstEdge;
    g->G[V2]->FirstEdge = newEdge;
}

//建图
PtrG BuildGraph()
{
    int nv, v1, v2, weight, i;
    scanf("%d", &nv);
    PtrG g = CreateGraph(nv);
    scanf("%d", &g->Ne);
    if (g->Ne != 0)
    {
        for (i = 0; i < g->Ne; i++)
        {
            scanf("%d %d %d", &v1, &v2, &weight);
            InsertEdge(v1, v2, weight, g);
        }
    }
    return g;
}
int main()
{
    return 0;
}