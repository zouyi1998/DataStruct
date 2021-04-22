#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
    int val;
    bool empty;
    q.push(3);
    q.push(4);
    q.push(5);
    val = q.front();
    q.pop();
    val = q.front();
    q.pop();
    empty = q.empty();
    q.push(5);
    while (!q.empty())
        q.pop();
    empty = q.empty();
    return 0;
}