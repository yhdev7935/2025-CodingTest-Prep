// BOJ - 2660 회장뽑기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 51

using namespace std;

vector<int> gph[MAXN]; int n;

int bfs(int x) {
    queue<pair<int, int> > q;
    int visited[MAXN] = {0, }, maxv = 0;
    visited[x] = 1; q.push({x, 0});
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for(int nx : gph[p.first]) {
            if(visited[nx]) continue;
            visited[nx] = 1;
            q.push({nx, p.second + 1}); maxv = max(maxv, p.second + 1);
        }
    }
    return maxv;
}
int main() {
    cin >> n;
    while(1) {
        int s, e; cin >> s >> e;
        if(s == -1 && e == -1) break;
        gph[s].push_back(e);
        gph[e].push_back(s);
    }


    vector<int> ans; int ansv = 0x7fffffff;
    for(int i = 1; i <= n; i++) {
        int cnt = bfs(i);
        if(cnt < ansv) {
            ansv = cnt; ans = vector<int>(); ans.push_back(i);
        }
        else if(cnt == ansv) ans.push_back(i);
    }

    cout << ansv << ' ' << ans.size() << '\n';
    for(int k : ans) cout << k << ' '; cout << '\n';
}