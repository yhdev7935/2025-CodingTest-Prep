// BOJ - 2302 극장 좌석

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> vip;
    for(int i = 0; i < m; i++) {
        int k; cin >> k; vip.push_back(k);
    } vip.push_back(n + 1);
    int dp[41] = {1, 1, 2};
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];

    int ans = 1, nw = 0;
    for(int k : vip) {
        ans *= dp[k - nw - 1];
        nw = k;
    }

    cout << ans << '\n';
}