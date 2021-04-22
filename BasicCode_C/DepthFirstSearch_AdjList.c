#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxVertexNum 5

typedef struct ENode *PtrE;
struct ENode
{
    int AdjV;
    PtrE next;
};

PtrE g[maxVertexNum];
int Ne, Nv;
bool visit[maxVertexNum];

//广度优先搜索-邻接链表 O(V+E)
void DFS(int s)
{
    PtrE p;
    visit[s] = true;
    p = g[s]->next;
    while (p && !visit[p->AdjV])
    {
        DFS(p->AdjV);
        p = p->next;
    }
    return;
}

int main()
{
    int i, j, v1, v2;
    PtrE newENode;
    scanf("%d %d", &Nv, &Ne);
    //初始化指针数组
    for (i = 0; i < Nv; i++)
    {
        g[i] = (PtrE)malloc(sizeof(struct ENode));
        g[i]->next = NULL;
        visit[i] = false;
    }
    //插入边
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d", &v1, &v2);
        newENode = (PtrE)malloc(sizeof(struct ENode));
        newENode->AdjV = v2;
        newENode->next = g[v1]->next;
        g[v1]->next = newENode;
        newENode = (PtrE)malloc(sizeof(struct ENode));
        newENode->AdjV = v1;
        newENode->next = g[v2]->next;
        g[v2]->next = newENode;
    }
    DFS(0);
    return 0;
}