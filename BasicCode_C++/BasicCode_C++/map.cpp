#include<iostream>
#include<string>
#include<utility>
#include<map>

using namespace std;

map<string, int> M;
map<string, int>::iterator iter;

int main()
{
    M.insert(pair<string, int>("A", 1));
    M.insert(map<string,int>::value_type("B", 2));
    M.insert(make_pair("C", 3));
    iter = M.find("A");
    cout << (*iter).first << endl;
    M.erase("B");
    if(M.find("B") == M.end())
        cout <<"Not Found" << endl;
    cout << M["A"] << endl;
    return 0;
}