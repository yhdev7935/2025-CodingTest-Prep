// BOJ - 13300 방 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, ans = 0; cin >> n >> k;
    int s[2][6] = {0, };
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        s[a][b - 1]++;
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 6; j++)
            ans += (s[i][j] + k - 1) / k;
    cout << ans << '\n';
}