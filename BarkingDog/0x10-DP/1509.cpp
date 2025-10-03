// BOJ - 1509 팰린드롬 분할

// QWERTYTREWQWERT
// QWERTYTREWQ, W, E, R, T
// 맨 앞의 Q가 사라지면?
// (Q), WERTYTREW, Q, W, E, R, T -> Overlapping Problems!

// palin[i][j] = "[i, j] 까지 팰린드롬일까?"
// dp[i] = "S[0, i]까지 최소 팰린드롬 분할 개수"
// dp[i] = min(dp[j - 1] + 1) // palin[j][i] 가 참일 때를 가정해야 함.

#include <iostream>
#include <vector>
#include <string>
#define INF 0x7fffff
#define MAXN 2501

using namespace std;

int palin[MAXN][MAXN], dp[MAXN];
int main() {
    string ss; cin >> ss;
    int n = ss.size();

    for(int i = n - 1; i >= 0; i--)
        for(int j = i; j < n; j++) {
            if(i == j) palin[i][j] = 1;
            else if(j - i == 1 && ss[i] == ss[j]) palin[i][j] = 1;
            else if(palin[i + 1][j - 1] && ss[i] == ss[j]) palin[i][j] = 1;
        }

        // palin[i][j] = "[i, j] 까지 팰린드롬일까?"
        // dp[i] = "S[0, i]까지 최소 팰린드롬 분할 개수"
        // dp[i] = min(dp[j - 1] + 1) // palin[j][i] 가 참일 때를 가정해야 함.

    for(int i = 0; i < n; i++) dp[i] = INF;


    for(int i = 0; i < n; i++) {
        if(palin[0][i]) dp[i] = 1;
        for(int j = 1; j <= i; j++)
            if(palin[j][i])
                dp[i] = min(dp[i], dp[j - 1] + 1);
    }

    cout << dp[n - 1] << '\n';
}


