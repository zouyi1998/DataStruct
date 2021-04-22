#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<int> set1, set2, set3;
unordered_set<int>::iterator iter;

int main()
{
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set2.insert(3);
    set2.insert(5);
    set2.insert(6);
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
    for (auto x : set3)
        cout << x << " ";
    cout << endl;
    set3.clear();
    cout <<  set3.size() << endl;
    return 0;
}