// BOJ - 1647 도시 분할 계획

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define ll long long
#define MAXN 100001

using namespace std;

struct p {
    int s, e, d;
};

int cmp(const p& a, const p& b) {
    return a.d < b.d;
}

ll parent[MAXN] = {0, };
int par(int k) {
    if(parent[k] == k) return parent[k];
    return parent[k] = par(parent[k]);
}
void uf(int a, int b) {
    a = par(a); b = par(b);
    if(a < b) parent[a] = b;
    else parent[b] = a;
}
int main() {
    for(int i = 1; i < MAXN; i++) parent[i] = i;

    int n, m; cin >> n >> m;
    vector<p> edges;
    for(int i = 1; i <= m; i++) {
        int s, e, d; cin >> s >> e >> d;
        edges.push_back({s, e, d});
    }

    sort(edges.begin(), edges.end(), cmp);
    int cnt = 0; vector<int> rv;
    for(p e : edges) {
        ll x = par(e.s), y = par(e.e);
        if(x == y) continue;

        cnt += e.d;
        rv.push_back(e.d);
        uf(x, y);
    }

    cout << (cnt - rv[rv.size() - 1]) << '\n';
}