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
int Ne, Nv, front, rear, top;
bool visit[maxVertexNum];
int dist[maxVertexNum];
int queue[maxVertexNum];
int path[maxVertexNum];
int stack[maxVertexNum];

//有权图单源最短路-Dijkstra：复杂度O(V^2+E)
//dist数组可用最小堆实现 复杂度为O(NlogN+ElogN)
void Dijkstra()
{
    int V, min, i;
    PtrE p;
    while (1)
    {
        min = inf;
        for (i = 0; i < Nv; i++)
            if (!visit[i] && dist[i] < min) //最小堆实现：取出顶部元素，末位元素替代，下沉
            {
                min = dist[i];
                V = i;
            }
        if (min == inf)
            break;
        else
        {
            visit[V] = true;
            p = g[V]->next;
            while (p)
            {
                if (!visit[p->AdjV] && dist[p->AdjV] > dist[V] + p->Weight)
                {
                    dist[p->AdjV] = dist[V] + p->Weight;
                    path[p->AdjV] = V;
                    //使用最小堆实现：查，改，上浮（减小）
                }
                p = p->next;
            }
        }
    }
}

//打印最短路径
void PrintShortestPath(int des)
{
    //初始化堆栈
    int top = -1;
    stack[++top] = des;
    while (path[des] != -1)
    {
        stack[++top] = path[des];
        des = path[des];
    }
    printf("\n");
    while (top != -1)
        printf("%d ", stack[top--]);
    return;
}

int main()
{
    int i, j, v1, v2, weight, s;
    PtrE newENode, p;
    scanf("%d %d", &Nv, &Ne);
    //初始化图,dist数组, path数组
    for (i = 0; i < Nv; i++)
    {
        g[i] = (PtrE)malloc(sizeof(struct ENode));
        g[i]->next = NULL;
        visit[i] = false;
        dist[i] = inf;
        path[i] = -1;
    }
    front = rear = -1;
    //插入边
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d %d", &v1, &v2, &weight);
        newENode = (PtrE)malloc(sizeof(struct ENode));
        newENode->AdjV = v2;
        newENode->Weight = weight;
        newENode->next = g[v1]->next;
        g[v1]->next = newENode;
    }
    //初始化源点
    s = 0;
    dist[s] = 0;
    visit[s] = true;
    p = g[s]->next;
    while (p)
    {
        dist[p->AdjV] = p->Weight;
        path[p->AdjV] = s;
        p = p->next;
    }
    Dijkstra();
    PrintShortestPath(4);
    return 0;
}