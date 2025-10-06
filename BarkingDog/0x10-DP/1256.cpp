// BOJ - 1256 사전

// K가 너무 커서 DFS 불가
// n = 2, m = 2
// aazz, k = 1, 01 // azaz, k = 2, 02 // azza, k = 3, 03 // zaaz, k = 4, 12 // zaza, k = 5, 13 // zzaa, k = 6, 23
// a의 위치를 한번 보자. 맨 앞의 a가 끝까지 이동하면 그 뒤의 a가 한칸 앞으로 이동한다.
// n = 3, m = 3
// aaazzz, 012 // aazazz, 013 // aazzaz, 014 // aazzza, 015 // azaazz, 023 // azazaz, 024 // azazza, 025 // azzaaz, 034 // azzaza, 035 // azzzaa, 045 // zaaazz, 123

// dp[i][j] = "'a'를 i개, 'z'를 j개 사용하여 만들 수 있는 모든 문자열의 총개수"
// dp[i][j] = dp[i - 1][j] (마지막이 'z') + dp[i][j - 1] (마지막이 'a')
// dp[1][0] = dp[1][1] = 1

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 101
#define INF 0x7ffffff
#define MOD 1000000001
#define ll long long int

using namespace std;

ll dp[MAXN][MAXN];
int main() {
    ll n, m, k; cin >> n >> m >> k;
    dp[0][0] = 1; 

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++) {
            ll v = 0;
            if(i > 0) v += dp[i - 1][j];
            if(j > 0) v += dp[i][j - 1];
            if(v > 0) dp[i][j] = min((ll)MOD, v);
        }
    
    ll cn = n, cm = m;
    if(k > dp[cn][cm]) {
        cout << "-1\n";
        return 0;
    }
    while(cn > 0 && cm > 0) { // temp
        ll s1 = cn > 0 ? dp[cn - 1][cm] : INF;
        ll s2 = cm > 0 ? dp[cn][cm - 1] : INF;
        if(k > s1) {
            cm--, k -= s1; // zxxxx..
            cout << "z";
        }
        else {
            cn--; // axx...
            cout << "a";
        }
    }
    while(cn > 0) cout << "a", cn--;
    while(cm > 0) cout << "z", cm--;
    cout << '\n';

    return 0;
}