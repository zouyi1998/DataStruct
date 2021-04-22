#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxVertexNum 5
#define inf 0xffff

typedef struct ENode *PtrE;
struct ENode
{
    int AdjV;
    int Weight;
    PtrE next;
};

PtrE g[maxVertexNum];
int Ne, Nv;
int dist[maxVertexNum];//dist使用数组实现，也可用堆实现适合于稀疏图
int parent[maxVertexNum]; //生成树中的连接关系

//稀疏图最小生成树-Prim：仅适合于无向图
void Prim()
{
    int i, MstSize, V, min;
    PtrE p;
    MstSize = 1;
    while (1)
    {
        min = inf;
        for (i = 0; i < Nv; i++)
            if (dist[i] && dist[i] < min)
            {
                min = dist[i];
                V = i;
            }
        if (min == inf)
            break;
        else
        {
            dist[V] = 0;
            MstSize++;
            p = g[V]->next;
            while (p)
            {
                if (dist[p->AdjV] && dist[p->AdjV] > p->Weight)
                {
                    dist[p->AdjV] = p->Weight;
                    parent[p->AdjV] = V;
                }
                p = p->next;
            }
        }
    }
    if (MstSize != Nv)
        printf("Cannot Found Minimum Spaning Tree");
}

int main()
{
    int i, j, v1, v2, weight, s;
    PtrE newENode, p;
    scanf("%d %d", &Nv, &Ne);
    //初始化指针数组,dist数组, path数组，队列
    for (i = 0; i < Nv; i++)
    {
        g[i] = (PtrE)malloc(sizeof(struct ENode));
        g[i]->next = NULL;
        dist[i] = inf;
        parent[i] = -1;
    }
    //插入边
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d %d", &v1, &v2, &weight);
        newENode = (PtrE)malloc(sizeof(struct ENode));
        newENode->AdjV = v2;
        newENode->Weight = weight;
        newENode->next = g[v1]->next;
        g[v1]->next = newENode;
        newENode = (PtrE)malloc(sizeof(struct ENode));
        newENode->AdjV = v1;
        newENode->Weight = weight;
        newENode->next = g[v2]->next;
        g[v2]->next = newENode;
    }
    //设置根结点，dist数组初始化
    s = 0;
    dist[0] = 0;
    p = g[s]->next;
    while (p)
    {
        dist[p->AdjV] = p->Weight;
        parent[p->AdjV] = s;
        p = p->next;
    }
    Prim();
    return 0;
}