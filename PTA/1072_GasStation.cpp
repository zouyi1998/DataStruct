#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> Visit;
vector<int> dis;
vector<tuple<double, double, int>> minAndAverage; //记录最小距离（相反数），平均距离，点序号
int N, M, K, Ds;
const int inf = 0x7fffffff;

int transfer(string s)
{
    if (s.size() == 1)
        return stoi(s);
    else
    {
        string s1(s.begin() + 1, s.end());
        return stoi(s1) + N;
    }
}

void Dijkstra(int src)
{
    //初始化Visit,dis
    Visit.insert(Visit.begin(), N+M+10, false);
    dis.insert(dis.begin(), N+M+10, inf);
    //初始化起点
    Visit[src] = true;
    dis[src] = 0;
    for (int i = 1; i <= N + M; i++)
        if (g[src][i])
            dis[i] = g[src][i];
    //最短路
    int minDis, v;
    while (1)
    {
        minDis = inf;
        for (int i = 1; i <= N + M; i++)
            if (!Visit[i] && dis[i] < minDis)
            {
                minDis = dis[i];
                v = i;
            }
        if (minDis == inf)
            break;
        else
        {
            Visit[v] = true;
            for (int i = 1; i <= N + M; i++)
                if (!Visit[i] && g[v][i] &&
                    dis[i] > g[v][i] + dis[v])
                    dis[i] = g[v][i] + dis[v];
        }
    }
    return;
}

void Judge(int src)
{
    double minDis, averDis;
    minDis = inf;
    averDis = 0;
    for (int i = 1; i <= N; i++)
    {
        averDis += dis[i];
        if (dis[i] < minDis)
            minDis = dis[i];
        if (dis[i] > Ds)
            return;
    }
    averDis /= N;
    minAndAverage.push_back(make_tuple(-minDis, averDis, src - N));
    return;
}

int main()
{
    cin >> N >> M >> K >> Ds;
    //初始化化图
    g.insert(g.begin(), N+M+10, vector<int>(N+M+10, 0)); //从1开始编号
    //输入图
    for (int i = 0; i < K; i++)
    {
        string s1, s2;
        int v1, v2, weight;
        getchar(); //读入回车
        cin >> s1 >> s2 >> weight;
        v1 = transfer(s1);
        v2 = transfer(s2);
        g[v1][v2] = g[v2][v1] = weight;
    }
    //dijkstra
    for (int i = 1; i <= M; i++)
    {
        Dijkstra(N + i);
        Judge(N + i);
    }
    //排序输出最小
    if (minAndAverage.size() == 0)
        printf("No Solution\n");
    else
    {
        sort(minAndAverage.begin(), minAndAverage.end());
        double first, second;
        int third;
        tie(first, second, third) = minAndAverage[0];
        printf("G%d\n%0.1f %0.1f\n", third, -first, second);
    }
    return 0;
}