// BOJ - 1941 소문난 칠공주

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char ch[26]; int sel[8];
int ans = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int isRange(int x, int y) {
    return 0 <= x && x <= 4 && 0 <= y && y <= 4;
}
void verify() {
    int visited[5][5] = {0, };
    for(int i = 1; i <= 7; i++) {
        int x = sel[i] / 5, y = sel[i] % 5;
        visited[x][y] = 1;
    }
    queue<pair<int, int> > q; q.push({sel[1] / 5, sel[1] % 5}); visited[sel[1] / 5][sel[1] % 5] = 2;
    while(!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = t.first + dx[i], ny = t.second + dy[i];
            if(!isRange(nx, ny)) continue;
            if(visited[nx][ny] != 1) continue;
            visited[nx][ny] = 2; q.push({nx, ny});
        }
    }

    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) {
        if(visited[i][j] == 1) return;
    }

    ans++;
    return;
}
void dfs(int num, int j, int cnt) {
    if(num == 8) {
        if(cnt >= 4) verify();
        return;
    }
    for(int i = j; i < 25; i++) {
        sel[num] = i;
        dfs(num + 1, i + 1, cnt + (ch[i] == 'S' ? 1 : 0));
        sel[num] = 0;
    }
}
int main() {
    for(int i = 0; i < 5; i++) {
        string ss; cin >> ss;
        for(int j = 0; j < 5; j++) ch[i * 5 + j] = ss[j];
    }

    dfs(1, 0, 0);

    cout << ans << '\n';
}