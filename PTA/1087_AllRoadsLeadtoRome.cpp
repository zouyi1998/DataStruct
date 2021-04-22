#include <bits/stdc++.h>
using namespace std;
typedef unordered_multimap<string, pair<string, int>> graph;
typedef unordered_map<string, int> mapInt;
typedef unordered_map<string, bool> mapBool;
typedef unordered_multimap<string, string> mapMultiString;
typedef unordered_map<string, string> mapString;
graph g;
mapInt nodeWeight;   //每点的点权
mapInt Cost;         //到每点的最小cost
mapBool Vis;         //是否访问结点
mapInt Weight;       //到每点的等cost路径的最大点权
mapInt cityNum;      //到每城市等cost等weight路径上最小城市数
mapMultiString path; //到每点cost最小的路径的前一个结点
mapString bestPath;  //最佳路径
const int inf = INT_MAX;
int N, K, pathNum;
string src, des;

void Dijkstra(string src)
{
    //初始化起点
    int cnt;
    graph::iterator iter;
    cnt = g.count(src);
    iter = g.find(src);
    for (int i = 0; i < cnt; i++, iter++)
    {
        Cost[iter->second.first] = iter->second.second;
        Weight[iter->second.first] = Weight[src] + nodeWeight[iter->second.first];
        cityNum[iter->second.first] = cityNum[src] + 1;
        path.insert(make_pair(iter->second.first, src));
        bestPath[iter->second.first] = src;
    }
    while (1)
    {
        int minCost = inf;
        string v;
        mapInt::iterator iterCost;
        for (iterCost = Cost.begin(); iterCost != Cost.end(); iterCost++)
            if (!Vis[iterCost->first] && iterCost->second < minCost)
            {
                minCost = iterCost->second;
                v = iterCost->first;
            }
        if (minCost == inf)
            break;
        else
        {
            Vis[v] = true;
            cnt = g.count(v);
            iter = g.find(v);
            for (int i = 0; i < cnt; i++, iter++)
                if (!Vis[iter->second.first])
                {
                    if (Cost[iter->second.first] > Cost[v] + iter->second.second)
                    {
                        Cost[iter->second.first] = Cost[v] + iter->second.second;
                        Weight[iter->second.first] = Weight[v] + nodeWeight[iter->second.first];
                        cityNum[iter->second.first] = cityNum[v] + 1;
                        path.erase(iter->second.first);
                        path.insert(make_pair(iter->second.first, v));
                        bestPath[iter->second.first] = v;
                    }
                    else if (Cost[iter->second.first] == Cost[v] + iter->second.second)
                    {
                        path.insert(make_pair(iter->second.first, v));
                        if (Weight[iter->second.first] < Weight[v] + nodeWeight[iter->second.first])
                        {
                            Weight[iter->second.first] = Weight[v] + nodeWeight[iter->second.first];
                            cityNum[iter->second.first] = cityNum[v] + 1;
                            bestPath[iter->second.first] = v;
                        }
                        else if (Weight[iter->second.first] == Weight[v] + nodeWeight[iter->second.first] && cityNum[iter->second.first] > cityNum[v] + 1)
                        {
                            cityNum[iter->second.first] = cityNum[v] + 1;
                            bestPath[iter->second.first] = v;
                        }
                    }
                }
        }
    }
    return;
}

void countPath(string now)
{
    if (now != src)
    {
        mapString::iterator iter = path.find(now);
        int cnt = path.count(now);
        pathNum += cnt - 1;
        for (int i = 0; i < cnt; i++, iter++)
            countPath(iter->second);
    }
    return;
}

void printPath()
{
    stack<string> s;
    string temp;
    temp = des;
    while (temp != src)
    {
        s.push(temp);
        temp = bestPath[temp];
    }
    cout << src;
    while (!s.empty())
    {
        cout << "->" << s.top();
        s.pop();
    }
    return;
}

int main()
{
    cin >> N >> K;
    getchar();
    cin >> src;
    //读入点权
    nodeWeight.insert(make_pair(src, 0));
    Cost.insert(make_pair(src, 0));
    Weight.insert(make_pair(src, 0));
    Vis.insert(make_pair(src, true));
    cityNum.insert(make_pair(src, 0));
    for (int i = 0; i < N - 1; i++)
    {
        int weight;
        string city;
        getchar();
        cin >> city >> weight;
        nodeWeight.insert(make_pair(city, weight));
        Cost.insert(make_pair(city, inf));
        Weight.insert(make_pair(city, 0));
        Vis.insert(make_pair(city, false));
        cityNum.insert(make_pair(city, 0));
    }
    //读入边
    for (int i = 0; i < K; i++)
    {
        string v1, v2;
        int cost;
        getchar();
        cin >> v1;
        getchar();
        cin >> v2 >> cost;
        g.insert(make_pair(v1, make_pair(v2, cost)));
        g.insert(make_pair(v2, make_pair(v1, cost)));
    }
    //dijkstra
    Dijkstra(src);
    //计算最短路径数
    des = "ROM";
    pathNum = 1;
    countPath(des);
    //输出结果
    cout << pathNum << " " << Cost[des] << " " << Weight[des] << " " << int(Weight[des] / cityNum[des]) << endl;
    printPath();
    return 0;
}

//将字符串映射到1~N即可，不需要使用这么多map