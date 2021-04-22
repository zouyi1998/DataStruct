#include<iostream>
#include<deque>
using namespace std;

deque<int> deq;

int main()
{
    deq.push_front(0);
    deq.push_front(1);
    deq.push_back(2);
    cout << deq.at(0) << endl;
    cout << deq.at(1) << endl;
    return 0;
}