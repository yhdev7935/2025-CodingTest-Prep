// BOJ - 2240 자두나무

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr[1001] = {0, };
    int dp[1001][2][31] = {0, };

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) { cin >> arr[i]; arr[i]--; } // 나무 번호를 0, 1 으로 포맷팅

    dp[1][0][0] = (arr[1] == 0 ? 1 : 0);
    if(m >= 1) dp[1][1][1] = (arr[1] == 1 ? 1 : 0);
    
    for(int t = 2; t <= n; t++) {
        for(int mv = 0; mv <= min(m, t - 1); mv++) {
            int loc = arr[t];
            if(mv == 0) dp[t][0][0] = dp[t - 1][0][0] + (loc == 0 ? 1 : 0);
            else {
                dp[t][loc][mv] = max(dp[t - 1][!loc][mv - 1] + 1, dp[t - 1][loc][mv] + 1);
                dp[t][!loc][mv] = max(dp[t - 1][!loc][mv], dp[t - 1][loc][mv - 1]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; i++) {
        ans = max(ans, dp[n][0][i]);
        ans = max(ans, dp[n][1][i]);
    }

    cout << ans << '\n';
}