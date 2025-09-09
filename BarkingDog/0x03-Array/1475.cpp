// BOJ - 1475 방 번호

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string s = to_string(n);
    int ch[10] = {0, };
    for(int i = 0; i < s.size(); i++) ch[s[i] - '0']++;
    int maxv = 0;
    for(int i = 0; i <= 8; i++) {
        int k = ch[i];
        if(i == 6) k = (ch[6] + ch[9] + 1) / 2;
        maxv = max(maxv, k);
    }
    cout << maxv << '\n';
}