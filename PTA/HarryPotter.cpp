#include <bits/stdc++.h>
using namespace std;
#define inf 0xffff

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> D(N + 1, vector<int>(N + 1, inf));
    //初始化距离矩阵
    for (int i = 1; i <= M; i++)
    {
        int v1, v2, dis;
        cin >> v1 >> v2 >> dis;
        D[v1][v2] = D[v2][v1] = dis;
    }
    for (int i = 1; i <= N; i++)
        D[i][i] = 0;
    //floyd
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (D[i][j] > D[i][k] + D[k][j])
                    D[i][j] = D[i][k] + D[k][j];
    //寻找到各点最大距离最小的点
    int globalMin, bestSrc, locMax;
    globalMin = inf;
    locMax = -1;
    for (int i = 1; i <= N; i++)
    {
        locMax = -1;
        for (int j = 1; j <= N; j++)
            if (locMax <= D[i][j])
                locMax = D[i][j];
        if (locMax < globalMin)
        {
            bestSrc = i;
            globalMin = locMax;
        }
    }
    if (globalMin != inf)
        cout << bestSrc << " " << globalMin << endl;
    else
        cout << 0 << endl;
    return 0;
}