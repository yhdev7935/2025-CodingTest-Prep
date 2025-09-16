// BOJ - 2206 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define MAXN 1001

using namespace std;

int n, m, arr[MAXN][MAXN];

struct p {
    int x, y, b, d;
};
int isRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[MAXN][MAXN][2] = {0, };
int bfs(int x, int y) {
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) for(int k = 0; k < 2; k++) visited[i][j][k] = INF;

    queue<p> q; q.push({x, y, 0, 1}); visited[x][y][0] = 1;
    int cnt = 0;
    while(!q.empty()) {
        p t = q.front(); q.pop();
        if(t.x == n && t.y == m) return t.d;
        for(int i = 0; i < 4; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i], nb = t.b, nd = t.d + 1;
            if(arr[nx][ny] == 1) nb++;
            if(nb >= 2) continue;
            if(!isRange(nx, ny)) continue;
            if(visited[nx][ny][nb] <= nd) continue;
            
            visited[nx][ny][nb] = nd;
            q.push({nx, ny, nb, nd});
        }
    }

    return -1;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string ss; cin >> ss;
        for(int j = 0; j < ss.size(); j++) arr[i][j + 1] = ss[j] - '0';
    }

    cout << bfs(1, 1) << '\n';
}