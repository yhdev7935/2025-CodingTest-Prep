// BOJ - 18809 Gaaaaaaaaaarden

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 51

using namespace std;

int n, m, g, r;
int arr[MAXN][MAXN] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int max_flowers = 0;
vector<pair<int, int> > land;
int whatisinland[11] = {0, }; // 1 = g, 2 = r
int isRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
struct p {
    int x, y, age;
};
void cnt_maxflowers() {
    //for(int i = 0; i < land.size(); i++) cout << whatisinland[i] << ' '; cout << '\n';

    int flowers = 0;
    int visited[MAXN][MAXN] = {0, }, clr[MAXN][MAXN] = {0, };
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) visited[i][j] = -1;

    queue<p> q;
    for(int i = 0; i < land.size(); i++) {
        if(whatisinland[i] >= 1) {
            int x = land[i].first, y = land[i].second;
            q.push({x, y, 0});
            visited[x][y] = 0; clr[x][y] = whatisinland[i];
        }
    }

    while(!q.empty()) {
        p t = q.front(); q.pop();
        if(clr[t.x][t.y] == 5) continue; // 이미 꽃이라면 넌 패스
        
        for(int i = 0; i < 4; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if(!isRange(nx, ny)) continue;
            if(arr[nx][ny] == 0) continue; // 호수 인 경우
            if(clr[nx][ny] + clr[t.x][t.y] == 3 && visited[nx][ny] == t.age + 1) { // 플라워 만들기!
                clr[nx][ny] = 5; flowers++;
                continue;
            }
            if(clr[nx][ny] != 0) continue; // 이미 색깔이 칠해진 곳은 방문 한 것임 플라워 만드는 것 외에는 갈 일 없음.
            if(visited[nx][ny] != -1) continue; // -1 아니면 방문 한 것임.

            visited[nx][ny] = t.age + 1; q.push({nx, ny, t.age + 1});
            clr[nx][ny] = clr[t.x][t.y];
        }
    }

    max_flowers = max(max_flowers, flowers);
}
void chse(int num, int gi, int ri) {
    if(num == land.size()) {
        if(gi == g && ri == r)
            cnt_maxflowers();
        return;
    }

    if(gi < g) {
        whatisinland[num] = 1;
        chse(num + 1, gi + 1, ri);
    }
    if(ri < r) {
        whatisinland[num] = 2;
        chse(num + 1, gi, ri + 1);
    }
    whatisinland[num] = 0;
    chse(num + 1, gi, ri);
}
int main() {
    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) land.push_back({i, j});
        }

    chse(0, 0, 0);

    cout << max_flowers << '\n';
}