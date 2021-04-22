#include <bits/stdc++.h>
using namespace std;
// using unordered_map<int,unordered_map<int,int>> = table;
unordered_multimap<int, int> g;       //图
unordered_map<int, set<int>> lineNum; //记录每个站点属路线
unordered_map<int, int> path;
unordered_map<int, int> curLine;
unordered_map<int, int> dis;
unordered_map<int, bool> vis;
unordered_map<int, int> tranferNum;
const int inf = INT_MAX;
int N;

int intersection(int v1, int v2)
{
    set<int> set3; 
    set_intersection(lineNum[v1].begin(),lineNum[v1].end(), lineNum[v2].begin(), lineNum[v2].end(), inserter(set3, set3.begin()));
    return *set3.begin();
}

void Dijkstra(int src)
{
    //初始化
    path.clear();
    for (auto iter : g)
    {
        dis[iter.first] = inf;
        vis[iter.first] = false;
        tranferNum[iter.first] = 0;
    }
    //初始化源点
    vis[src] = true;
    dis[src] = 0;
    tranferNum[src] = 0;
    curLine[src] = 0;
    unordered_multimap<int, int>::iterator iter = g.find(src);
    int cnt = g.count(src);
    for (int i = 0; i < cnt; i++, iter++)
    {
        dis[iter->second] = dis[src] + 1;
        path[iter->second] = src;
        curLine[iter->second] = intersection(src, iter->second);
    }
    //最短路
    while (1)
    {
        int minDis, v;
        minDis = inf;
        for (auto iter : dis)
            if (!vis[iter.first] && iter.second < minDis)
            {
                minDis = iter.second;
                v = iter.first;
            }
        if (minDis == inf)
            break;
        else
        {
            int nextLine;
            vis[v] = true;
            iter = g.find(v);
            cnt = g.count(v);
            for (int i = 0; i < cnt; i++, iter++)
                if (!vis[iter->second])
                {
                    if (dis[iter->second] > dis[v] + 1)
                    {
                        path[iter->second] = v;
                        dis[iter->second] = dis[v] + 1;
                        nextLine = intersection(iter->second, v);
                        curLine[iter->second] = nextLine;
                        if (nextLine != curLine[v])
                            tranferNum[iter->second] = tranferNum[v] + 1;
                        else
                            tranferNum[iter->second] = tranferNum[v];
                    }
                    else if (dis[iter->second] == dis[v] + 1)
                    {
                        nextLine = intersection(iter->second, v);
                        if (nextLine != curLine[v])
                        {
                            if (tranferNum[iter->second] > tranferNum[v] + 1)
                            {
                                path[iter->second] = v;
                                tranferNum[iter->second] = tranferNum[v] + 1;
                                curLine[iter->second] = nextLine;
                            }
                        }
                        else
                        {
                            if (tranferNum[iter->second] > tranferNum[v])
                            {
                                path[iter->second] = v;
                                tranferNum[iter->second] = tranferNum[v];
                                curLine[iter->second] = nextLine;
                            }
                        }
                    }
                }
        }
    }
    return;
}

void PrintPath(int src, int des)
{
    int temp = des;
    vector<int> bestPath;
    while (temp != src)
    {
        bestPath.push_back(temp);
        temp = path[temp];
    }
    bestPath.push_back(src);
    int ind = bestPath.size() - 1;
    int start, end, startLine, endLine;
    start = bestPath[ind];
    while (start != des)
    {
        startLine = curLine[bestPath[ind - 1]];
        cout << "Take Line#" << startLine << " from " << start << " to ";
        ind--;
        while (bestPath[ind] != des && curLine[bestPath[ind]] == curLine[bestPath[ind-1]])
            ind--;
        end = bestPath[ind];
        cout << end << "." << endl;
        start = end;
    }
    return;
}

int main()
{
    cin >> N;
    //建图
    for (int i = 1; i <= N; i++) //地铁路线从1编号到N
    {
        int M;
        cin >> M;
        int lastStation;
        cin >> lastStation;
        lineNum[lastStation].insert(i);
        for (int j = 2; j <= M; j++)
        {
            int curStation;
            cin >> curStation;
            g.insert(make_pair(lastStation, curStation));
            g.insert(make_pair(curStation, lastStation));
            lineNum[curStation].insert(i);
            lastStation = curStation;
        }
    }
    //Dijkstra
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int src, des;
        cin >> src >> des;
        Dijkstra(src);
        cout << dis[des] << endl;
        PrintPath(src, des);
    }
    return 0;
}
