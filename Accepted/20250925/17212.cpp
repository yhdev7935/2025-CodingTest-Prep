// BOJ - 17212 달나라 토끼를 위한 구매대금 지불 도우미
// 코인의 종류끼리 전부 약수/배수 관계가 아니므로 Greedy Algorithm으로 해결하지 못합니다.

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int cnt = 0;
    int dp[100001] = {0, };
    dp[1] = dp[2] = dp[5] = dp[7] = 1;
    dp[3] = 2; dp[4] = 2; dp[6] = 2;
    for(int i = 8; i <= n; i++) {
        dp[i] = min(dp[i - 1], min(dp[i - 2], min(dp[i - 5], dp[i - 7]))) + 1;
    }

    cout << dp[n] << '\n';
}