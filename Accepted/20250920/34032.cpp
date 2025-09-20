// BOJ - 34032 /gg

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, cnt = 0; cin >> n;
    string s; cin >> s;
    for(char ch : s) {
        if(ch == 'O') cnt++;
    }

    if(cnt >= (n + 1) / 2) cout << "Yes\n";
    else cout << "No\n";
}