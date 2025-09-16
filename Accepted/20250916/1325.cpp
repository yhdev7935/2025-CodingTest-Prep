// BOJ - 1325 효율적인 해킹

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <memory.h>
#define MAXN 10001

using namespace std;

int n, m, visited[MAXN], cnt = 0;
vector<int> gph[MAXN];
void dfs(int k) {
    visited[k] = 1; cnt++;
    for(int nx : gph[k]) {
        if(visited[nx]) continue;
        dfs(nx);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        gph[b].push_back(a);
    }

    int ans = 0; set<int> st;
    for(int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);

        if(ans == cnt) {
            st.insert(i);
        }
        else if(ans < cnt) {
            ans = cnt;
            st = set<int>(); st.insert(i);
        }
        cnt = 0;
    }

    for(int k : st) {
        cout << k << ' ';
    }
    cout << '\n';
}