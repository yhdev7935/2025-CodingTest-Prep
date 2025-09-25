// BOJ - 4883 삼각 그래프

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100001
#define INF 0x7FFFFFFF
#define ll long long int

using namespace std;

int main() {
    ll cnt = 1;
    while(1) {
        ll n, arr[MAXN][4] = {0, }; cin >> n;
        if(n == 0) break;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) cin >> arr[i][j];
        // dp[i][j] = "(i, j) 까지 도달하기 위한 최소 비용"
        ll dp[MAXN][5] = {0, }; 
        for(int i = 0; i < MAXN; i++) for(int j = 0; j < 5; j++) dp[i][j] = INF;
        dp[1][2] = arr[1][2];
        dp[1][3] = arr[1][2] + arr[1][3];
        for(int i = 2; i <= n; i++) {
            dp[i][1] = arr[i][1] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = arr[i][2] + min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3], dp[i][1]});
            dp[i][3] = arr[i][3] + min({dp[i - 1][2], dp[i - 1][3], dp[i][2]});
        }

        cout << cnt << ". " << dp[n][2] << '\n';
        cnt++;
    }
}