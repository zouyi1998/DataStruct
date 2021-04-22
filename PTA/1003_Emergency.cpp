#include <bits/stdc++.h>
using namespace std;

const int inf = 0x7fffffff; //int最大值！！！！
int N, M, src, des, pathNum;
vector<int> nodeWeight;
vector<vector<int>> graph;
unordered_multimap<int, int> path;
vector<bool> visit;
vector<int> dis;
vector<int> teamNum;

void dijkstra(int s)
{
    //初始化起点
    visit[src] = true;
    teamNum[src] = nodeWeight[src];
    dis[src] = 0;
    for (int i = 0; i < N; i++)
        if (graph[src][i])
        {
            dis[i] = graph[src][i];
            teamNum[i] = teamNum[src] + nodeWeight[i];
            path.insert(make_pair(i, src));
        }
    while (1)
    {
        int minDis, v;
        minDis = inf;
        for (int i = 0; i < N; i++)
            if (!visit[i] && dis[i] < minDis)
            {
                minDis = dis[i];
                v = i;
            }
        if (minDis == inf)
            break;
        else
        {
            visit[v] = true;
            for (int i = 0; i < N; i++)
                if (!visit[i] && graph[v][i])
                {
                    if (dis[i] > dis[v] + graph[v][i])
                    {
                        path.erase(i);                           //找到更小的路线，清空所有
                        path.insert(make_pair(i, v));            //加入路径
                        dis[i] = dis[v] + graph[v][i];           //更新最短路
                        teamNum[i] = nodeWeight[i] + teamNum[v]; //更新点权
                    }
                    else if (dis[i] == dis[v] + graph[v][i])
                    {
                        path.insert(make_pair(i, v));                //路径长度相同加入新的路径
                        if (teamNum[i] < nodeWeight[i] + teamNum[v]) //点权更大，则更新点权
                            teamNum[i] = nodeWeight[i] + teamNum[v];
                    }
                }
        }
    }
    return;
}

void countPath(int lastNode)
{
    if (lastNode != src)
    {
        int cnt = path.count(lastNode);
        pathNum += cnt - 1;
        unordered_multimap<int, int>::iterator iter = path.find(lastNode);
        for (int i = 0; i < cnt; i++, iter++)
            countPath(iter->second);
    }
    return;
}

int main()
{
    cin >> N >> M >> src >> des;
    //读入点权重
    for (int i = 0; i < N; i++)
    {
        int weight;
        cin >> weight;
        nodeWeight.push_back(weight);
    }
    //读入边权
    graph.insert(graph.begin(), N, vector<int>(N, 0));
    for (int i = 0; i < M; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1][v2] = graph[v2][v1] = weight;
    }
    //初始化数组
    visit.insert(visit.begin(), N, false);
    dis.insert(dis.begin(), N, inf);
    teamNum.insert(teamNum.begin(), N, 0);
    //dijkstra
    dijkstra(src);
    //对路径计数
    pathNum = 1;
    countPath(des);
    cout << pathNum << ' ' << teamNum[des] << endl;
    return 0;
}

/*
特殊情况如空，单个元素要在代码完成后在检验！！！
*/