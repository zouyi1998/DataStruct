#include<iostream>
#include<tuple>
#include<string>
using namespace std;

tuple<int, int, string> t(1 , 1, "A");


int main()
{
    cout << tuple_size<decltype(t)>::value << endl;
    cout << get<2>(t) << endl;
    return 0;
}