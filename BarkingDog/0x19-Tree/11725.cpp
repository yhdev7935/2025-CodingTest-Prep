// BOJ - 11725 트리의 부모 찾기

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100001

using namespace std;

int n, par[MAXN];
vector<int> gph[MAXN];
void dfs(int x) {
    for(int nx : gph[x]) {
        if(par[x] == nx) continue;
        par[nx] = x;
        dfs(nx);
    }
}
int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        gph[u].push_back(v);
        gph[v].push_back(u);
    }
    for(int i = 0; i < MAXN; i++) par[i] = i;
    dfs(1);
    for(int i = 2; i <= n; i++) cout << par[i] << '\n';
}