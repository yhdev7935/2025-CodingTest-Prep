// BOJ - 9466 텀 프로젝트

#include <iostream>
#include <vector>
#include <memory.h>
#include <set>
#define MAXN 100001

using namespace std;

int n, cnt, visited[MAXN], finished[MAXN], arr[MAXN];
void dfs(int k) {
    // 3-status: ready-ongoing-done
    visited[k] = 1;
    int v = arr[k];
    if(!visited[v]) dfs(v);
    else if(!finished[v]) {
        cnt++;
        for(int nv = v; nv != k; nv = arr[nv]) cnt++;
    }
    finished[k] = 1;
}
void tc() {
    memset(visited, 0, sizeof(visited));
    memset(finished, 0, sizeof(finished));
    memset(arr, 0, sizeof(arr));

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    cnt = 0;
    for(int i = 1; i <= n; i++) if(!visited[i]) dfs(i);
    cout << (n - cnt) << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        tc();
    }

    return 0;
}