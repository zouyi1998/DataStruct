#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;

int main()
{
    int val, size;
    v.push_back(1);
    v.push_back(6);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    val = v[1];
    v.pop_back();
    size = v.size();
    return 0;
}