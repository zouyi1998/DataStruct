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
int Ne, Nv, front, rear;
bool visit[maxVertexNum];
int queue[maxVertexNum];

//广度优先搜索-邻接表 O(N+E)
void BFS(int s)
{
    PtrE p;
    int V;
    queue[++rear] = s;
    visit[s] = true;
    while (front != rear)
    {
        V = queue[++front];
        p = g[V]->next;
        while (p)
        {
            if (!visit[p->AdjV])
            {
                visit[p->AdjV] = true;
                queue[++rear] = p->AdjV;
            }
            p = p->next;
        }
    }
}

int main()
{
    int i, j, v1, v2;
    PtrE newENode;
    scanf("%d %d", &Nv, &Ne);
    //初始化图，visit数组
    for (i = 0; i < Nv; i++)
    {
        g[i] = (PtrE)malloc(sizeof(struct ENode));
        g[i]->next = NULL;
        visit[i] = false;
    }
    front = rear = -1;
    //插入边：无向图
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
    BFS(0);
    return 0;
}