// BOJ - 1958 LCS 3

// LCS with 3 sequences
// prev: dp[i][j] = "A[0..i), B[0..j)에서 LCS의 최대 길이"
// prev: dp[i][j][k] = "A[0..i), B[0..j), C[0..k) 인 LCS의 최대 길이"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAXN 101

using namespace std;

int dp[MAXN][MAXN][MAXN] = {0, };
int main() {
    string A, B, C; cin >> A >> B >> C;
    int an = A.size(), bn = B.size(), cn = C.size();
    A = '0' + A;
    B = '0' + B;
    C = '0' + C;

    for(int i = 1; i <= an; i++)
        for(int j = 1; j <= bn; j++)
            for(int k = 1; k <= cn; k++) {
                int maxv = 0;
                if(!(A[i] == B[j] && B[j] == C[k]))
                    maxv = max({maxv, dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                else
                    maxv = max({maxv, dp[i - 1][j - 1][k - 1] + 1});
                dp[i][j][k] = maxv;
            }

    cout << dp[an][bn][cn] << '\n';
}