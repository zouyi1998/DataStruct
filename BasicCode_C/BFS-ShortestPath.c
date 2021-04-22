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
int Ne, Nv, front, rear, top;
int dist[maxVertexNum];
int queue[maxVertexNum];
int path[maxVertexNum];
int stack[maxVertexNum];


//无权图单源最短路径-BFS：有向图无向图都适用，这里输入为无向图
void ShortestPath(int s)
{
    int V;
    PtrE p;
    queue[++rear] = s;
    dist[s] = 0;
    while (front != rear)
    {
        V = queue[++front];
        p = g[V]->next;
        while (p)
        {
            if(dist[p->AdjV] == -1)
            {
                path[p->AdjV] = V;
                dist[p->AdjV] = dist[V]+1;
                queue[++rear] = p->AdjV;
            }
            p = p->next;
        }
    }
    return;
}

//打印最短路径：
void PrintShortestPath(int des)
{
    //初始化堆栈
    int top = -1;
    stack[++top] = des;
    while(path[des]!=-1)
    {
        stack[++top] = path[des];
        des = path[des];
    }
    printf("\n");
    while (top!=-1)
        printf("%d ", stack[top--]);
    return;
}

int main()
{
    int i, j, v1, v2;
    PtrE newENode;
    scanf("%d %d", &Nv, &Ne);
    //初始化指针数组,dist数组, path数组，队列
    for (i = 0; i < Nv; i++)
    {
        g[i] = (PtrE)malloc(sizeof(struct ENode));
        g[i]->next = NULL;
        dist[i] = -1;
        path[i] = -1;
    }
    front = rear = -1;
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
    ShortestPath(1);
    PrintShortestPath(4);
    return 0;
}