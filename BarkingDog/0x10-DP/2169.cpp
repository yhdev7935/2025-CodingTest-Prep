// BOJ - 2169 로봇 조종하기

// BFS는 TLE
// 왼쪽으로도 갈 수 있기 때문에 dp 배열 하나 가지고 풀 수 없음.
// dp 배열 하나만 있으면 왼쪽 오른쪽을 같은 줄에서 중복 방문이 있는 채로 할 수도 있기 때문임.

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1001
#define NINF -0x7ffffff

using namespace std;

int arr[MAXN][MAXN], dp[MAXN][MAXN], dp2[MAXN][MAXN];
int n, m; 

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) dp[i][j] = NINF, dp2[i][j] = NINF;
    dp[1][0] = dp[0][1] = 0;
    dp[1][1] = arr[1][1], dp2[1][1] = arr[1][1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) dp[i][j] = max({dp[i - 1][j], dp2[i - 1][j], dp[i][j - 1]}) + arr[i][j];
        if(i != 1) for(int j = m; j >= 1; j--) dp2[i][j] = max({dp[i - 1][j], dp2[i - 1][j], dp2[i][j + 1]}) + arr[i][j];
    }

    cout << max(dp[n][m], dp2[n][m]) << '\n';
}