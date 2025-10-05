// BOJ - 4811 알약

// 알약 = 4, WHWWWHHH

#include <iostream>
#include <vector>
#define ll unsigned long long int

using namespace std;

int tc() {
    ll n; cin >> n;
    if(n == 0) return 0;
    ll dp[61][31] = {0, };
    // dp[i][j] = "i번째까지 등장한 j = (W의 개수 - H의 개수) 인 경우의 수"
    // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]
    dp[1][1] = 1;
    for(int i = 2; i <= 2 * n; i++)
        for(int j = 0; j <= n; j++) {
            if(j > 0) dp[i][j] += dp[i - 1][j - 1];
            if(j < n) dp[i][j] += dp[i - 1][j + 1];
        }

    cout << dp[2 * n][0] << '\n';
    return 1;
}
int main() {
    while(1) if(!tc()) break;
    return 0;
}