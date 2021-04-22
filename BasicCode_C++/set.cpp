#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> set1, set2, set3;
set<int>::iterator iter;

int main()
{
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set2.insert(3);
    set2.insert(5);
    set2.insert(6);
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
    for (iter = set3.begin(); iter != set3.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    set3.clear();
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
    for (iter = set3.begin(); iter != set3.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    return 0;
}