// BOJ - 4803 트리

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 501

using namespace std;

int cs = 0;
int tc() {
    cs++;
    int n, m; cin >> n >> m;
    if(!n && !m) return 0;

    vector<int> gph[MAXN];
    for(int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        gph[s].push_back(e);
        gph[e].push_back(s);
    }

    int visited[MAXN] = {0, }, cnt = 0;
    for(int root = 1; root <= n; root++) {
        if(visited[root]) continue;
        
        int cycle = 0;
        cnt++;
        queue<pair<int, int> > q; q.push({root, 0}); visited[root] = 1;
        while(!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            int curr = t.first, parent = t.second;
            for(int nx : gph[curr])
                if(!visited[nx])
                    q.push({nx, curr}), visited[nx] = 1;
                else if(nx == parent) continue;
                else cycle = 1;
        }
        if(cycle) cnt--;
    }

    cout << "Case " << cs << ": ";
    if(cnt > 1) cout << "A forest of " << cnt << " trees.\n";
    else if(cnt == 1) cout << "There is one tree.\n";
    else cout << "No trees.\n";

    return 1;
}
int main() {
    while(tc());
}