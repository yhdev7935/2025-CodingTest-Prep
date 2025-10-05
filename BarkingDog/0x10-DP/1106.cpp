// BOJ - 1106 호텔

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 21
#define MAXC 10001
#define INF 0x7fffff

using namespace std;

int main() {
    int c, n; cin >> c >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b}); // cost, customer
    }

    // dp[i] = "고객 i명을 늘이기 위해 투자해야 하는 돈의 최솟값"
    // dp[i] = dp[i - customer] + cost
    // dp[0] = 0
    int dp[MAXC] = {0, };
    for(int i = 0; i < MAXC; i++) dp[i] = INF;

    dp[0] = 0;
    for(pair<int, int> p : v) {
        for(int i = p.second; i < MAXC; i++) {
            dp[i] = min(dp[i], dp[i - p.second] + p.first);
        }
    }

    int minv = INF;
    for(int i = c; i < MAXC; i++) minv = min(minv, dp[i]);
    cout << minv << '\n';
}

