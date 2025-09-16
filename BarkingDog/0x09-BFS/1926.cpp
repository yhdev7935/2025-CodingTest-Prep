// BOJ - 1926 그림

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 501

using namespace std;

int n, m; int arr[MAXN][MAXN] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int isRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
int bfs(int x, int y) {
    queue<pair<int, int> > q; q.push({x, y});
    arr[x][y] = 0; int cnt = 1;
    while(!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(!isRange(nx, ny)) continue;
            if(!arr[nx][ny]) continue;
            q.push({nx, ny}); arr[nx][ny] = 0; cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    int cnt = 0, maxv = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(arr[i][j]) maxv = max(maxv, bfs(i, j)), cnt++;
        }

    cout << cnt << '\n' << maxv << '\n';
}