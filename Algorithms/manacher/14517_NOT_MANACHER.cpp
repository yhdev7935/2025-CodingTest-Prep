// BOJ - 14517 팰린드롬 개수 구하기 (Large)

// 조심해야 할 것! 이 문제는 "부분 문자열"이 아니라 "부분 수열"의 문제 이므로 Manacher's 가 통하지 않습니다.
// 그렇기에 DP 로 해결해야 합니다.

// 문자열의 최대 길이 <= 1000 (2차원 배열 ㄱㄴ.)
// dp[i][j] = "S[i..j]까지의 부분 문자열에서 만들 수 있는 '팰린드롬 부분 수열'의 최대 개수"
// dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]
// dp[i][j] += (dp[i + 1][j - 1] + 1) if s[i] == s[j]

#include <iostream>
#include <vector>
#define ll long long int
#define MAXN 1001

using namespace std;

ll dp[MAXN][MAXN];
int main() {
    string ss; cin >> ss;
    int n = ss.size();
    
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 1; len < n; len++)
        for(int i = 0; i < n; i++) {
            int j = i + len;
            if(j >= n) continue;
            dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + 10007) % 10007;
            if(ss[i] == ss[j]) dp[i][j] += (dp[i + 1][j - 1] + 1);
            dp[i][j] %= 10007;
        }

    cout << (dp[0][n - 1] % 10007) << '\n';
}