#include <iostream>
#include <algorithm>
#define ll long long
#define MAXN 200001 + 1

using namespace std;

int main() {
    ll n, k; cin >> n >> k;
    ll arr[MAXN][2] = {0, };
    for(int i = 1; i <= n; i++) {
        ll a; cin >> a;
        arr[i][0] = a;
    }
    for(int i = 1; i <= n; i++) {
        ll a; cin >> a;
        arr[i][1] = a;
    }

    ll dp[MAXN][3] = {0, };
    dp[1][0] = arr[1][0], dp[1][1] = arr[1][1];
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 1; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][!j] + k) + arr[i][j];
        }
    }

    cout << min(dp[n][0], dp[n][1]) << '\n';
}