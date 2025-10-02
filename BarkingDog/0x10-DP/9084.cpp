// BOJ - 9084 동전

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 10001
#define ll long long int

using namespace std;

void tc() {
    ll n; cin >> n;
    vector<ll> v;
    for(int i = 0 ; i < n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }
    ll m; cin >> m;
    ll dp[MAXN] = {0, };
    // dp[i] = "i 원을 만드는 동전 조합수"
    // 1, 5, 100 -> 100
    // dp[100] = (100, 95 + 5, 90 + 10, ...)
    // dp[1] = 1
    // dp[5] = 2 (1x5, 5x1)
    // dp[10] = 3 (5x2, 5x1+1x5, 1x10)

    dp[0] = 1; // 0원은 1가지로 집계
    for(int k : v) // 동전 하나 고정
        for(int i = k; i <= m; i++) // 쓸 수 있는 금액부터 시작
            dp[i] += dp[i - k];

    cout << dp[m] << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) tc();
}