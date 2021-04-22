#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    q.push(3);
    q.push(5);
    q.push(1);
    q.push(10);
    while (!q.empty())
    {
        printf("%d ", q.top());
        q.pop();
    }
    return 0;
}