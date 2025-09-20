// BOJ - 13234 George Boole

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> m;
    m["true"] = 1;
    m["false"] = 0;

    string ss, op;
    cin >> ss; int a = m[ss];
    cin >> op;
    cin >> ss; int b = m[ss];
    if(op == "AND")
        cout << (a & b ? "true" : "false") << '\n';
    else
        cout << (a | b ? "true" : "false") << '\n';

}