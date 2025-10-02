// BOJ - 2618 경찰차

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
#define MAXN 1001
#define INF 0x7fffffffffff

using namespace std;

ll n, w;
ll dp[MAXN][MAXN] = {0, }, choice[MAXN][MAXN] = {0, };
pair<ll, ll> parent[MAXN][MAXN];
vector<pair<ll, ll> > incidents;

int dist(int from, int to, int who) {
    pair<ll, ll> inci_a = incidents[from], inci_b = incidents[to];
    if(from == 0 && who == 0) inci_a = {1, 1};
    else if(from == 0 && who == 1) inci_a = {n, n};
    return abs(inci_a.first - inci_b.first) + abs(inci_a.second - inci_b.second);
}
int main() {

    // dp[i][j] = "경찰차1가 i번째 사건까지 처리했고, 경찰차가 j번 사건까지 처리했을 때 최소 이동 거리"
    // + 백트래킹을 위해 dp 갱신했을 때 별도의 배열에 (i, j) 이 상태에서 어떤 경찰차가 선택되었는지 배열 처리가 필요함.

    cin >> n >> w;
    incidents.push_back({0, 0});
    for(int i = 1; i <= w; i++) {
        ll x, y; cin >> x >> y;
        incidents.push_back({x, y});
    }

    for(int i = 0; i <= w; i++) for(int j = 0; j <= w; j++) dp[i][j] = INF;

    // dp[i][j] -> dp[next][j], dp[i][next] 어디로?

    dp[0][0] = 0;
    for(int i = 0; i <= w; i++)
        for(int j = 0; j <= w; j++) {
            if(dp[i][j] == INF) continue;

            ll next = max(i, j) + 1;
            if(next > w) continue;

            ll p0 = dp[i][j] + dist(i, next, 0);
            if(p0 < dp[next][j]) {
                dp[next][j] = p0;
                parent[next][j] = {i, j}; 
                choice[next][j] = 1;
            }

            ll p1 = dp[i][j] + dist(j, next, 1);
            if(p1 < dp[i][next]) {
                dp[i][next] = p1;
                parent[i][next] = {i, j};
                choice[i][next] = 2;
            }
        }

    // minimum distance
    ll ans = INF;
    pair<ll, ll> end = {-1, -1};
    for(int i = 0; i <= w; i++) {
        if(dp[w][i] < ans) { ans = dp[w][i]; end = {w, i}; }
        if(dp[i][w] < ans) { ans = dp[i][w]; end = {i, w}; }
    }

    cout << ans << '\n';

    // backtracking
    vector<int> order;
    pair<ll, ll> cur = end;
    while(!(cur.first == 0 && cur.second == 0)) {
        order.push_back(choice[cur.first][cur.second]); 
        cur = parent[cur.first][cur.second];
    }
    reverse(order.begin(), order.end());
    for(int k : order) cout << k << '\n';
    
    return 0;
}