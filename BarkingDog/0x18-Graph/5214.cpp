// BOJ - 5214 환승

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long int
#define MAXN 100001
#define MAXL 1001
#define INF 0x7fffffffffff

using namespace std;

ll n, m, k;
vector<ll> adj[MAXN + MAXL];

struct p {
    ll x, d;
};

ll bfs(int x) {

    ll visited[MAXN + MAXL] = {0, };
    queue<p> q; 
    q.push({x, 1}); visited[x] = 1;

    if(x == n) return 1;

    while(!q.empty()) {
        p t = q.front(); q.pop();
        
        for(ll nx : adj[t.x]) {
            if(visited[nx]) continue;

            visited[nx] = 1;
            if (nx <= n) {
                if (nx == n) return t.d + 1;
                q.push({nx, t.d + 1});
            }
            else q.push({nx, t.d});
        }
    }

    return -1;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++) {
        ll hln = n + i;
        for(int j = 1; j <= k; j++) {
            ll stn; cin >> stn;
            adj[stn].push_back(hln);
            adj[hln].push_back(stn);
        }
    }

    cout << bfs(1) << '\n';
}