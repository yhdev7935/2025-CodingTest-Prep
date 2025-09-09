// BOJ - 11908 카드

#include <iostream>

using namespace std;

int main() {
    int n, s = 0, maxv = 0; cin >> n;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        s += k;
        maxv = max(maxv, k);
    }
    cout << (s - maxv) << '\n';
}