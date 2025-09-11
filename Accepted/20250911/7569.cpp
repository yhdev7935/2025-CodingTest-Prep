// BOJ - 7569 토마토

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[101][101][101] = {0, };

int dh[6] = {-1, +1, 0, 0, 0};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int m, n, h; 

struct p {
    int h, x, y, d;
};

int isRange(int hm, int x, int y) {
    return 1 <= hm && hm <= h && 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
    cin >> m >> n >> h;

    queue<p> q;
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= m; k++) {
                int t; cin >> t;
                arr[i][j][k] = t;
                if(t == 1) q.push({i, j, k, 0});
            }

    int cnt = 0;
    while(!q.empty()) {
        p t = q.front(); q.pop();
        cnt = max(cnt, t.d);
        for(int i = 0; i < 6; i++) {
            int nh = t.h + dh[i], nx = t.x + dx[i], ny = t.y + dy[i];
            if(!isRange(nh, nx, ny)) continue;
            if(arr[nh][nx][ny] == 1 || arr[nh][nx][ny] == -1) continue;
            arr[nh][nx][ny] = 1;
            q.push({nh, nx, ny, t.d + 1});
        }
    }

    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= m; k++)
                if(arr[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }

    cout << cnt << '\n';
}