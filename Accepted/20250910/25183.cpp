// BOJ - 25183 인생은 한 방

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string ss; cin >> ss;
    int cnt = 1, maxv = 1; char cmp = '0';
    for(char ch : ss) {
        if(abs(ch - cmp) == 1) { cnt++; maxv = max(maxv, cnt); }
        else cnt = 1;
        cmp = ch;
    }

    cout << (maxv >= 5 ? "YES" : "NO") << '\n';
}