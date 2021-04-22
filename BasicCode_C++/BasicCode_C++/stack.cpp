#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> s;

int main()
{
    int val;
    bool empty;
    s.push(4);
    s.push(5);
    s.push(6);
    val = s.top();
    s.pop();
    while (!s.empty())
    {
        val = s.top();
        s.pop();
    }
    return 0;
}