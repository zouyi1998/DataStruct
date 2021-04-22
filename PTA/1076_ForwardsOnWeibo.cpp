#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<vector<int>> g(1, vector<int>(1, 0)); //编号对齐
vector<bool> vis;                          //编号对齐

void BFS(int s)
{
    int last, tail, dis, cnt;
    vis.insert(vis.begin(), N + 1, false); //vis数组初始化
    queue<int> q;
    q.push(s);
    vis[s] = true;
    last = tail = s;
    dis = cnt = 0;
    while (!q.empty())
    {
        int v;
        v = q.front();
        q.pop();
        for (int i = 1; i <= g[v].size() - 1; i++)
            if (!vis[g[v][i]])
            {
                q.push(g[v][i]);
                vis[g[v][i]] = true;
                tail = g[v][i];
            }
        if (dis >= 1 && dis <= L)
            cnt++;
        else if (dis > L)
            break;
        if (v == last)
        {
            dis++;
            last = tail;
        }
    }
    cout << cnt << endl;
    return;
}

int main()
{
    cin >> N >> L;
    g.insert(g.begin(), N + 1, vector<int>(1, 0));
    for (int i = 1; i <= N; i++)
    {
        int K;
        cin >> K;
        for (int j = 1; j <= K; j++)
        {
            int v;
            cin >> v;
            g[v].push_back(i);
        }
    }
    int queryNum;
    cin >> queryNum;
    for (int i = 0; i < queryNum; i++)
    {
        int src;
        cin >> src;
        BFS(src);
    }
    return 0;
}