#include<iostream>
#include<algorithm>
#include<utility>
#include<tuple>
#include<vector>
using namespace std;
pair<int, int> t1(1, 2), temp, t2(1, 2), t3(1, 3), t4(2, 2);
vector<pair<int, int>> v;

int main()
{
    int fisrt,second;
    bool mark;
    v.push_back(make_pair(2, 3));
    temp = v.at(0);
    tie(fisrt, second) = temp;
    mark = t1==t2;
    mark = t1 > t2;
    mark = t3 > t1;
    return 0;
}