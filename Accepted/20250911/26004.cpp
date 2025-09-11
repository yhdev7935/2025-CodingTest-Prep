// BOJ - 26004 HI-ARC

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    string ss; cin >> ss;

    map<char, int> m;
    for(char ch: ss) m[ch]++;

    cout << min(m['H'], min(m['I'], min(m['A'], min(m['R'], m['C'])))) << '\n';
}