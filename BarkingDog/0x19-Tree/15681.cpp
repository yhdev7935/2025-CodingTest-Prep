// BOJ - 15681 트리와 쿼리

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100001

using namespace std;

int n, r, q, visited[MAXN]; 
vector<int> gph[MAXN];
int cnt[MAXN] = {0, };
void dfs(int x) {
    cnt[x] = 1; visited[x] = 1;
    for(int nv : gph[x]) {
        if(visited[nv]) continue;
        dfs(nv);
        cnt[x] += cnt[nv];
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n >> r >> q;

    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        gph[u].push_back(v);
        gph[v].push_back(u);
    }

    dfs(r);
    while(q--) {
        int node; cin >> node;
        cout << cnt[node] << '\n';
    }
}