#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;
const int maxn = 201;
unordered_map<string, int> string2int; //固定
string int2string[maxn];
int adjM[maxn][maxn];
int hpyN[maxn];
int dis[maxn]; //更新
int hpy[maxn];
int cityNum[maxn];
bool vis[maxn];
int pathNum[maxn];
int path[maxn];
int N, K; //常量
string src, des;

void Dijkstra(int src)
{
    fill(dis, dis+N+1, inf);
    fill(hpy, hpy+N+1, 0);
    fill(cityNum, cityNum+N+1, 0);
    fill(vis, vis+N+1, false);
    fill(pathNum, pathNum+N+1, 0);
    for (int i = 1; i <= N; i++)
        if (adjM[src][i])
        {
            dis[i] = adjM[src][i];
            hpy[i] = hpy[src] + hpyN[i];
            cityNum[i] = cityNum[src] + 1;
            pathNum[i] = 1;
            path[i] = src;
        }
    vis[src] = true;
    while (1)
    {
        int minDis, v;
        minDis = inf;
        for (int i = 1; i <= N; i++)
            if (!vis[i] && dis[i] < minDis)
            {
                minDis = dis[i];
                v = i;
            }
        if (minDis == inf)
            break;
        else
        {
            vis[v] = true;
            for (int i = 1; i <= N; i++)
                if (!vis[i] && adjM[v][i])
                {
                    if (dis[i] > dis[v] + adjM[v][i])
                    {
                        dis[i] = dis[v] + adjM[v][i];
                        hpy[i] = hpy[v] + hpyN[i];
                        cityNum[i] = cityNum[v] + 1;
                        pathNum[i] = pathNum[v];
                        path[i] = v;
                    }
                    else if (dis[i] == dis[v] + adjM[v][i] && hpy[i] < hpy[v] + hpyN[i])
                    {
                        hpy[i] = hpy[v] + hpyN[i];
                        cityNum[i] = cityNum[v] + 1;
                        pathNum[i] += pathNum[v];
                        path[i] = v;
                    }
                    else if (dis[i] == dis[v] + adjM[v][i] && hpy[i] == hpy[v] + hpyN[i] && cityNum[i] > cityNum[v] + 1)
                    {
                        cityNum[i] = cityNum[v] + 1;
                        pathNum[i] += pathNum[v];
                        path[i] = v;
                    }
                    else if (dis[i] == dis[v] + adjM[v][i])
                        pathNum[i] += pathNum[v];
                }
        }
    }
    return;
}

void PrintPath(int desInt)
{
    stack<int> s;
    int temp = desInt;
    while(temp!=1)
    {
        s.push(temp);
        temp = path[temp];
    }
    cout << src;
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        cout << "->" << int2string[temp];
    }
    return;
}

int main()
{
    cin >> N >> K;
    getchar();
    cin >> src;
    string2int[src] = 1;
    int2string[1] = src;
    hpyN[1] = 0;
    memset(adjM, 0, sizeof(adjM)); //初始化邻接矩阵
    for (int i = 2; i <= N; i++)   //读入点权
    {
        string city;
        int nodeW;
        getchar();
        cin >> city >> nodeW;
        string2int[city] = i;
        int2string[i] = city;
        hpyN[i] = nodeW;
    }
    for (int i = 0; i < K; i++) //读入边权
    {
        string city1, city2;
        int v1, v2, edgeW;
        getchar();
        cin >> city1 >> city2 >> edgeW;
        v1 = string2int[city1];
        v2 = string2int[city2];
        adjM[v1][v2] = adjM[v2][v1] = edgeW;
    }
    Dijkstra(1);
    des = "ROM";
    int desInt = string2int[des];
    cout << pathNum[desInt] << " " << dis[desInt] << " " << hpy[desInt] << " " << int(hpy[desInt]/cityNum[desInt]) << endl;
    PrintPath(desInt);
    return 0;
}
