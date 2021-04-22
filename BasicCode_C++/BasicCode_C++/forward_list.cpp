#include <forward_list>
#include <algorithm>
#include <cstdio>
using namespace std;

forward_list<int> L1;
forward_list<int>::iterator it;

int main()
{
    L1.push_front(1);
    L1.push_front(10);
    L1.push_front(3);
    L1.push_front(0);
    L1.push_front(-4);
    L1.push_front(20);
    L1.pop_front();
    L1.sort();
    for (it = L1.begin(); it != L1.end(); it++)
        printf("%d ", *it);
    return 0;
}
