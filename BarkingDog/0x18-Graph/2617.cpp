// BOJ - 2617 구슬 찾기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 101

using namespace std;

vector<int> gph1[MAXN];
vector<int> gph2[MAXN];
int n, m;

struct p {
    int x;
};
int bfs1(int x) {
    int vis[MAXN] = {0, }, ret = 0;
    queue<p> q; q.push({x}); vis[x] = 1;
    while(!q.empty()) {
        p t = q.front(); q.pop();
        for(int k : gph1[t.x]) {
            if(vis[k]) continue;
            q.push({k}); vis[k] = 1;
            ret++;
        }
    }

    if(ret >= (n + 1) / 2) return 1;
    return 0;
}
int bfs2(int x) {
    int vis[MAXN] = {0, }, ret = 0;
    queue<p> q; q.push({x}); vis[x] = 1;
    while(!q.empty()) {
        p t = q.front(); q.pop();
        for(int k : gph2[t.x]) {
            if(vis[k]) continue;
            q.push({k}); vis[k] = 1;
            ret++;
        }
    }

    if(ret >= (n + 1) / 2) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int s, e; cin >> s >> e; // s > e
        gph1[e].push_back(s);
        gph2[s].push_back(e);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += (bfs1(i) | bfs2(i));
    }

    cout << ans << '\n';
}