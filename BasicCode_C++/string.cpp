#include <iostream>
#include <string>
using namespace std;

int main()
{
    string::iterator it;
    string s1, s2;
    s2 = "de";
    getline(cin, s1);
    cout << s1.length() << endl;
    cout << s1 << endl;
    cout << s1 + s2 << endl;
    cout << s1.find("bce") << endl;
    cout << s1.npos << endl;
    cout << s1.at(1) << endl;
    s1.insert(2,"Hello");
    cout << s1 << endl;
    return 0;
}