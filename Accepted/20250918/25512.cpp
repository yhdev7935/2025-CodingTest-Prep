// BOJ - 25512 트리를 간단하게 색칠하는 최소 비용

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define MAXN 100001
#define ll long long

using namespace std;

struct p {
    ll node, clr;
};
vector<int> arr[MAXN];
ll visited[MAXN], value[MAXN][2], n;
ll bfs(ll x, ll y) {
    ll ret = 0;
    memset(visited, 0, sizeof(visited));
    queue<p> q; q.push({x, y});
    visited[x] = 1;
    while(!q.empty()) {
        p t = q.front(); ret += value[t.node][t.clr];
        q.pop();
        for(int nx : arr[t.node]) {
            if(visited[nx]) continue;
            q.push({nx, !t.clr}); visited[nx] = 1;
        }
    }

    return ret;
}
int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        ll f, t; cin >> f >> t;
        arr[f].push_back(t);
    }

    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        value[i][0] = a;
        value[i][1] = b;
    }
    
    cout << min(bfs(0, 0), bfs(0, 1)) << '\n';
}